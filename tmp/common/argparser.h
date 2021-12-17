/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <cstdio>
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
   class Arg
   {
   public:
      explicit Arg(str const Name);

      inline auto name(void) const { return _Name; }
      inline auto desc(void) const { return _desc; }
      inline auto abbr(void) const { return _abbr; }

      Arg & desc (str  const Desc);
      Arg & abbr (char const Abbr);
      Arg & yesno(void           );

   private:
      str const _Name; // arg name (used as the key)
      str       _desc; // description
      char      _abbr; // abbreviation of name
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
   template <typename Head_T>
   constexpr void parse_helper(uint32 const   Idx,
                               Head_T const & Head);

   template <typename    Head_T,
             typename... Rest_T>
   constexpr void parse_helper(uint32 const      Idx,
                               Head_T const &    Head,
                               Rest_T const &... Rest);

   Arg *  _args_ptr;
   uint32 _abbrs[52];
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
template <typename Head_T>
constexpr void ArgParser::parse_helper(uint32 const   Idx,
                                       Head_T const & Head)
{
   new (_args_ptr + Idx) Arg(Head);

   if (Idx > 0)
   {
      auto const PrevName = (this - 1)->getName();
   //    if (std::strcmp(PrevName, _Name) > 0)
   //    { // _Name is lexicographically smaller than previous name - uh oh
   //       throw ParseError("Arg '%s' is not supposed to preceed arg '%s'!", _Name, PrevName);
   //    }
   }
}

/**
 *
 */
template <typename    Head_T,
          typename... Rest_T>
constexpr void ArgParser::parse_helper(uint32 const      Idx,
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
}

} // hoso
