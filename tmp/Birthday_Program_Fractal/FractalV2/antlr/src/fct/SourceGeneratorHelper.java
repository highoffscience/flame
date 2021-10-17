/**
 * @author Forrest Jablonski
 */

package fct;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CharStreams;

import java.io.IOException;

/**
 * 
 */
public class SourceGeneratorHelper
{
   private String name;
   
   /**
    * 
    */
   public SourceGeneratorHelper(String name, String cppFileName)
   {
      this.name = name;
      
      if (!cppFileName.endsWith(".cpp"))
      {
         fctExit("Source file name " + cppFileName + " must be a .cpp file!");
      }
   }
   
   /**
    * 
    */
   public void usrExit(String msg)
   {
      System.err.println("USRError: In " + name + ": " + msg);
      System.exit(1);
   }
   
   /**
    * 
    */
   public void fctExit(String msg)
   {
      System.err.println("FCTError: In " + name + ": " + msg);
      System.exit(1);
   }
   
   /**
    * 
    */
   public CharStream getStreamFromFileName(String fileName)
   {
      CharStream stream = null;
      
      try
      {
         stream = CharStreams.fromFileName(fileName);
      }
      catch (IOException exc)
      {
         fctExit("Could not open file " + fileName + "!");
      }
      
      return stream;
   }
}
