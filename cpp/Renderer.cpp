/**                                                                                    
 * @author Forrest Jablonski                                                           
 *                                                                                     
 * AUTO-GENERATED                                                                      
 */                                                                                    
                                                                                       
#include <cmath>                                                                       
#include <iostream>                                                                    
#include <limits>                                                                      
                                                                                       
#include "Renderer.h"                                                                
                                                                                       
#include "ColorScheme.h"                                                             
#include "Fitter.h"                                                                  
#include "Pixel.h"                                                                   
#include "Point.h"                                                                   
#include "Random.h"                                                                  
#include "StrangeAttractor.h"                                                        
#include "VariationBlend.h"                                                          
                                                                                       
/**                                                                                    
 *                                                                                     
 */                                                                                    
void fct::rd::render(Pixel* const* const histo)                                        
{                                                                                      
   constexpr uint width  = uint(1920);                                
   constexpr uint height = uint(1080);                                
                                                                                       
   Random rand;                                                                        
                                                                                       
   Point pnt = Point((2.0 * rand.genUniformReal()) - 1.0,  // x                        
                     (2.0 * rand.genUniformReal()) - 1.0); // y                        
   double clr = rand.genUniformReal();                                                 
                                                                                       
   for (uint i = 0U; i < 100U; ++i)                                                    
   {                                                                                   
      const uint index = sa::preTransform(pnt, clr);                                   
      vb::transform(index, pnt);                                                       
      sa::postTransform(pnt, clr);                                                     
   }                                                                                   
                                                                                       
   { // create fitter                                                                  
      Point minFitPnt = Point(std::numeric_limits<double>::max(),                      
                              std::numeric_limits<double>::max());                     
      Point maxFitPnt = Point(std::numeric_limits<double>::lowest(),                   
                              std::numeric_limits<double>::lowest());                  
                                                                                       
      for (uint i = 0U; i < 10000U; ++i)                                               
      {                                                                                
         const uint index = sa::preTransform(pnt, clr);                                
         vb::transform(index, pnt);                                                    
         sa::postTransform(pnt, clr);                                                  
                                                                                       
         if      (pnt.x < minFitPnt.x) { minFitPnt.x = pnt.x; }                        
         else if (pnt.x > maxFitPnt.x) { maxFitPnt.x = pnt.x; }                        
                                                                                       
         if      (pnt.y < minFitPnt.y) { minFitPnt.y = pnt.y; }                        
         else if (pnt.y > maxFitPnt.y) { maxFitPnt.y = pnt.y; }                        
      }                                                                                
                                                                                       
      fit::init(minFitPnt, maxFitPnt);                                                 
   } // end create fitter                                                              
                                                                                       
   constexpr ulong niters = ulong(1000000);                              
   constexpr ulong step = niters / 100UL;                                              
   for (ulong i = 0; i < niters; ++i)                                                  
   {                                                                                   
      if (i % step == 0)                                                               
      {                                                                                
         std::cout << "\r" << (i / step) << "% Rendered" << std::flush;           
      }                                                                                
                                                                                       
      const uint index = sa::preTransform(pnt, clr);                                   
      vb::transform(index, pnt);                                                       
      sa::postTransform(pnt, clr);                                                     
                                                                                       
      const Point fittedPnt = fit::transform(pnt);                                     
                                                                                       
      const int x =               (int)fittedPnt.x;                                    
      const int y = (int)height - (int)fittedPnt.y;                                    
                                                                                       
      if (x >= 0 && x < (int)width &&                                                  
          y >= 0 && y < (int)height)                                                   
      {                                                                                
         histo[y][x]   += cs::transform(clr);                                          
         histo[y][x].a += 1.0F;                                                        
      }                                                                                
   }                                                                                   
   std::cout << "\r100% Rendered\n" << std::flush;                                 
                                                                                       
   float alphaMax = 0.0F;                                                              
   for (uint i = 0; i < height; ++i)                                                   
   {                                                                                   
      for (uint j = 0; j < width; ++j)                                                 
      {                                                                                
         Pixel& pxl = histo[i][j];                                                     
                                                                                       
         if (pxl.a > 0.0F)                                                             
         {                                                                             
            pxl *= std::log1p(pxl.a) / pxl.a;                                          
                                                                                       
            if (pxl.a > alphaMax)                                                      
            {                                                                          
               alphaMax = pxl.a;                                                       
            }                                                                          
         }                                                                             
      }                                                                                
   }                                                                                   
                                                                                       
   constexpr float invGamma = float(1.0 / (4.0)); // 2.2F is baseline 
   for (uint i = 0; i < height; ++i)                                                   
   {                                                                                   
      for (uint j = 0; j < width; ++j)                                                 
      {                                                                                
         Pixel& pxl = histo[i][j];                                                     
                                                                                       
         if (pxl.a > 0.0F)                                                             
         {                                                                             
            pxl /= alphaMax;                                                           
            pxl ^= invGamma;                                                           
         }                                                                             
      }                                                                                
   }                                                                                   
}                                                                                      
