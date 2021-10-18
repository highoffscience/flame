/**
 * @author Forrest Jablonski
 */

#include "Topic.h"

#include "Hsm.h"

/**
 *
 */
ym::hsm::Topic::Topic(SStr_T const Name)
   : CNameable_NV {Name},
     SmartLink    {    }
{
}

/**
 *
 */
void ym::hsm::Topic::publish(Event * const e_Ptr)
{
   for (auto * const smartLink_Ptr : getDependents())
   {
      // this cast is safe
      static_cast<Hsm *>(smartLink_Ptr)->dispatch(e_Ptr);
   }
}

/**
 *
 */
void ym::hsm::Topic::subscribe(Hsm * const hsm_Ptr)
{
   link(hsm_Ptr);
}

/**
 *
 */
void ym::hsm::Topic::unsubscribe(Hsm * const hsm_Ptr)
{
   unlink(hsm_Ptr);
}
