/**
 * @author Forrest Jablonski
 */

package fct;

import java.io.PrintWriter;
import java.io.FileNotFoundException;

/**
 * 
 */
public class FacataCodeGenerator
{
   private static final boolean debug = false;
   
   private PrintWriter writer;
   
   private String fileName;
   
   private int     indentLevel;
   private boolean isStartOfLine;

   /**
    * 
    */
   public FacataCodeGenerator(String fileName)
   {
      this.writer = null;
      
      this.fileName = fileName;
      
      this.indentLevel   = 0;
      this.isStartOfLine = true;
   }
   
   /**
    * 
    */
   public void open()
   {
      if (writer != null)
      {
         System.err.println("FCTError: Must close current file before opening again!");
         System.exit(1);
      }
      
      try
      {
         writer = new PrintWriter(fileName);
      }
      catch (FileNotFoundException exc)
      {
         System.err.println("FCTError: File " + fileName + " could not be opened! " + exc);
         System.exit(1);
      }
   }
   
   /**
    * 
    */
   public void close()
   {
      writer.close();
      writer = null;
   }
   
   /**
    * 
    */
   public void write(String s)
   {
      final int nNewlines = count(s, '\n');
      
      if (nNewlines > 1)
      {
         System.err.println("FCTError: Line to print contains more than one newline!");
         System.exit(1);
      }
      
      if ((nNewlines == 1                  ) &&
          (s.charAt(s.length() - 1) != '\n'))
      {
         System.err.println("FCTError: Newline must be at the end of the line!");
         System.exit(1);
      }
      
      if (isStartOfLine)
      {
         writeIndent();
         isStartOfLine = false;
      }
      
      if (debug)
      {
         System.out.print(s);
      }
      else
      {
         writer.print(s);
      }
      
      if (nNewlines == 1)
      {
         isStartOfLine = true;
      }
   }
   
   /**
    * 
    */
   public void indent()
   {
      indentLevel += 1;
   }
   
   /**
    * 
    */
   public void undent()
   {
      indentLevel -= 1;
      
      if (indentLevel < 0)
      {
         System.err.println("FCTError: Indent level cannot be less than 0!");
         System.exit(1);
      }
   }
   
   /**
    * 
    */
   private void writeIndent()
   {
      for (int i = 0; i < indentLevel; ++i)
      {
         if (debug)
         {
            System.out.print("   ");
         }
         else
         {
            writer.print("   ");
         }
      }
   }
   
   /**
    * 
    */
   private int count(String strToSearch, final char charToCount)
   {
      int nCounts = 0;
      
      for (int i = 0; i < strToSearch.length(); ++i)
      {
         final char c = strToSearch.charAt(i);
         
         if (c == charToCount)
         {
            nCounts += 1;
         }
      }
      
      return nCounts;
   }
}
