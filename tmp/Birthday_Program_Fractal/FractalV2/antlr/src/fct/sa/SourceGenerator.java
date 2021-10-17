/**
 * @author Forrest Jablonski
 */

package fct.sa;

import fct.FacataCodeGenerator;
import fct.SourceGeneratorHelper;

import java.util.HashMap;
import java.util.ArrayList;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.*;

// TODO guarantee that probabilities add up to unity
// TODO guarantee that probabilities decrease with subsequent matrices

// TODO below is the code for the apollonian gasket

//   constexpr Matrix mat_0 = {0.0, 1.0/3.0};
//   constexpr Matrix mat_1 = {0.5, 1.0/3.0};
//   constexpr Matrix mat_2 = {1.0, 1.0/3.0};
//
//   constexpr Point p_1 = Point(1.0, 0.0);
//   constexpr Point p_2 = Point(2.0, 0.0);
//   constexpr Point p_3 = Point(3.0, 0.0);
//   constexpr Point p_s = Point(std::sqrt(3.0), 0.0);
//
//   constexpr Point p_1_pls_s  = p_1.cPls(p_s);
//   constexpr Point p_2nd_term = p_1_pls_s.cDvd(p_2.cPls(p_s));
//
//   constexpr Point p_0p5  = Point( 0.5, 0.0);
//   constexpr Point p_n1   = Point(-1.0, 0.0);
//   constexpr Point p_si   = p_3.rev();
//   constexpr Point p_2num = p_0p5.cTms(p_n1.cPls(p_si));
//   constexpr Point p_3num = p_0p5.cTms(p_n1.cMns(p_si));
//
//   // TODO guarantee that probabilities add up to unity
//   // TODO guarantee that probabilities decrease with subsequent matrices
//
//   const double r = fctRand.genUniformReal();
//
//   if (r < mat_0.prob)
//   {
//      pnt = (p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term);
//      clr = 0.5 * (clr + mat_0.clr);
//      //return 0U;
//   }
//   else if (r < mat_0.prob + mat_1.prob)
//   {
//      pnt = p_2num.cDvd((p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term));
//      clr = 0.5 * (clr + mat_1.clr);
//      //return 1U;
//   }
//   else
//   {
//      pnt = p_3num.cDvd((p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term));
//      clr = 0.5 * (clr + mat_2.clr);
//      //return 2U;
//   }

/**
 *
 */
public class SourceGenerator extends FacataBaseVisitor<Integer>
{
   private static final int TFloat     = 0;
   private static final int TPoint     = 1;
   private static final int TReference = 2;
   private static final int TNone      = 3;
   private static final int TIas       = 4;
   private static final int TIfs       = 5;
   private static final int TInvalid   = 6;

   private SourceGeneratorHelper    sgh;
   private FacataCodeGenerator      gen;
   private HashMap<String, Integer> env;

   private int matrixCount;

   /**
    *
    */
   public SourceGenerator(String cppFileName)
   {
      this.sgh = new SourceGeneratorHelper("StrangeAttractor", cppFileName);
      this.gen = new FacataCodeGenerator(cppFileName);
      this.env = new HashMap<String, Integer>();

      this.matrixCount = 0;
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
   private void writeMatrixTransform(final int id, final boolean preMode)
   {
      String idStr = Integer.toString(id);
      String mtxStr = "mat_" + idStr;

      gen.write("const double x = (" + mtxStr + ".a * pnt.x) + (" + mtxStr + ".b * pnt.y) + " + mtxStr + ".e; \n");
      gen.write("const double y = (" + mtxStr + ".c * pnt.x) + (" + mtxStr + ".d * pnt.y) + " + mtxStr + ".f; \n");
      gen.write("pnt.x = x;                                                                                   \n");
      gen.write("pnt.y = y;                                                                                   \n");
      gen.write("clr = 0.5 * (clr + " + mtxStr + ".clr);                                                      \n");
      if (preMode)
      {
         gen.write("return " + idStr + "U;                                                                    \n");
      }
   }

   /**
    *
    */
   private void writeMatrixProbSummation(final int maxID)
   {
      gen.write("mat_0.prob");
      for (int i = 1; i <= maxID; ++i)
      {
         gen.write(" + mat_" + Integer.toString(i) + ".prob");
      }
   }

   /**
    *
    */
   private void writeMatrixDecisionTree(final boolean preMode)
   {
      if (matrixCount == 0)
      {
         // nothing
      }
      else if (matrixCount == 1)
      {
         writeMatrixTransform(0, preMode);
      }
      else
      {
         gen.write("                                          \n");
         gen.write("const double r = fctRand.genUniformReal();\n");
         gen.write("\n");
         gen.write("if (r < mat_0.prob)                       \n");
         gen.write("{                                         \n");
         gen.indent();
         writeMatrixTransform(0, preMode);
         gen.undent();
         gen.write("}                                         \n");
         for (int i = 1; i < matrixCount - 1; ++i)
         {
            gen.write("else if (r < ");
            writeMatrixProbSummation(i);
            gen.write(")                           \n");
            gen.write("{                           \n");
            gen.indent();
            writeMatrixTransform(i, preMode);
            gen.undent();
            gen.write("}                           \n");
         }
         gen.write("else                        \n");
         gen.write("{                           \n");
         gen.indent();
         writeMatrixTransform(matrixCount - 1, preMode);
         gen.undent();
         gen.write("}                           \n");
      }
   }

   /**
    *
    */
   @Override
   public Integer visitUnit_(FacataParser.Unit_Context ctx)
   {
      gen.open();

      gen.write("/**                                          \n");
      gen.write(" * @author Forrest Jablonski                 \n");
      gen.write(" *                                           \n");
      gen.write(" * AUTO-GENERATED                            \n");
      gen.write(" */                                          \n");
      gen.write("                                             \n");
      gen.write("#include \"StrangeAttractor.h\"              \n");
      gen.write("                                             \n");
      gen.write("#include \"Point.h\"                         \n");
      gen.write("#include \"Random.h\"                        \n");
      gen.write("                                             \n");
      gen.write("struct IASMatrix                             \n");
      gen.write("{                                            \n");
      gen.write("   const double a, b, c, d, e, f;            \n");
      gen.write("   const double clr;                         \n");
      gen.write("   const double prob;                        \n");
      gen.write("};                                           \n");
      gen.write("                                             \n");
      gen.write("struct IFSMatrix                             \n");
      gen.write("{                                            \n");
      gen.write("   const double clr;                         \n");
      gen.write("   const double prob;                        \n");
      gen.write("};                                           \n");
      gen.write("                                             \n");
      gen.write("static fct::Random fctRand;                  \n");
      gen.write("                                             \n");

      visit(ctx.statementList());

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
   private void writeApollonianGasket()
   {
      gen.write("constexpr IFSMatrix mat_0 = {0.0, 1.0/3.0};                            \n");
      gen.write("constexpr IFSMatrix mat_1 = {0.5, 1.0/3.0};                            \n");
      gen.write("constexpr IFSMatrix mat_2 = {1.0, 1.0/3.0};                            \n");
      gen.write("                                                                       \n");
      gen.write("constexpr Point p_1 = Point(1.0, 0.0);                                 \n");
      gen.write("constexpr Point p_2 = Point(2.0, 0.0);                                 \n");
      gen.write("constexpr Point p_3 = Point(3.0, 0.0);                                 \n");
      gen.write("constexpr Point p_s = Point(std::sqrt(3.0), 0.0);                      \n");
      gen.write("                                                                       \n");
      gen.write("constexpr Point p_1_pls_s  = p_1.cPls(p_s);                            \n");
      gen.write("constexpr Point p_2nd_term = p_1_pls_s.cDvd(p_2.cPls(p_s));            \n");
      gen.write("                                                                       \n");
      gen.write("constexpr Point p_0p5  = Point( 0.5, 0.0);                             \n");
      gen.write("constexpr Point p_n1   = Point(-1.0, 0.0);                             \n");
      gen.write("constexpr Point p_si   = p_3.rev();                                    \n");
      gen.write("constexpr Point p_2num = p_0p5.cTms(p_n1.cPls(p_si));                  \n");
      gen.write("constexpr Point p_3num = p_0p5.cTms(p_n1.cMns(p_si));                  \n");
      gen.write("                                                                       \n");
      gen.write("// TODO guarantee that probabilities add up to unity                   \n");
      gen.write("// TODO guarantee that probabilities decrease with subsequent matrices \n");
      gen.write("                                                                       \n");
      gen.write("const double r = fctRand.genUniformReal();                             \n");
      gen.write("                                                                       \n");
      gen.write("if (r < mat_0.prob)                                                    \n");
      gen.write("{                                                                      \n");
      gen.write("   pnt = (p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term);             \n");
      gen.write("   clr = 0.5 * (clr + mat_0.clr);                                      \n");
      gen.write("   return 0U;                                                          \n");
      gen.write("}                                                                      \n");
      gen.write("else if (r < mat_0.prob + mat_1.prob)                                  \n");
      gen.write("{                                                                      \n");
      gen.write("   pnt = p_2num.cDvd((p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term));\n");
      gen.write("   clr = 0.5 * (clr + mat_1.clr);                                      \n");
      gen.write("   return 1U;                                                          \n");
      gen.write("}                                                                      \n");
      gen.write("else                                                                   \n");
      gen.write("{                                                                      \n");
      gen.write("   pnt = p_3num.cDvd((p_3.cDvd(p_1_pls_s.cMns(pnt))).cMns(p_2nd_term));\n");
      gen.write("   clr = 0.5 * (clr + mat_2.clr);                                      \n");
      gen.write("   return 2U;                                                          \n");
      gen.write("}                                                                      \n");
   }

   /**
    * 
    */
   @Override
   public Integer visitPreStatement_(FacataParser.PreStatement_Context ctx)
   {
      Integer t = visit(ctx.typeExpression());

      matrixCount = 0;

      gen.write("/**                                                 \n");
      gen.write(" *                                                  \n");
      gen.write(" */                                                 \n");
      gen.write("uint fct::sa::preTransform(Point& pnt, double& clr) \n");
      gen.write("{                                                   \n");
      gen.indent();
      if (t == TIfs)
      {
         writeApollonianGasket();
      }
      else if (t == TIas)
      {
         visit(ctx.statementList());
         writeMatrixDecisionTree(true);
      }
      gen.undent();
      gen.write("}                                                   \n");
      gen.write("                                                    \n"); // leave a newline for post func def

      return TInvalid;
   }

   /**
    * 
    */
   @Override
   public Integer visitPostStatement_(FacataParser.PostStatement_Context ctx)
   {
      Integer t = visit(ctx.typeExpression());

      matrixCount = 0;

      gen.write("/**                                                  \n");
      gen.write(" *                                                   \n");
      gen.write(" */                                                  \n");
      gen.write("void fct::sa::postTransform(Point& pnt, double& clr) \n");
      gen.write("{                                                    \n");
      gen.indent();
      visit(ctx.statementList());
      writeMatrixDecisionTree(false);
      gen.undent();
      gen.write("}                                                    \n");

      return TInvalid;
   }

   /**
    * 
    */
   @Override
   public Integer visitAssignmentStatement_(FacataParser.AssignmentStatement_Context ctx)
   {
      String name = ctx.Identifier().getText();

      gen.write("const auto " + name + " = ");

      visit(ctx.additiveExpression());
      gen.write(";\n");

      return TInvalid;
   }

   /**
    * 
    */
   @Override
   public Integer visitMatrixStatement_(FacataParser.MatrixStatement_Context ctx)
   {
      String id = ctx.Matrix().getText().substring(1);

      matrixCount += 1;

      gen.write("constexpr IASMatrix mat_" + id + " = ");
      visit(ctx.matrixExpression());
      gen.write(";\n");

      return TInvalid;
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
   public Integer visitTypeExpression_(FacataParser.TypeExpression_Context ctx)
   {
      String name = ctx.TYPE.getText();

      if (name.equals("None"))
      {
         return TNone;
      }
      else if (name.equals("Ias"))
      {
         return TIas;
      }
      else if (name.equals("Ifs"))
      {
         return TIfs;
      }
      else
      {
         sgh.fctExit("No type expr " + name + " found!");
      }

      return TInvalid;
   }

   /**
    * 
    */
   @Override
   public Integer visitMatrixExpression_(FacataParser.MatrixExpression_Context ctx)
   {
      gen.write("{");
      visit(ctx.A);
      gen.write(", ");
      visit(ctx.B);
      gen.write(", ");
      visit(ctx.C);
      gen.write(", ");
      visit(ctx.D);
      gen.write(", ");
      visit(ctx.E);
      gen.write(", ");
      visit(ctx.F);
      gen.write(", ");
      visit(ctx.CLR);
      gen.write(", ");
      visit(ctx.PROB);
      gen.write("}");

      //gen.write("{");
      //visit(ctx.additiveExpression());
      //gen.write("}");

      return TInvalid;
   }

   /**
    * 
    */
   @Override
   public Integer visitAdditionExpression_(FacataParser.AdditionExpression_Context ctx)
   {
      visit(ctx.additiveExpression());
      gen.write(" " + ctx.OP.getText() + " ");
      visit(ctx.multiplicativeExpression());

      return TInvalid;
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
      visit(ctx.multiplicativeExpression());
      gen.write(" " + ctx.OP.getText() + " ");
      visit(ctx.primaryExpression());

      return TInvalid;
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
      gen.write(ctx.Integer().getText());

      return TFloat;
   }

   /**
    * 
    */
   @Override
   public Integer visitDecimal_(FacataParser.Decimal_Context ctx)
   {
      gen.write(ctx.Decimal().getText());

      return TFloat;
   }

   /**
    * 
    */
   @Override
   public Integer visitReference_(FacataParser.Reference_Context ctx)
   {
      String name = ctx.Identifier().getText();

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

      gen.write(name);

      return env.get(name);
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
   public Integer visitParenthesisedExpression_(FacataParser.ParenthesisedExpression_Context ctx)
   {
      gen.write("(");
      Integer t = visit(ctx.additiveExpression());
      gen.write(")");

      return t;
   }
}
