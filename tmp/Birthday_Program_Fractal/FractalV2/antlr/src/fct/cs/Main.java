/**
 * @author Forrest Jablonski
 */

package fct.cs;

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
      String csFctFileName = "./scripts/cs.fct";
      String csCppFileName = "../fct/src/ColorScheme.cpp";

      if (args.length == 0)
      { // default mode; nothing to do
      }
      else if (args.length == 1)
      {
         csFctFileName = args[0];
      }
      else
      {
         System.err.println("FCTError: In CS-Main: Called with [<non-default-csFctFileName>]");
         System.exit(1);
      }

      SourceGenerator gen = new SourceGenerator(csCppFileName);
      gen.generateCppFile(csFctFileName);
   }
}
