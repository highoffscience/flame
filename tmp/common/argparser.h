/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <cstdio>
#include <cstring>
#include <exception>
#include <type_traits>

namespace hoso
{

/**
 * Arg names must be string literals
 */
class ArgParser
{
public:
   /**
    *
    */
   struct Arg
   {
   public:
      enum class State_T : uint8 { No = 0, Yes, Composite   };
      enum class Req_T   : uint8 { No = 0, Yes, Conditional }; // require

      explicit inline Arg(str const Name)
         : _Name  {Name       },
           _desc  {nullptr    },
           _val   {nullptr    },
           _abbr  {'\0'       },
           _state {State_T::No},
           _req   {Req_T::No  }
      {}

      inline auto name (void) const { return _Name;  }
      inline auto desc (void) const { return _desc;  }
      inline auto val  (void) const { return _val;   }
      inline auto abbr (void) const { return _abbr;  }
      inline auto state(void) const { return _state; }
      inline auto req  (void) const { return _req;   }

      inline auto & desc  (str     const Desc  ) { _desc  = Desc;   return *this; }
      inline auto & defVal(str     const DefVal) { _val   = DefVal; return *this; }
      inline auto & abbr  (char    const Abbr  ) { _abbr  = Abbr;   return *this; }
      inline auto & state (State_T const State ) { _state = State;  return *this; }
      inline auto & req   (Req_T   const Req   ) { _req   = Req;    return *this; }

   private:
      str const _Name;  // arg name (used as the key)
      str       _desc;  // description
      str       _val;   // if null, value of cmdline if specified, else default val
      char      _abbr;  // abbreviation of name
      State_T   _state; // is argument binary
      Req_T     _req;   // is argument required
   };

   /**
    *
    */
   class ParseError : public std::exception
   {
   public:
      explicit ParseError(str      const    Format);
      template<typename... Params_T>
      explicit ParseError(str      const    Format,
                          Params_T const... Params);
      virtual ~ParseError(void) = default;

      virtual str what(void) const noexcept override;

   private:
      static constexpr uint32 MsgSize_bytes = 256;
      char _msg[MsgSize_bytes];
   };

   explicit ArgParser(void);
   ~ArgParser(void);

   template <typename... Params_T>
   void parse(int      const         Argc,
              str      const * const Argv_Ptr,
              Params_T const &...    Params);

   // Key is the name of the desired Arg
   Arg const * operator[](str const Key) const;

private:
   void parse_args(int const         Argc,
                   str const * const Argv_Ptr);

   void parse_helper(uint32 const   Idx,
                     Arg    const & Head);

   template <typename    Head_T,
             typename... Rest_T>
   inline void parse_helper(uint32 const      Idx,
                            Head_T const &    Head,
                            Rest_T const &... Rest);

   inline str findKeysEnd(str key,
                          str searchable) const;

   Arg *  _args_ptr;
   Arg *  _abbrs[52];
   uint32 _nArgs;
};

/**
 * Get rid of "format ain't a string literal" error
 */
ArgParser::ParseError::ParseError(str const Format)
   : ParseError("%s", Format)
{
}

/**
 *
 */
template<typename... Params_T>
ArgParser::ParseError::ParseError(str      const    Format,
                                  Params_T const... Params)
   : _msg {'\0'}
{
   std::snprintf(_msg, MsgSize_bytes, Format, Params...);
}

/**
 *
 */
template <typename    Head_T,
          typename... Rest_T>
inline void ArgParser::parse_helper(uint32 const      Idx,
                                    Head_T const &    Head,
                                    Rest_T const &... Rest)
{
   parse_helper(Idx,     Head   );
   parse_helper(Idx + 1, Rest...);
}

/**
 *
 */
template <typename... Params_T>
void ArgParser::parse(int      const         Argc,
                      str      const * const Argv_Ptr,
                      Params_T const &...    Params)
{
   constexpr auto NArgs = sizeof...(Params_T);

   static_assert(NArgs > 0, "Number of params in parse() must be greater than 0!");

   static_assert(std::conjunction_v<std::is_same<Params_T, Arg>...>, "Param not Arg type!");

   _args_ptr = static_cast<Arg *>(::operator new(NArgs * sizeof(Arg)));
   if (!_args_ptr)
   {
      throw ParseError("Unable to allocate memory to store argument details");
   }

   _nArgs = NArgs;

   parse_helper(0, Params...);

   parse_args(Argc, Argv_Ptr);
}

} // hoso
