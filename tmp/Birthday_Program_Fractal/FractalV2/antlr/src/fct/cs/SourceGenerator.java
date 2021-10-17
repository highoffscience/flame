/**
 * @author Forrest Jablonski
 */

package fct.cs;

import fct.FacataCodeGenerator;
import fct.SourceGeneratorHelper;

import java.util.HashMap;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.*;

/**
 * 
 */
public class SourceGenerator extends FacataBaseVisitor<Integer>
{
   private static final int TFloat     = 0;
   private static final int TPixel     = 1;
   private static final int TReference = 2;
   private static final int TInvalid   = 3;
   
   private SourceGeneratorHelper    sgh;
   private FacataCodeGenerator      gen;
   private HashMap<String, Integer> env;
   private int                      pass;
   
   /**
    * 
    */
   public SourceGenerator(String cppFileName)
   {
      this.sgh  = new SourceGeneratorHelper("ColorScheme", cppFileName);
      this.gen  = new FacataCodeGenerator(cppFileName);
      this.env  = new HashMap<String, Integer>();
      this.pass = 0;
   }
   
   /**
    * 
    */
   public void generateCppFile(String fctFileName)
   {
      CharStream        stream = sgh.getStreamFromFileName(fctFileName);
      FacataLexer       lexer  = new FacataLexer          (stream     );
      CommonTokenStream tokens = new CommonTokenStream    (lexer      );
      FacataParser      parser = new FacataParser         (tokens     );
      
      final int nErrors = parser.getNumberOfSyntaxErrors();

      if (nErrors == 0)
      {
         ParseTree tree = parser.unit();
         visit(tree); // generates cpp file
      }
      else
      {
         sgh.usrExit(Integer.toString(nErrors) + " syntax errors found in file " + fctFileName + "!");
      }
   }
   
   /**
    * 
    */
   @Override
   public Integer visitUnit_(FacataParser.Unit_Context ctx)
   {  
      pass = 0;
      
      visit(ctx.statementList());
      
      pass = 1;
      
      gen.open();

      gen.write("/**\n"                                                );
      gen.write(" * @author Forrest Jablonski\n"                       );
      gen.write(" *\n"                                                 );
      gen.write(" * AUTO-GENERATED\n"                                  );
      gen.write(" */\n"                                                );
      gen.write("\n"                                                   );
      gen.write("#include <cmath>\n"                                   );
      gen.write("\n"                                                   );
      gen.write("#include \"ColorScheme.h\"\n"                         );
      gen.write("\n"                                                   );
      gen.write("/**\n"                                                );
      gen.write(" * 'color' is in [0..1] and maps to a pixel\n"        );
      gen.write(" */\n"                                                );
      gen.write("auto fct::cs::transform(const float color) -> Pixel\n");
      gen.write("{\n"                                                  );
      gen.indent();
      visit(ctx.statementList());
      gen.undent();
      gen.write("}\n"                                                  );
    
      gen.close();
      
      return TInvalid;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitListStatement_(FacataParser.ListStatement_Context ctx)
   {
      visit(ctx.statementList());
      visit(ctx.statement());
      return TInvalid;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitSingleStatement_(FacataParser.SingleStatement_Context ctx)
   {
      visit(ctx.statement());
      return TInvalid;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitAssignmentStatement_(FacataParser.AssignmentStatement_Context ctx)
   {
      Integer type = TInvalid;
      String  name = ctx.Identifier().getText();
      
      if (pass == 0)
      {
         type = visit(ctx.additiveExpression());
         env.put(name, type);
      }
      else // pass == 1
      {
         type = env.get(name);
         
         if (type == TPixel)
         {
            gen.write("const Pixel " + name + " = ");
         }
         else if (type == TFloat)
         {
            gen.write("const float " + name + " = ");
         }
         else
         {
            sgh.fctExit("No type " + type + " found!");
         }
         
         visit(ctx.additiveExpression());
         gen.write(";\n");
      }
      
      return type;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitReturnStatement_(FacataParser.ReturnStatement_Context ctx)
   {
      Integer type = TInvalid;
      
      if (pass == 0)
      {
         type = visit(ctx.additiveExpression());
      }
      else // pass == 1
      {
         gen.write("\n");
         gen.write("return ");
         type = visit(ctx.additiveExpression());
         gen.write(";\n");
      }
      
      return type;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitEmptyStatement_(FacataParser.EmptyStatement_Context ctx)
   {
      return TInvalid;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitAdditionExpression_(FacataParser.AdditionExpression_Context ctx)
   {
      Integer type = TInvalid;
      Integer lhs  = TInvalid;
      Integer rhs  = TInvalid;
      
      lhs = visit(ctx.additiveExpression());
      
      if (pass == 1)
      {
         gen.write(" " + ctx.OP.getText() + " ");
      }
      
      rhs = visit(ctx.multiplicativeExpression());
      
      if ((lhs == TPixel) || (rhs == TPixel))
      {
         type = TPixel;
      }
      else
      {
         type = TFloat;
      }
      
      return type;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitAdditiveExpression_(FacataParser.AdditiveExpression_Context ctx)
   {
      return visit(ctx.multiplicativeExpression());
   }
   
   /**
    * 
    */
   @Override
   public Integer visitMultiplicationExpression_(FacataParser.MultiplicationExpression_Context ctx)
   {
      Integer type = TInvalid;
      Integer lhs  = TInvalid;
      Integer rhs  = TInvalid;
      
      lhs = visit(ctx.multiplicativeExpression());
      
      if (pass == 1)
      {
         gen.write(" " + ctx.OP.getText() + " ");
      }
      
      rhs = visit(ctx.primaryExpression());
      
      if ((lhs == TPixel) || (rhs == TPixel))
      {
         type = TPixel;
      }
      else
      {
         type = TFloat;
      }
      
      return type;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitMultiplicativeExpression_(FacataParser.MultiplicativeExpression_Context ctx)
   {
      return visit(ctx.primaryExpression());
   }
   
   /**
    * 
    */
   @Override
   public Integer visitInteger_(FacataParser.Integer_Context ctx)
   {
      if (pass == 1)
      {
         gen.write(ctx.Integer().getText());
      }
      
      return TFloat;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitDecimal_(FacataParser.Decimal_Context ctx)
   {
      if (pass == 1)
      {
         gen.write(ctx.Decimal().getText());
      }
      
      return TFloat;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitReference_(FacataParser.Reference_Context ctx)
   {
      String name = ctx.Identifier().getText();
      
      if (pass == 0)
      {
         if (!env.containsKey(name))
         {
            env.put(name, TReference);
         }
         else
         { // we have seen this key before, we should know its type!
            if (env.get(name) == TReference)
            {
               sgh.usrExit("Undefined reference " + name + "!");
            }
         }
      }
      else // pass == 1
      {
         gen.write(name);
      }
      
      return env.get(name);
   }
   
   /**
    * 
    */
   @Override
   public Integer visitColor_(FacataParser.Color_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("color");
      }
      
      return TFloat;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitFunctionCall_(FacataParser.FunctionCall_Context ctx)
   {
      Integer t = visit(ctx.functionCall());
      
      if (pass == 0)
      {
         if (t != TFloat)
         {
            sgh.usrExit("Function call only takes floats as arguments!");
         }
      }
      
      return t;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitPrimaryPixelExpression_(FacataParser.PrimaryPixelExpression_Context ctx)
   {
      return visit(ctx.pixelExpression());
   }
   
   /**
    * 
    */
   @Override
   public Integer visitPrimaryParenthesisedExpression_(FacataParser.PrimaryParenthesisedExpression_Context ctx)
   {
      return visit(ctx.parenthesisedExpression());
   }
   
   /**
    * 
    */
   @Override
   public Integer visitSin_(FacataParser.Sin_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("std::sin(");
         visit(ctx.ARG);
         gen.write(")");
      }
      
      return TFloat;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitCos_(FacataParser.Cos_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("std::cos(");
         visit(ctx.ARG);
         gen.write(")");
      }
      
      return TFloat;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitTan_(FacataParser.Tan_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("std::tan(");
         visit(ctx.ARG);
         gen.write(")");
      }
      
      return TFloat;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitPixelExpression_(FacataParser.PixelExpression_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("{");
         visit(ctx.RED);
         gen.write(", ");
         visit(ctx.GREEN);
         gen.write(", ");
         visit(ctx.BLUE);
         gen.write(", ");
         gen.write("0.0");
         gen.write("}");
      }
      
      return TPixel;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitParenthesisedExpression_(FacataParser.ParenthesisedExpression_Context ctx)
   {
      Integer t = TInvalid;
      
      if (pass == 0)
      {
         t = visit(ctx.additiveExpression());
      }
      else // pass == 1
      {
         gen.write("(");
         t = visit(ctx.additiveExpression());
         gen.write(")");
      }
      
      return t;
   }
}
