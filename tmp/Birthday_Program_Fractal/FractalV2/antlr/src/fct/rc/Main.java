/**
 * @author Forrest Jablonski
 */

package fct.rc;

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
      String rcFctFileName = "./scripts/rc.fct";
      String rcCppFileName = "../fct/src/Fractal.cpp";

      if (args.length == 0)
      { // default mode; nothing to do
      }
      else if (args.length == 1)
      {
         rcFctFileName = args[0];
      }
      else
      {
         System.err.println("FCTError: In RC-Main: Called with [<non-default-rcFctFileName>]");
         System.exit(1);
      }

      SourceGenerator gen = new SourceGenerator(rcCppFileName);
      gen.generateCppFile(rcFctFileName);
   }
}
