/**
 * @author Forrest Jablonski
 */

#include "argparser.h"

#include <cstdlib>

/**
 *
 */
hoso::ArgParser::ArgParser(void)
   : _args_ptr {nullptr},
     _abbrs    {nullptr},
     _nArgs    {0      }
{
}

/**
 *
 */
hoso::ArgParser::~ArgParser(void)
{
   if (_args_ptr)
   {
      ::operator delete(_args_ptr);
   }
}

/**
 * TODO this should return an exception with all the errors
 */
// void ArgParser::parse(int   const         Argc,
//                       Str_T const * const Argv_Ptr)
// {
//    auto isAlpha = [](char const C) -> bool {
//       return (C >= 'A' && C <= 'Z') ||
//              (C >= 'a' && C <= 'z');
//    }
//
//    for (int i = 1; i < Argc; ++i)
//    {
//       auto name = Argv_Ptr[i];
//
//       if (name[0] == '-') // accessing 0th element is safe because it's null terminated
//       { // potential arg
//          if (name[1] == '-')
//          { // potential longhand arg
//             if (isAlpha(name[2]))
//             { // found longhand arg
//                name += 2;
//                if (auto * const arg_Ptr = get(name); arg_Ptr)
//                { // found match
//                   // TODO
//                   if (arg_Ptr->isBool())
//                   {
//                      arg_Ptr->setVal(...)
//                   }
//                   if (++i < Argc)
//                   { // found value
//                      arg_Ptr->_val = Argv_Ptr[i];
//                   }
//                   else
//                   { // no value - EOF
//                      std::printf("No value for arg %s!\n", arg);
//                      everythingGood = false;
//                   }
//                }
//                else
//                { // found unregistered arg
//                   std::printf("Found unregistered arg %s!\n", arg);
//                   everythingGood = false;
//                }
//                continue;
//             }
//          }
//          else if (isAlpha(arg[1]))
//          { // found shorthand arg(s)
//             arg += 1;
//             // TODO
//             continue;
//          }
//       }
//
//       std::printf("Found rogue value %s!\n", arg);
//       everythingGood = false;
//    }
//
//    return everythingGood;
// }
//
/**
 *
 */
auto hoso::ArgParser::get(str const ArgName) const -> Arg const &
{
   // Arg arg(ArgName);
   // return *static_cast<Arg *>(std::bsearch(&arg, _args_ptr, _nArgs, sizeof(Arg),
   //                                         [](void const * Lhs_ptr, void const * Rhs_ptr) -> int {
   //    return std::strcmp(static_cast<Arg const *>(Lhs_ptr)->name(),
   //                       static_cast<Arg const *>(Rhs_ptr)->name());
   // }));

   //uint32 lower    = 0;
   //uint32 upper    = _nArgs;
   //uint32 char_idx = 0;
   //char   prevChar = '\0';
   //while (lower < upper)
   //{
   //   uint32 const Idx = (lower + upper) / 2;
   //   __p = (void *) (((const char *) __base) + (__idx * __size));
   //   __comparison = (*__compar) (__key, __p);
//
   //   char const CurrChar = _args_ptr[Idx].name()[char_idx];
//
   //   if (CurrChar )
//
   //   if (_args_ptr[Idx].name()[char_idx])
//
   //   if (__comparison < 0)
   //      __u = __idx;
   //   else if (__comparison > 0)
   //      __l = __idx + 1;
   //   else
   //      return (void *) __p;
   //}
//
   // return NULL;
}

/**
 *
 */
void hoso::ArgParser::parse_args(int const         Argc,
                                 str const * const Argv_Ptr)
{

}

/**
 *
 */
void hoso::ArgParser::parse_helper(uint32 const   Idx,
                                   Arg    const & Head)
{
   // if (!Head.name() || !Head.name()[0])
   // {
   //    throw ParseError("Arg name must be non-empty");
   // }

   // if (Idx > 0)
   // {
   //    auto const PrevName = _args_ptr[Idx - 1].name();
   //    if (std::strcmp(PrevName, Head.name()) > 0)
   //    { // name is lexicographically smaller than previous name - uh oh
   //       throw ParseError("Arg '%s' is not supposed to preceed arg '%s'", PrevName, Head.name());
   //    }
   // }

   // if (!Head.desc() || !Head.desc()[0])
   // {
   //    throw ParseError("Arg '%s' desc must have a description", Head.name());
   // }
//
   // { // check abbr
   //    uint32 const Abbr_idx =
   //       (Head.abbr() >= 'A' && Head.abbr() <= 'Z') ? (Head.abbr() - 'A'     ) :
   //       (Head.abbr() >= 'a' && Head.abbr() <= 'z') ? (Head.abbr() - 'a' + 26) : (-1u);
//
   //    if (Abbr_idx >= 52)
   //    {
   //       throw ParseError("Illegal abbr '%c' found for arg '%s'!", Head.abbr(), Head.name());
   //    }
//
   //    if (_abbrs[Abbr_idx])
   //    {
   //       throw ParseError("Arg '%s' wants abbr '%c' but it's already used by arg '%s'!",
   //          Head.name(), Head.abbr(), _abbrs[Abbr_idx]->name());
   //    }
//
   //    _abbrs[Abbr_idx] = (_args_ptr + Idx); // this memory addr is invalid until this function completes
   // }

   new (_args_ptr + Idx) Arg(Head);
}

/**
 *
 */
auto hoso::ArgParser::ParseError::what(void) const noexcept -> str
{
   return _msg;
}

/*
 *
 */
#ifdef drive_argparser
int main(int       const         Argc,
         hoso::str const * const Argv_Ptr)
{
   hoso::ArgParser argParser;
   try
   {
      using Arg = hoso::ArgParser::Arg;
      argParser.parse(Argc, Argv_Ptr,
         //Arg("clean").abbr('c').desc("Cleans project"),
         //Arg("verbose").abbr('v').desc("Increases logging"),
         Arg{.Name="clean"}
      );
   }
   catch (hoso::ArgParser::ParseError const & E)
   {
      std::printf("ArgParser failure! %s!\n", E.what());
      return 1;
   }
   std::printf("%s\n", argParser["verbose"].Desc);
   return 0;
}
#endif // drive_argparser
