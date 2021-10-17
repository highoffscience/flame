/**                                          
 * @author Forrest Jablonski                 
 *                                           
 * AUTO-GENERATED                            
 */                                          
                                             
#include "StrangeAttractor.h"              
                                             
#include "Point.h"                         
#include "Random.h"                        
                                             
struct IASMatrix                             
{                                            
   const double a, b, c, d, e, f;            
   const double clr;                         
   const double prob;                        
};                                           
                                             
struct IFSMatrix                             
{                                            
   const double clr;                         
   const double prob;                        
};                                           
                                             
static fct::Random fctRand;                  
                                             
/**                                                 
 *                                                  
 */                                                 
uint fct::sa::preTransform(Point& pnt, double& clr) 
{                                                   
   constexpr IFSMatrix mat_0 = {0.0, 1.0/3.0};                            
   constexpr IFSMatrix mat_1 = {0.5, 1.0/3.0};                            
   constexpr IFSMatrix mat_2 = {1.0, 1.0/3.0};                            
                                                                          
   constexpr Point p_1 = Point(1.0, 0.0);                                 
   constexpr Point p_2 = Point(2.0, 0.0);                                 
   constexpr Point p_3 = Point(3.0, 0.0);                                 
   constexpr Point p_s = Point(std::sqrt(3.0), 0.0);                      
                                                                          
   constexpr Point p_1_pls_s  = p_1.cPls(p_s);                            
   constexpr Point p_2nd_term = p_1_pls_s.cDvd(p_2.cPls(p_s));            
                                                                          
   constexpr Point p_0p5  = Point( 0.5, 0.0);                             
   constexpr Point p_n1   = Point(-1.0, 0.0);                             
   constexpr Point p_si   = p_3.rev();                                    
   constexpr Point p_2num = p_0p5.cTms(p_n1.cPls(p_si));                  
   constexpr Point p_3num = p_0p5.cTms(p_n1.cMns(p_si));                  
                                                                          
   // TODO guarantee that probabilities add up to unity                   
   // TODO guarantee that probabilities decrease with subsequent matrices 
                                                                          
   const double r = fctRand.genUniformReal();                             
                                                                          
   if (r < mat_0.prob)                                                    
   {                                                                      
      pnt = (p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term);             
      clr = 0.5 * (clr + mat_0.clr);                                      
      return 0U;                                                          
   }                                                                      
   else if (r < mat_0.prob + mat_1.prob)                                  
   {                                                                      
      pnt = p_2num.cDvd((p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term));
      clr = 0.5 * (clr + mat_1.clr);                                      
      return 1U;                                                          
   }                                                                      
   else                                                                   
   {                                                                      
      pnt = p_3num.cDvd((p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term));
      clr = 0.5 * (clr + mat_2.clr);                                      
      return 2U;                                                          
   }                                                                      
}                                                   
                                                    
/**                                                  
 *                                                   
 */                                                  
void fct::sa::postTransform(Point& pnt, double& clr) 
{                                                    
}                                                    
