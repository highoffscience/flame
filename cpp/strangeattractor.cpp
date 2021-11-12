/**
 * @author Forrest Jablonski
 */

#include "random.h"
#include "strangeattractor.h"

/**
 *
 */
auto hoso::flame::StrangeAttractor::preTransform(Point        & pnt_ref,
                                                 Pixel::dim_t & clr_ref,
                                                 Random       & rand_ref) const -> uint32
{
   constexpr IASMatrix Mats[] = {
      {.A =  0.5, .B = -0.5, .C = 0.5, .D =  0.5, .E = 0.0, .F = 0.0, .Clr = 0.0, .Prob = 0.5},
      {.A = -0.5, .B = -0.5, .C = 0.5, .D = -0.5, .E = 1.0, .F = 0.0, .Clr = 1.0, .Prob = 0.5}
   };

   auto   const R   = rand_ref.gen<decltype(IASMatrix::Prob)>();
   uint32 const Idx = (R < Mats[0].Prob) ? 0 : 1;

   pnt_ref = Point(Mats[Idx].A * pnt_ref.x + Mats[Idx].B * pnt_ref.y + Mats[Idx].E,
                   Mats[Idx].C * pnt_ref.x + Mats[Idx].D * pnt_ref.y + Mats[Idx].F);

   clr_ref = 0.5 * (clr_ref + Mats[Idx].Clr);

   return Idx;

   // constexpr IASMatrix Mat0{0.14,  0.01,  0.0 , 0.51, -0.08, -1.31, 0.0/3.0, 0.25};
   // constexpr IASMatrix Mat1{0.43,  0.52, -0.45, 0.5 ,  1.49, -0.75, 1.0/3.0, 0.25};
   // constexpr IASMatrix Mat2{0.45, -0.49,  0.47, 0.47, -1.62, -0.74, 2.0/3.0, 0.25};
   // constexpr IASMatrix Mat3{0.49,  0.0 ,  0.0 , 0.51,  0.02,  1.62, 3.0/3.0, 0.25};
//
   // auto const R = _rand.gen<float32>();
//
   // if (R < Mat0.Prob)
   // {
   //    pnt_ref.x = Mat0.A * pnt_ref.x + Mat0.B * pnt_ref.y + Mat0.E;
   //    pnt_ref.y = Mat0.C * pnt_ref.x + Mat0.D * pnt_ref.y + Mat0.F;
   //    clr_ref   = 0.5f * (clr_ref + Mat0.Clr);
   //    return 0;
   // }
   // else if (R < Mat0.Prob + Mat1.Prob)
   // {
   //    pnt_ref.x = Mat1.A * pnt_ref.x + Mat1.B * pnt_ref.y + Mat1.E;
   //    pnt_ref.y = Mat1.C * pnt_ref.x + Mat1.D * pnt_ref.y + Mat1.F;
   //    clr_ref   = 0.5f * (clr_ref + Mat1.Clr);
   //    return 1;
   // }
   // else if (R < Mat0.Prob + Mat1.Prob + Mat2.Prob)
   // {
   //    pnt_ref.x = Mat2.A * pnt_ref.x + Mat2.B * pnt_ref.y + Mat2.E;
   //    pnt_ref.y = Mat2.C * pnt_ref.x + Mat2.D * pnt_ref.y + Mat2.F;
   //    clr_ref   = 0.5f * (clr_ref + Mat2.Clr);
   //    return 2;
   // }
   // else
   // {
   //    pnt_ref.x = Mat3.A * pnt_ref.x + Mat3.B * pnt_ref.y + Mat3.E;
   //    pnt_ref.y = Mat3.C * pnt_ref.x + Mat3.D * pnt_ref.y + Mat3.F;
   //    clr_ref   = 0.5f * (clr_ref + Mat3.Clr);
   //    return 3;
   // }
}

/**
 *
 */
void hoso::flame::StrangeAttractor::postTransform(Point        & pnt_ref,
                                                  Pixel::dim_t & clr_ref,
                                                  Random       & rand_ref) const
{
}
