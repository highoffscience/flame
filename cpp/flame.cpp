/**                                                                   
 * @author Forrest Jablonski                                          
 *                                                                    
 * AUTO-GENERATED                                                     
 */                                                                   
                                                                      
#include <png++/png.hpp>                                              
                                                                      
#include "Standard.h"                                               
                                                                      
#include "Pixel.h"                                                  
#include "Renderer.h"                                               
                                                                      
/**                                                                   
 *                                                                    
 */                                                                   
int main(const int argc, const char* const* const argv)               
{                                                                     
   using fct::uint;                                                   
                                                                      
   constexpr uint width  = uint(1920);               
   constexpr uint height = uint(1080);               
                                                                      
   fct::Pixel** histo = new fct::Pixel*[height];                      
   for (uint i = 0U; i < height; ++i)                                 
   {                                                                  
      histo[i] = new fct::Pixel[width];                               
   }                                                                  
                                                                      
   fct::rd::render(histo);                                            
                                                                      
   png::image<png::rgba_pixel> image(width, height);                  
                                                                      
   for (uint i = 0U; i < height; ++i)                                 
   {                                                                  
      for (uint j = 0U; j < width; ++j)                               
      {                                                               
         const fct::Pixel& pxl = histo[i][j];                         
                                                                      
         const fct::ubyte r = (fct::ubyte) ((pxl.r * 255.0F) + 0.5F); 
         const fct::ubyte g = (fct::ubyte) ((pxl.g * 255.0F) + 0.5F); 
         const fct::ubyte b = (fct::ubyte) ((pxl.b * 255.0F) + 0.5F); 
         const fct::ubyte a = (fct::ubyte) ((pxl.a * 255.0F) + 0.5F); 
                                                                      
         image[i][j] = png::rgba_pixel(r, g, b, a);                   
      }                                                               
   }                                                                  
                                                                      
   image.write("./pics/fractal-1.0.png");
                                                                      
   for (uint i = 0U; i < height; ++i)                                 
   {                                                                  
      delete[] histo[i];                                              
   }                                                                  
   delete[] histo;                                                    
                                                                      
   return 0;                                                          
}                                                                     
