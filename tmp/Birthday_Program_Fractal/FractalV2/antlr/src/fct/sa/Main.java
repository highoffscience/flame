/**
 * @author Forrest Jablonski
 */

package fct.sa;

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
      String saFctFileName = "./scripts/sa.fct";
      String saCppFileName = "../fct/src/StrangeAttractor.cpp";

      if (args.length == 0)
      { // default mode; nothing to do
      }
      else if (args.length == 1)
      {
         saFctFileName = args[0];
      }
      else
      {
         System.err.println("FCTError: In SA-Main: Called with [<non-default-saFctFileName>]");
         System.exit(1);
      }

      SourceGenerator gen = new SourceGenerator(saCppFileName);
      gen.generateCppFile(saFctFileName);
   }
}
