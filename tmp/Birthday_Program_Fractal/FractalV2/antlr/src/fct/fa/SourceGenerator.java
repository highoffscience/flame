/**
 * @author Forrest Jablonski
 */

package fct.fa;

import fct.FacataCodeGenerator;
import fct.SourceGeneratorHelper;

import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.*;

/**
 *
 */
public class SourceGenerator extends FacataBaseVisitor<String>
{
   private SourceGeneratorHelper sgh;
   private FacataCodeGenerator   gen;

   private String  widthExprStr;
   private String heightExprStr;
   private String nitersExprStr;
   private String  gammaExprStr;

   /**
    *
    */
   public SourceGenerator(String cppFileName)
   {
      this.sgh = new SourceGeneratorHelper("Flame", cppFileName);
      this.gen = new FacataCodeGenerator(cppFileName);

       widthExprStr = null;
      heightExprStr = null;
      nitersExprStr = null;
       gammaExprStr = null;
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
   public String visitUnit_(FacataParser.Unit_Context ctx)
   {
      visit(ctx.statementList());

      if (widthExprStr == null)
      {
         sgh.fctExit("Width is not defined!");
      }

      if (heightExprStr == null)
      {
         sgh.fctExit("Height is not defined!");
      }

      if (nitersExprStr == null)
      {
         sgh.fctExit("NIters is not defined!");
      }

      if (gammaExprStr == null)
      {
         sgh.fctExit("Gamma is not defined!");
      }

      gen.open();

      gen.write("/**                                                                                    \n");
      gen.write(" * @author Forrest Jablonski                                                           \n");
      gen.write(" *                                                                                     \n");
      gen.write(" * AUTO-GENERATED                                                                      \n");
      gen.write(" */                                                                                    \n");
      gen.write("                                                                                       \n");
      gen.write("#include <cmath>                                                                       \n");
      gen.write("#include <iostream>                                                                    \n");
      gen.write("#include <limits>                                                                      \n");
      gen.write("                                                                                       \n");
      gen.write("#include \"Renderer.h\"                                                                \n");
      gen.write("                                                                                       \n");
      gen.write("#include \"ColorScheme.h\"                                                             \n");
      gen.write("#include \"Fitter.h\"                                                                  \n");
      gen.write("#include \"Pixel.h\"                                                                   \n");
      gen.write("#include \"Point.h\"                                                                   \n");
      gen.write("#include \"Random.h\"                                                                  \n");
      gen.write("#include \"StrangeAttractor.h\"                                                        \n");
      gen.write("#include \"VariationBlend.h\"                                                          \n");
      gen.write("                                                                                       \n");
      gen.write("/**                                                                                    \n");
      gen.write(" *                                                                                     \n");
      gen.write(" */                                                                                    \n");
      gen.write("void fct::rd::render(Pixel* const* const histo)                                        \n");
      gen.write("{                                                                                      \n");
      gen.write("   constexpr uint width  = uint(" +  widthExprStr + ");                                \n");
      gen.write("   constexpr uint height = uint(" + heightExprStr + ");                                \n");
      gen.write("                                                                                       \n");
      gen.write("   Random rand;                                                                        \n");
      gen.write("                                                                                       \n");
      gen.write("   Point pnt = Point((2.0 * rand.genUniformReal()) - 1.0,  // x                        \n");
      gen.write("                     (2.0 * rand.genUniformReal()) - 1.0); // y                        \n");
      gen.write("   double clr = rand.genUniformReal();                                                 \n");
      gen.write("                                                                                       \n");
      gen.write("   for (uint i = 0U; i < 100U; ++i)                                                    \n");
      gen.write("   {                                                                                   \n");
      gen.write("      const uint index = sa::preTransform(pnt, clr);                                   \n");
      gen.write("      vb::transform(index, pnt);                                                       \n");
      gen.write("      sa::postTransform(pnt, clr);                                                     \n");
      gen.write("   }                                                                                   \n");
      gen.write("                                                                                       \n");
      gen.write("   { // create fitter                                                                  \n");
      gen.write("      Point minFitPnt = Point(std::numeric_limits<double>::max(),                      \n");
      gen.write("                              std::numeric_limits<double>::max());                     \n");
      gen.write("      Point maxFitPnt = Point(std::numeric_limits<double>::lowest(),                   \n");
      gen.write("                              std::numeric_limits<double>::lowest());                  \n");
      gen.write("                                                                                       \n");
      gen.write("      for (uint i = 0U; i < 10000U; ++i)                                               \n");
      gen.write("      {                                                                                \n");
      gen.write("         const uint index = sa::preTransform(pnt, clr);                                \n");
      gen.write("         vb::transform(index, pnt);                                                    \n");
      gen.write("         sa::postTransform(pnt, clr);                                                  \n");
      gen.write("                                                                                       \n");
      gen.write("         if      (pnt.x < minFitPnt.x) { minFitPnt.x = pnt.x; }                        \n");
      gen.write("         else if (pnt.x > maxFitPnt.x) { maxFitPnt.x = pnt.x; }                        \n");
      gen.write("                                                                                       \n");
      gen.write("         if      (pnt.y < minFitPnt.y) { minFitPnt.y = pnt.y; }                        \n");
      gen.write("         else if (pnt.y > maxFitPnt.y) { maxFitPnt.y = pnt.y; }                        \n");
      gen.write("      }                                                                                \n");
      gen.write("                                                                                       \n");
      gen.write("      fit::init(minFitPnt, maxFitPnt);                                                 \n");
      gen.write("   } // end create fitter                                                              \n");
      gen.write("                                                                                       \n");
      gen.write("   constexpr ulong niters = ulong(" + nitersExprStr + ");                              \n");
      gen.write("   constexpr ulong step = niters / 100UL;                                              \n");
      gen.write("   for (ulong i = 0; i < niters; ++i)                                                  \n");
      gen.write("   {                                                                                   \n");
      gen.write("      if (i % step == 0)                                                               \n");
      gen.write("      {                                                                                \n");
      gen.write("         std::cout << \"\\r\" << (i / step) << \"% Rendered\" << std::flush;           \n");
      gen.write("      }                                                                                \n");
      gen.write("                                                                                       \n");
      gen.write("      const uint index = sa::preTransform(pnt, clr);                                   \n");
      gen.write("      vb::transform(index, pnt);                                                       \n");
      gen.write("      sa::postTransform(pnt, clr);                                                     \n");
      gen.write("                                                                                       \n");
      gen.write("      const Point fittedPnt = fit::transform(pnt);                                     \n");
      gen.write("                                                                                       \n");
      gen.write("      const int x =               (int)fittedPnt.x;                                    \n");
      gen.write("      const int y = (int)height - (int)fittedPnt.y;                                    \n");
      gen.write("                                                                                       \n");
      gen.write("      if (x >= 0 && x < (int)width &&                                                  \n");
      gen.write("          y >= 0 && y < (int)height)                                                   \n");
      gen.write("      {                                                                                \n");
      gen.write("         histo[y][x]   += cs::transform(clr);                                          \n");
      gen.write("         histo[y][x].a += 1.0F;                                                        \n");
      gen.write("      }                                                                                \n");
      gen.write("   }                                                                                   \n");
      gen.write("   std::cout << \"\\r100% Rendered\\n\" << std::flush;                                 \n");
      gen.write("                                                                                       \n");
      gen.write("   float alphaMax = 0.0F;                                                              \n");
      gen.write("   for (uint i = 0; i < height; ++i)                                                   \n");
      gen.write("   {                                                                                   \n");
      gen.write("      for (uint j = 0; j < width; ++j)                                                 \n");
      gen.write("      {                                                                                \n");
      gen.write("         Pixel& pxl = histo[i][j];                                                     \n");
      gen.write("                                                                                       \n");
      gen.write("         if (pxl.a > 0.0F)                                                             \n");
      gen.write("         {                                                                             \n");
      gen.write("            pxl *= std::log1p(pxl.a) / pxl.a;                                          \n");
      gen.write("                                                                                       \n");
      gen.write("            if (pxl.a > alphaMax)                                                      \n");
      gen.write("            {                                                                          \n");
      gen.write("               alphaMax = pxl.a;                                                       \n");
      gen.write("            }                                                                          \n");
      gen.write("         }                                                                             \n");
      gen.write("      }                                                                                \n");
      gen.write("   }                                                                                   \n");
      gen.write("                                                                                       \n");
      gen.write("   constexpr float invGamma = float(1.0 / (" + gammaExprStr + ")); // 2.2F is baseline \n");
      gen.write("   for (uint i = 0; i < height; ++i)                                                   \n");
      gen.write("   {                                                                                   \n");
      gen.write("      for (uint j = 0; j < width; ++j)                                                 \n");
      gen.write("      {                                                                                \n");
      gen.write("         Pixel& pxl = histo[i][j];                                                     \n");
      gen.write("                                                                                       \n");
      gen.write("         if (pxl.a > 0.0F)                                                             \n");
      gen.write("         {                                                                             \n");
      gen.write("            pxl /= alphaMax;                                                           \n");
      gen.write("            pxl ^= invGamma;                                                           \n");
      gen.write("         }                                                                             \n");
      gen.write("      }                                                                                \n");
      gen.write("   }                                                                                   \n");
      gen.write("}                                                                                      \n");

      gen.close();

      return null;
   }

   /**
    *
    */
   @Override
   public String visitListStatement_(FacataParser.ListStatement_Context ctx)
   {
      visit(ctx.statementList());
      visit(ctx.statement());

      return null;
   }

   /**
    *
    */
   @Override
   public String visitSingleStatement_(FacataParser.SingleStatement_Context ctx)
   {
      visit(ctx.statement());

      return null;
   }

   /**
    *
    */
   @Override
   public String visitAssignWidthStatement_(FacataParser.AssignWidthStatement_Context ctx)
   {
      if (widthExprStr != null)
      {
         sgh.fctExit("Width is defined more than once!");
      }

      widthExprStr = visit(ctx.additiveExpression());

      return widthExprStr;
   }

   /**
    *
    */
   @Override
   public String visitAssignHeightStatement_(FacataParser.AssignHeightStatement_Context ctx)
   {
      if (heightExprStr != null)
      {
         sgh.fctExit("Height is defined more than once!");
      }

      heightExprStr = visit(ctx.additiveExpression());

      return heightExprStr;
   }

   /**
    *
    */
   @Override
   public String visitAssignNItersStatement_(FacataParser.AssignNItersStatement_Context ctx)
   {
      if (nitersExprStr != null)
      {
         sgh.fctExit("NIters is defined more than once!");
      }

      nitersExprStr = visit(ctx.additiveExpression());

      return nitersExprStr;
   }

   /**
    *
    */
   @Override
   public String visitAssignGammaStatement_(FacataParser.AssignGammaStatement_Context ctx)
   {
      if (gammaExprStr != null)
      {
         sgh.fctExit("Gamma is defined more than once!");
      }

      gammaExprStr = visit(ctx.additiveExpression());

      return gammaExprStr;
   }

   /**
    *
    */
   @Override
   public String visitEmptyStatement_(FacataParser.EmptyStatement_Context ctx)
   {
      return null;
   }

   /**
    *
    */
   @Override
   public String visitAdditionExpression_(FacataParser.AdditionExpression_Context ctx)
   {
      String lhs = visit(ctx.additiveExpression());
      String rhs = visit(ctx.multiplicativeExpression());

      return lhs + " " + ctx.OP.getText() + " " + rhs;
   }

   /**
    *
    */
   @Override
   public String visitAdditiveExpression_(FacataParser.AdditiveExpression_Context ctx)
   {
      return visit(ctx.multiplicativeExpression());
   }

   /**
    *
    */
   @Override
   public String visitMultiplicationExpression_(FacataParser.MultiplicationExpression_Context ctx)
   {
      String lhs = visit(ctx.multiplicativeExpression());
      String rhs = visit(ctx.primaryExpression());

      return lhs + " " + ctx.OP.getText() + " " + rhs;
   }

   /**
    *
    */
   @Override
   public String visitMultiplicativeExpression_(FacataParser.MultiplicativeExpression_Context ctx)
   {
      return visit(ctx.primaryExpression());
   }

   /**
    *
    */
   @Override
   public String visitInteger_(FacataParser.Integer_Context ctx)
   {
      return ctx.Integer().getText();
   }

   /**
    *
    */
   @Override
   public String visitDecimal_(FacataParser.Decimal_Context ctx)
   {
      return ctx.Decimal().getText();
   }

   /**
    *
    */
   @Override
   public String visitPrimaryParenthesisedExpression_(FacataParser.PrimaryParenthesisedExpression_Context ctx)
   {
      return visit(ctx.parenthesisedExpression());
   }

   /**
    *
    */
   @Override
   public String visitParenthesisedExpression_(FacataParser.ParenthesisedExpression_Context ctx)
   {
      return "(" + visit(ctx.additiveExpression()) + ")";
   }
}
