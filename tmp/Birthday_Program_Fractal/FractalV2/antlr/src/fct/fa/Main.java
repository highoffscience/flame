/**
 * @author Forrest Jablonski
 */

package fct.fa;

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
      String faFctFileName = "./scripts/fa.fct";
      String faCppFileName = "../fct/src/Renderer.cpp";

      if (args.length == 0)
      { // default mode; nothing to do
      }
      else if (args.length == 1)
      {
         faFctFileName = args[0];
      }
      else
      {
         System.err.println("FCTError: In FA-Main: Called with [<non-default-faFctFileName>]");
         System.exit(1);
      }

      SourceGenerator gen = new SourceGenerator(faCppFileName);
      gen.generateCppFile(faFctFileName);
   }
}
