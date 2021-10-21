/**                                                      
 * @author Forrest Jablonski                             
 *                                                       
 * AUTO-GENERATED                                        
 */                                                      
                                                         
#include "Fitter.h"                                    
                                                         
static fct::Point s_scale;                               
static fct::Point s_trans;                               
                                                         
/**                                                      
 * Init scale and trans                                  
 */                                                      
void fct::fit::init(const Point& minFitPnt,              
                    const Point& maxFitPnt)              
{                                                        
}                                                        
                                                         
/**                                                      
 * Scale and translate 'pnt' and return the result       
 */                                                      
auto fct::fit::transform(const fct::Point& pnt) -> Point 
{                                                        
   constexpr uint width  = 1920;              
   constexpr uint height = 1080;              
   constexpr uint mindim = width < height ? width : height; 
   constexpr Point scale = {mindim * (0.2), mindim * (0.2)}; 
   constexpr Point trans = {width  * (0.5), height * (0.5)}; 
                                                            
      return (pnt * scale) + trans;                         
}                                                           
