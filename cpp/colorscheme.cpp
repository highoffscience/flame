/**
 * @author Forrest Jablonski
 */

#include "colorscheme.h"

/**
 * Clr is in [0..1] and maps to a pixel
 */
auto hoso::flame::ColorScheme::apply(float32 const Clr) const -> Pixel
{
   //                     r     g     b     a
   constexpr Pixel Begin(0.0f, 1.0f, 0.0f, 0.0f);
   constexpr Pixel End  (1.0f, 0.0f, 0.0f, 0.0f);
   
   constexpr Pixel Alpha(End.mns(Begin));
// constexpr Pixel Beta (Begin);
   
   return Alpha.tms(Clr).pls(Begin);
}
