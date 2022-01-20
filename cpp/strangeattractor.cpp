/**
 * @author Forrest Jablonski
 */

#include "random.h"
#include "strangeattractor.h"

/**
 *
 */
auto hoso::flame::StrangeAttractor::preTransform(Point  & pnt_ref,
                                                 dim_t  & clr_ref,
                                                 Random & rand_ref) const -> uint32
{
   #include "strangeattractor_scripts/heighway_dragon.script"

   constexpr auto NMats = sizeof(Mats) / sizeof(IASMatrix);
   auto const R = rand_ref.gen<dim_t>();

   // this block gets sufficiently optimized
   uint32 idx  = NMats - 1ul;
   dim_t  prob = 0;
   for (uint32 i = 0; i < NMats - 1ul; ++i)
   {
      prob += Mats[i].Prob;
      if (R < prob)
      {
         idx = i;
         break;
      }
   }

   pnt_ref = Point(Mats[idx].A * pnt_ref.x + Mats[idx].B * pnt_ref.y + Mats[idx].E,
                   Mats[idx].C * pnt_ref.x + Mats[idx].D * pnt_ref.y + Mats[idx].F);

   clr_ref = 0.5_f * (clr_ref + Mats[idx].Clr);

   return idx;
}

/**
 *
 */
void hoso::flame::StrangeAttractor::postTransform(Point  & pnt_ref,
                                                  dim_t  & clr_ref,
                                                  Random & rand_ref) const
{
}
