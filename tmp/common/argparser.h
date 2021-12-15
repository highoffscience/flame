/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <cstdio>
#include <exception>

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

      inline auto getName(void) const { return _Name; }
      inline auto getDesc(void) const { return _desc; }
      inline auto getAbbr(void) const { return _abbr; }

      Arg * desc (str  const Desc);
      Arg * abbr (char const Abbr);
      Arg * yesno(void           );

   private:
      str const _Name;    // arg name (used as the key)
      str       _desc;    // description
      char      _abbr;    // abbreviation of name
   };

   /**
    * 
    */
   class ParseError : public std::exception
   {
   public:
      template<typename... Args_T>
      explicit ParseError(str    const    Format,
                          Args_T const... Args);
      virtual ~ParseError(void) = default;

      virtual str what(void) const noexcept override;

   private:
      static constexpr uint32 MsgSize_bytes = 256;
      char _msg[MsgSize_bytes];
   };

   explicit ArgParser(void);
   ~ArgParser(void);

   template <typename... Args_T>
   void init(Args_T const... Args);

   Arg * add(Str_T const Name);

   void parse(int   const         Argc,
              Str_T const * const Argv_Ptr);

   Arg * get(Str_T const Key);

private:
   Arg *  _args_ptr;
   uint32 _abbrs[52];
};

/**
 * 
 */
template<typename... Args_T>
ArgParser::ParseError::ParseError(str    const    Format,
                                  Args_T const... Args)
   : _msg {'\0'}
{
   std::snprintf(_msg, MsgSize_bytes, Format, Args...);
}

/**
 * 
 */
template <typename... Args_T>
void ArgParser::init(Args_T const... Args)
{
   constexpr auto NArgs = sizeof...(Args_T);
   static_assert(NArgs > 0, "Number of args in init() must be greater than 0!");

   _args_ptr = static_cast<Arg *>(::operator new(NArgs * sizeof(Arg)));
   if (!_args_ptr)
   {
      throw ParseError("Unable to allocate memory to store argument details!");
   }

   
}

} // hoso
