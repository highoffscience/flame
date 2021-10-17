/**
 * @author Forrest Jablonski
 */

package fct.vb;

/**
 *
 */
public class Main
{
   /**
    *
    */
   public static void main(String[] args)
   {
      String vbFctFileName = "./scripts/vb.fct";
      String vbCppFileName = "../fct/src/VariationBlend.cpp";

      if (args.length == 0)
      { // default mode; nothing to do
      }
      else if (args.length == 1)
      {
         vbFctFileName = args[0];
      }
      else
      {
         System.err.println("FCTError: In VB-Main: Called with [<non-default-vbFctFileName>]");
         System.exit(1);
      }

      SourceGenerator gen = new SourceGenerator(vbCppFileName);
      gen.generateCppFile(vbFctFileName);
   }
}
