/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <cstdio>
#include <exception>
#include <type_traits>

/*
struct Arg
{
    Arg(int i_) : i(i_) {}

    Arg & addJ(int j_) { j = j_; return *this; }
    Arg & addK(int k_) { k = k_; return *this; }

    int i, j, k;
};

template <typename... Params_T>
void print(Params_T const... Params)
{
    static_assert(std::conjunction_v<std::is_same<Params_T, Arg>...>, "Not Arg type");

    std::cout << "NArgs " << sizeof...(Params_T) << std::endl;

    ((std::cout << Params.i << ", "
                << Params.j << ", "
                << Params.k << std::endl), ...);
}

int main()
{
    print(Arg(1).addJ(2).addK(3),
          Arg(4).addJ(5).addK(6),
          Arg(7).addJ(8).addK(9));
    return 0;
}
*/

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

      Arg & desc (str  const Desc);
      Arg & abbr (char const Abbr);
      Arg & yesno(void           );

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
   void init(Params_T const... Params);

private:
   template <typename Head_T>
   void init_helper(uint32 const   Idx,
                    Head_T const & Head);

   template <typename    Head_T,
             typename... Rest_T>
   void init_helper(uint32 const      Idx,
                    Head_T const &    Head,
                    Rest_T const &... Rest);

   Arg *  _args_ptr;
   uint32 _abbrs[52];
};

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
void ArgParser::init_helper(uint32 const   Idx,
                            Head_T const & Head)
{
   new (_args_ptr + Idx) Arg(Head);
}

/**
 *
 */
template <typename    Head_T,
          typename... Rest_T>
void ArgParser::init_helper(uint32 const      Idx,
                            Head_T const &    Head,
                            Rest_T const &... Rest)
{
   init_helper(Idx,     Head   );
   init_helper(Idx + 1, Rest...);
}

/**
 *
 */
template <typename... Params_T>
void ArgParser::init(Params_T const... Params)
{
   constexpr auto NArgs = sizeof...(Params_T);
   static_assert(NArgs > 0, "Number of params in init() must be greater than 0!");

   static_assert(std::conjunction_v<std::is_same<Params_T, Arg>...>, "Param not Arg type!");

   _args_ptr = static_cast<Arg *>(::operator new(NArgs * sizeof(Arg)));
   if (!_args_ptr)
   {
      throw ParseError("Unable to allocate memory to store argument details!");
   }

   init_helper(0, Params...);
}

} // hoso
