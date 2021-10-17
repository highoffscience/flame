/**
 * @author Forrest Jablonski
 */

package fct.vb;

import fct.FacataCodeGenerator;
import fct.SourceGeneratorHelper;

import java.util.HashMap;
import java.util.ArrayList;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.*;

/**
 * 
 */
public class SourceGenerator extends FacataBaseVisitor<Integer>
{
   private static final int TFloat     = 0;
   private static final int TPoint     = 1;
   private static final int TReference = 2;
   private static final int TInvalid   = 3;
   
   private SourceGeneratorHelper        sgh;
   private FacataCodeGenerator          gen;
   private HashMap<String, Integer>     env;
   private int                          pass;
   private ArrayList<ArrayList<String>> weights;
   private int                          currVar;

   /**
    * 
    */
   public SourceGenerator(String cppFileName)
   {
      this.sgh     = new SourceGeneratorHelper("VariationBlend", cppFileName);
      this.gen     = new FacataCodeGenerator(cppFileName);
      this.env     = new HashMap<String, Integer>();
      this.pass    = 0;
      this.weights = new ArrayList<ArrayList<String>>();
      this.currVar = 0;
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
   private void writeWeights()
   {
      Integer nTransforms = weights.get(0).size(); // we are guaranteed the existence of a 0th element
      Integer nVars       = weights.size();        // same here
      
      // star wars 36, remastered and in full vr. they say it's a classic
      
      gen.write("constexpr double weights[");
      gen.write(nTransforms.toString());
      gen.write("][");
      gen.write(nVars.toString());
      gen.write("] = {\n");
      
      for (int transform_idx = 0; transform_idx < nTransforms; ++transform_idx)
      {
         gen.write("   {");
         
         for (int var_idx = 0; var_idx < nVars; ++var_idx)
         {
            String weight = weights.get(var_idx).get(transform_idx);
            
            if ((var_idx + 1) == nVars)
            {
               gen.write(weight + "}");
            }
            else
            {
               gen.write(weight + ", ");
            }
         }
         
         if ((transform_idx + 1) == nTransforms)
         {
            gen.write("\n");
            gen.write("};\n");
         }
         else
         {
            gen.write(",\n");
         }
      }
   }
   
   /**
    * 
    */
   private void writeMainTransformFunction()
   {
      gen.write("/**\n"                                                       );
      gen.write(" * Transforms 'pnt'\n"                                       );
      gen.write(" * 'index' was the most recently applied transformation\n"   );
      gen.write(" */\n"                                                       );
      gen.write("void fct::vb::transform(const uint index, fct::Point& pnt)\n");
      gen.write("{\n");
      gen.indent();
      writeWeights();
      gen.write("\n");
      gen.write("pnt = ");
      for (int i = 0; i < currVar; ++i)
      {
         if (i > 0)
         {
            gen.write("      ");
         }
         
         String varNumber = Integer.toString(i);
         gen.write("(var_" + varNumber + "(pnt) * weights[index][" + varNumber + "])");
         
         if ((i + 1) == currVar)
         {
            gen.write(";\n");
         }
         else
         {
            gen.write(" +\n");
         }
      }
      gen.undent();
      gen.write("}\n");
   }
   
   /**
    * 
    */
   @Override
   public Integer visitUnit_(FacataParser.Unit_Context ctx)
   {  
      pass = 0;
      
      visit(ctx.statementList());
      
      if (currVar == 0)
      {
         sgh.usrExit("Must have at least one variation!");
      }
      
      pass = 1;
      
      currVar = 0;
      
      gen.open();

      gen.write("/**\n"                                                );
      gen.write(" * @author Forrest Jablonski\n"                       );
      gen.write(" *\n"                                                 );
      gen.write(" * AUTO-GENERATED\n"                                  );
      gen.write(" */\n"                                                );
      gen.write("\n"                                                   );
      gen.write("#include <cmath>\n"                                   );
      gen.write("\n"                                                   );
      gen.write("#include \"VariationBlend.h\"\n"                      );
      gen.write("\n"                                                   );
      gen.write("#include \"Point.h\"\n"                               );
      gen.write("\n"                                                   );
      visit(ctx.statementList());
      writeMainTransformFunction();
    
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
         /*
          * TODO I'm assuming g++ is smart enough to optimize const to constexpr
          */
         
         type = env.get(name);
         
         if (type == TPoint)
         {
            gen.write("const Point " + name + " = ");
         }
         else if (type == TFloat)
         {
            gen.write("const double " + name + " = ");
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
   public Integer visitVarStatement_(FacataParser.VarStatement_Context ctx)
   {
      if (pass == 0)
      {
         visit(ctx.numbersList());
         visit(ctx.statementList());
      }
      else // pass == 1
      {
         gen.write("/**\n");
         gen.write(" *\n");
         gen.write(" */\n");
         gen.write("inline fct::Point var_" + Integer.toString(currVar) + "(const fct::Point& pnt)\n");
         gen.write("{\n");
         gen.indent();
         visit(ctx.statementList());
         gen.undent();
         gen.write("}\n");
         gen.write("\n");
      }
      
      currVar += 1;
      
      return TInvalid;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitNumbersList_(FacataParser.NumbersList_Context ctx)
   {
      visit(ctx.numbersList());
      
      if (pass == 0)
      {
         weights.get(currVar).add(ctx.Decimal().getText());
      }
      
      return TInvalid;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitSingleNumber_(FacataParser.SingleNumber_Context ctx)
   {
      if (pass == 0)
      {
         if (weights.size() != currVar)
         {
            sgh.fctExit("Size of weights = " + weights.size() + ", should equal current var# = " + currVar + "!");
         }
         else
         {
            weights.add(new ArrayList<String>());
            weights.get(currVar).add(ctx.Decimal().getText());
         }
      }
      
      return TFloat;
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
      
      if ((lhs == TPoint) || (rhs == TPoint))
      {
         type = TPoint;
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
      
      if ((lhs == TPoint) || (rhs == TPoint))
      {
         type = TPoint;
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
   public Integer visitX_(FacataParser.X_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("pnt.x");
      }
      
      return TFloat;
   }
   
   /**
    * 
    */
   @Override
   public Integer visitY_(FacataParser.Y_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("pnt.y");
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
   public Integer visitPrimaryPointExpression_(FacataParser.PrimaryPointExpression_Context ctx)
   {
      return visit(ctx.pointExpression());
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
   public Integer visitPointExpression_(FacataParser.PointExpression_Context ctx)
   {
      if (pass == 1)
      {
         gen.write("{");
         visit(ctx.XCoord);
         gen.write(", ");
         visit(ctx.YCoord);
         gen.write("}");
      }
      
      return TPoint;
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
