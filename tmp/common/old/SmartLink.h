/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include <vector>

namespace ym
{

/**
 *
 */
class SmartLink
{
public:
   explicit SmartLink(void);
   explicit SmartLink(uint32 const NExpectedDependents);

   virtual ~SmartLink(void);

   auto const & getDependents(void) const { return _dependents; }
   auto       & getDependents(void)       { return _dependents; }

protected:
   void link  (SmartLink * const dependent_Ptr);
   void unlink(SmartLink * const dependent_Ptr);

private:
   std::vector<SmartLink *> _dependents;
};

} // ym
