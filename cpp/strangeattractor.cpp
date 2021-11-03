/**
 * @author Forrest Jablonski
 */

#include "strangeattractor.h"

/**
 *
 */
hoso::flame::StrangeAttractor::StrangeAttractor(void)
   : _rand {}
{
}

/**
 *
 */
auto hoso::flame::StrangeAttractor::preTransform(Point        & pnt_ref,
                                                 Pixel::dim_t & clr_ref) -> uint32
{
   constexpr IASMatrix Mat0{ 0.5f, -0.5f, 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 0.5f};
   constexpr IASMatrix Mat1{-0.5f, -0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 0.5f};

   if (_rand.gen<float32>() < Mat0.Prob)
   {
      pnt_ref.x = Mat0.A * pnt_ref.x + Mat0.B * pnt_ref.y + Mat0.E;
      pnt_ref.y = Mat0.C * pnt_ref.x + Mat0.D * pnt_ref.y + Mat0.F;
      clr_ref   = 0.5f * (clr_ref + Mat0.Clr);
      return 0;
   }
   else
   {
      pnt_ref.x = Mat1.A * pnt_ref.x + Mat1.B * pnt_ref.y + Mat1.E;
      pnt_ref.y = Mat1.C * pnt_ref.x + Mat1.D * pnt_ref.y + Mat1.F;
      clr_ref   = 0.5f * (clr_ref + Mat1.Clr);
      return 1;
   }
}

/**
 *
 */
void hoso::flame::StrangeAttractor::postTransform(Point        & pnt_ref,
                                                  Pixel::dim_t & clr_ref)
{
}
