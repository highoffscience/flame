#include <iostream>

#include "colorscheme.h"
#include "pixel.h"

int main(void)
{
   using namespace hoso;
   using namespace hoso::flame;
   
   ColorScheme cs;
   Pixel p;
   
   for (uint32 i = 0; i < 1; ++i)
   {
      p = cs.apply(0.4);
   }

   std::cout << "(" << p.r << ", " << p.g << ", " << p.b << ", " << p.a << ")" << std::endl;
   std::cout << ctr_i << std::endl;
   
   return 0;
}
