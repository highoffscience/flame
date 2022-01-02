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
inline auto hoso::ArgParser::findKeysEnd(str key,
                                         str searchable) const -> str
{
   while (*key && (*key == *searchable))
   {
      ++key, ++searchable;
   }

   return key;
}

/**
 *
 */
auto hoso::ArgParser::operator[](str const Key) const -> Arg const *
{
   Arg const * Target_ptr = nullptr;

   for (uint32 i = 0; i < _nArgs; ++i)
   {
      auto const KeyEnd = findKeysEnd(Key, _args_ptr[i].name());

      if (!*KeyEnd) // Key must be consumed
      { // Key matched
         if (Target_ptr)
         { // ambiguity detected
            throw ParseError("Key '%s' matches multiple targets", Key);
         }

         Target_ptr = _args_ptr + i;
      }
      else if (Target_ptr)
      { // Key matches previous entry and no ambiguity detected
         break;
      }
   }

   if (!Target_ptr)
   {
      throw ParseError("No match for key '%s' found", Key);
   }

   return Target_ptr;
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
   if (!Head.name() || !Head.name()[0])
   {
      throw ParseError("Arg name must be non-empty");
   }

   if (Idx > 0)
   {
      auto const PrevName = _args_ptr[Idx - 1].name();
      if (std::strcmp(PrevName, Head.name()) >= 0) // = detects duplicates
      { // name is lexicographically smaller than previous name - uh oh
         throw ParseError("Arg '%s' is not supposed to preceed or equate to '%s'", PrevName, Head.name());
      }
   }

   if (!Head.desc() || !Head.desc()[0])
   {
      throw ParseError("Arg '%s' must have a description", Head.name());
   }

   { // check abbr
      uint32 const Abbr_idx =
         (Head.abbr() >= 'A' && Head.abbr() <= 'Z') ? (Head.abbr() - 'A'     ) :
         (Head.abbr() >= 'a' && Head.abbr() <= 'z') ? (Head.abbr() - 'a' + 26) : (-1u);

      if (Abbr_idx >= 52)
      {
         throw ParseError("Illegal abbr '%c' found for arg '%s'!", Head.abbr(), Head.name());
      }

      if (_abbrs[Abbr_idx])
      {
         throw ParseError("Arg '%s' wants abbr '%c' but it's already used by arg '%s'",
            Head.name(), Head.abbr(), _abbrs[Abbr_idx]->name());
      }

      _abbrs[Abbr_idx] = _args_ptr + Idx; // this memory addr is invalid until function completes
   }

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
         Arg("clean").abbr('c').desc("Cleans project"),
         Arg("verbose").abbr('v').desc("Increases logging"),
         Arg("verbose").desc("Prints version info")
      );
   }
   catch (hoso::ArgParser::ParseError const & E)
   {
      std::printf("ArgParser failure! %s!\n", E.what());
      return 1;
   }
   std::printf("%s\n", argParser["v"]->desc());
   return 0;
}
#endif // drive_argparser
