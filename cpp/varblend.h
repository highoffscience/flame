/**
 * @author Forrest Jablonski
 */

#pragma once

#include "hoso.h"
#include "point.h"

namespace hoso::flame
{

/**
 * 
 */
class VarBlend // Variation Blend
{
public:
   explicit VarBlend(void);

   Point apply(uint32 const XForm_idx) const;

private:
   /**
    * 
    */
   struct Var
   {
      typedef Point(*fun_t)(Point const & P);

      fun_t  const Fun; // in the sun
      uint32 const Weight;
   };

   Var const * const _Vars_Ptr;
};

} // hoso::flame
