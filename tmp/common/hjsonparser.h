/**
 * @author Forrest Jablonski
 */

#include "standard.h"

#include <string>
#include <variant>
#include <vector>

/**
 * TODO inherit from Nameable
 */
class hjsonparser
{
public:
   /**
    * 
    */
   struct Value
   {
      std::variant<std::string, std::vector<Value *>> variant;
   };

   /**
    * 
    */
   struct Item
   {
      std::string name;
      Value       value;
   };

   /**
    * 
    */
   struct Object
   {
      std::vector<Item> items;
   };

   explicit hjsonparser(Str_T const Filename);

   inline auto getFilename(void) const { return _Filename; }

   void parse(void);

private:
   Str_T const _Filename;
};
