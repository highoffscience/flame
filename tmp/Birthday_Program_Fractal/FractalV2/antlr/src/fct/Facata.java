/**
 * @author Forrest Jablonski
 */

package fct;

import fct.vb.VariationBlendSourceGenerator;
import fct.cs.ColorSchemeSourceGenerator;
import fct.ft.FitterSourceGenerator;

/**
 *
 */
public class Facata
{
   /**
    *
    */
   public static void main(String[] args)
   {
      if (args.length != 6)
      {
         System.err.print("Must call with <variation-blend-fct-file-name>\n" +
                          "               <variation-blend-cpp-file-name>\n" +
                          "               <color-scheme-fct-file-name>\n"    +
                          "               <color-scheme-cpp-file-name>\n"    +
                          "               <fitter-fct-file-name>\n"          +
                          "               <fitter-cpp-file-name>\n"          );
         System.exit(1);
      }
      
      String vbFctFileName = args[0];
      String vbCppFileName = args[1];
      String csFctFileName = args[2];
      String csCppFileName = args[3];
      String ftFctFileName = args[4];
      String ftCppFileName = args[5];
      
      (new VariationBlendSourceGenerator(vbCppFileName            )).generateCppFile(vbFctFileName);
      (new ColorSchemeSourceGenerator   (csCppFileName            )).generateCppFile(csFctFileName);
      (new FitterSourceGenerator        (ftCppFileName, 1920, 1080)).generateCppFile(ftFctFileName);
   }
}
