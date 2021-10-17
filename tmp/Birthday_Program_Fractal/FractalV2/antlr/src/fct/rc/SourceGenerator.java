/**
 * @author Forrest Jablonski
 */

package fct.rc;

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

   /**
    *
    */
   public SourceGenerator(String cppFileName)
   {
      this.sgh = new SourceGeneratorHelper("Fractal", cppFileName);
      this.gen = new FacataCodeGenerator(cppFileName);

       widthExprStr = null;
      heightExprStr = null;
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

      gen.open();

      gen.write("/**                                                                   \n");
      gen.write(" * @author Forrest Jablonski                                          \n");
      gen.write(" *                                                                    \n");
      gen.write(" * AUTO-GENERATED                                                     \n");
      gen.write(" */                                                                   \n");
      gen.write("                                                                      \n");
      gen.write("#include <png++/png.hpp>                                              \n");
      gen.write("                                                                      \n");
      gen.write("#include \"Standard.h\"                                               \n");
      gen.write("                                                                      \n");
      gen.write("#include \"Pixel.h\"                                                  \n");
      gen.write("#include \"Renderer.h\"                                               \n");
      gen.write("                                                                      \n");
      gen.write("/**                                                                   \n");
      gen.write(" *                                                                    \n");
      gen.write(" */                                                                   \n");
      gen.write("int main(const int argc, const char* const* const argv)               \n");
      gen.write("{                                                                     \n");
      gen.write("   using fct::uint;                                                   \n");
      gen.write("                                                                      \n");
      gen.write("   constexpr uint width  = uint(" +  widthExprStr + ");               \n");
      gen.write("   constexpr uint height = uint(" + heightExprStr + ");               \n");
      gen.write("                                                                      \n");
      gen.write("   fct::Pixel** histo = new fct::Pixel*[height];                      \n");
      gen.write("   for (uint i = 0U; i < height; ++i)                                 \n");
      gen.write("   {                                                                  \n");
      gen.write("      histo[i] = new fct::Pixel[width];                               \n");
      gen.write("   }                                                                  \n");
      gen.write("                                                                      \n");
      gen.write("   fct::rd::render(histo);                                            \n");
      gen.write("                                                                      \n");
      gen.write("   png::image<png::rgba_pixel> image(width, height);                  \n");
      gen.write("                                                                      \n");
      gen.write("   for (uint i = 0U; i < height; ++i)                                 \n");
      gen.write("   {                                                                  \n");
      gen.write("      for (uint j = 0U; j < width; ++j)                               \n");
      gen.write("      {                                                               \n");
      gen.write("         const fct::Pixel& pxl = histo[i][j];                         \n");
      gen.write("                                                                      \n");
      gen.write("         const fct::ubyte r = (fct::ubyte) ((pxl.r * 255.0F) + 0.5F); \n");
      gen.write("         const fct::ubyte g = (fct::ubyte) ((pxl.g * 255.0F) + 0.5F); \n");
      gen.write("         const fct::ubyte b = (fct::ubyte) ((pxl.b * 255.0F) + 0.5F); \n");
      gen.write("         const fct::ubyte a = (fct::ubyte) ((pxl.a * 255.0F) + 0.5F); \n");
      gen.write("                                                                      \n");
      gen.write("         image[i][j] = png::rgba_pixel(r, g, b, a);                   \n");
      gen.write("      }                                                               \n");
      gen.write("   }                                                                  \n");
      gen.write("                                                                      \n");
      gen.write("   image.write(\"../pics/fractal-1.0.png\");                          \n");
      gen.write("                                                                      \n");
      gen.write("   for (uint i = 0U; i < height; ++i)                                 \n");
      gen.write("   {                                                                  \n");
      gen.write("      delete[] histo[i];                                              \n");
      gen.write("   }                                                                  \n");
      gen.write("   delete[] histo;                                                    \n");
      gen.write("                                                                      \n");
      gen.write("   return 0;                                                          \n");
      gen.write("}                                                                     \n");

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
