/**
 * @author Forrest Jablonski
 */

#pragma once

#include "Standard.h"

#include "Event.h"
#include "Nameable.h"
#include "SmartLink.h"

namespace ym::hsm
{

class Hsm;

/**
 *
 */
class Topic : public CNameable_NV,
              public SmartLink
{
protected:
   explicit Topic(SStr_T const Name);

public:
   virtual ~Topic(void) = default;

   void publish(Event * const e_Ptr); // TODO only want owning hsm to be able to access this. pass key?

   void subscribe  (Hsm * const hsm_Ptr);
   void unsubscribe(Hsm * const hsm_Ptr);
};

} // ym::hsm
