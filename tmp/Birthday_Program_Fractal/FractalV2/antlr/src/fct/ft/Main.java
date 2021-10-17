/**
 * @author Forrest Jablonski
 */

package fct.ft;

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
      String ftFctFileName = "./scripts/ft.fct";
      String ftCppFileName = "../fct/src/Fitter.cpp";

      if (args.length == 0)
      { // default mode; nothing to do
      }
      else if (args.length == 1)
      {
         ftFctFileName = args[0];
      }
      else
      {
         System.err.println("FCTError: In FT-Main: Called with [<non-default-ftFctFileName>]");
         System.exit(1);
      }

      SourceGenerator gen = new SourceGenerator(ftCppFileName);
      gen.generateCppFile(ftFctFileName);
   }
}
