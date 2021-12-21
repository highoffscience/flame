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
   //public:
      //explicit inline Arg(str const Name)
      //   : _Name   {Name   },
      //     _desc   {nullptr},
      //     _abbr   {'\0'   },
      //     _yesno  {false  }
      //{}

      //inline auto name (void) const { return _Name;  }
      //inline auto desc (void) const { return _desc;  }
      //inline auto abbr (void) const { return _abbr;  }
      //inline auto yesno(void) const { return _yesno; }

      //inline Arg & desc (str  const Desc ) { _desc  = Desc;  return *this; }
      //inline Arg & abbr (char const Abbr ) { _abbr  = Abbr;  return *this; }
      //inline Arg & yesno(bool const YesNo) { _yesno = YesNo; return *this; }

   //private:
      enum class Switch_T : uint8 { No = 0, Yes, Composite   };
      enum class Req_T    : uint8 { No = 0, Yes, Conditional };

      str      const Name   = nullptr;      // arg name (used as the key)
      str      const Desc   = nullptr;      // description
      uint32   const
      char     const Abbr   = '\0';         // abbreviation of name
      Switch_T const Switch = Switch_T::No; // is argument binary
      Req_T    const Req    = Req_T::No;    // is argument required
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

   inline auto        operator[](str const ArgName) const { return get(ArgName); }
          Arg const & get       (str const ArgName) const;

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
