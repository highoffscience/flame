/**
 * @author Forrest Jablonski
 */

package fct.ft;

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
   
   private String scaleXExpr;
   private String scaleYExpr;
   private String transXExpr;
   private String transYExpr;
   private String widthExpr;
   private String heightExpr;
   
   private boolean isAuto;
   private int     pass;
   
   /**
    * 
    */
   public SourceGenerator(String cppFileName)
   {
      this.sgh    = new SourceGeneratorHelper("Fitter", cppFileName);
      this.gen    = new FacataCodeGenerator(cppFileName);
      this.isAuto = false;
      this.pass   = 0;
      this.scaleXExpr = "";
      this.scaleYExpr = "";
      this.transXExpr = "";
      this.transYExpr = "";
      this.widthExpr  = "";
      this.heightExpr = "";
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
      gen.open();
      
      pass = 0;
      
      visit(ctx.statementList());
      
      pass = 1;

      gen.write("/**                                                      \n");
      gen.write(" * @author Forrest Jablonski                             \n");
      gen.write(" *                                                       \n");
      gen.write(" * AUTO-GENERATED                                        \n");
      gen.write(" */                                                      \n");
      gen.write("                                                         \n");
      gen.write("#include \"Fitter.h\"                                    \n");
      gen.write("                                                         \n");
      gen.write("static fct::Point s_scale;                               \n");
      gen.write("static fct::Point s_trans;                               \n");
      gen.write("                                                         \n");
      gen.write("/**                                                      \n");
      gen.write(" * Init scale and trans                                  \n");
      gen.write(" */                                                      \n");
      gen.write("void fct::fit::init(const Point& minFitPnt,              \n");
      gen.write("                    const Point& maxFitPnt)              \n");
      gen.write("{                                                        \n");
      if (isAuto)
      {
         gen.indent();
         gen.write("constexpr uint width  = " + widthExpr  + ";                        \n");
         gen.write("constexpr uint height = " + heightExpr + ";                        \n");
         gen.write("const Point alpha = Point(width, height) / (maxFitPnt - minFitPnt);\n");
         gen.write("const Point beta  = -alpha * minFitPnt;                            \n");
         gen.write("const double minAlpha = (width < height) ? alpha.x : alpha.y;      \n");
         gen.write("s_scale = Point(minAlpha, minAlpha);                               \n");
         gen.write("s_trans = beta;                                                    \n");
         gen.undent();
      }
      gen.write("}                                                        \n");
      gen.write("                                                         \n");
      gen.write("/**                                                      \n");
      gen.write(" * Scale and translate 'pnt' and return the result       \n");
      gen.write(" */                                                      \n");
      gen.write("auto fct::fit::transform(const fct::Point& pnt) -> Point \n");
      gen.write("{                                                        \n");
      if (isAuto)
      {
         gen.write("   return (pnt * s_scale) + s_trans;                  \n");
      }
      else
      {
         visit(ctx.statementList());
         gen.indent();
         gen.write("constexpr uint width  = " + widthExpr  + ";              \n");
         gen.write("constexpr uint height = " + heightExpr + ";              \n");
         gen.write("constexpr uint mindim = width < height ? width : height; \n");
         gen.write("constexpr Point scale = {mindim * (" + scaleXExpr + "), mindim * (" + scaleYExpr + ")}; \n");
         gen.write("constexpr Point trans = {width  * (" + transXExpr + "), height * (" + transYExpr + ")}; \n");
         gen.write("                                                         \n");
         gen.write("   return (pnt * scale) + trans;                         \n");
         gen.undent();
      }
      
      gen.write("}                                                           \n");

      gen.close();

      return null;
   }

   /**
    * 
    */
   @Override
   public String visitListStatement_(FacataParser.ListStatement_Context ctx)
   {
      String s = "";
      
      s += visit(ctx.statementList());
      s += visit(ctx.statement());
      
      return s;
   }
   
   /**
    * 
    */
   @Override
   public String visitSingleStatement_(FacataParser.SingleStatement_Context ctx)
   {
      return visit(ctx.statement());
   }
   
   /**
    * 
    */
   @Override
   public String visitAssignScaleStatement_(FacataParser.AssignScaleStatement_Context ctx)
   {
      if (pass == 1)
      {
         String[] pnt_strs = visit(ctx.pointExpression()).split(" ");
         
         scaleXExpr = pnt_strs[0];
         scaleYExpr = pnt_strs[1];
      }
      
      return null;
   }
   
   /**
    * 
    */
   @Override
   public String visitAssignTransStatement_(FacataParser.AssignTransStatement_Context ctx)
   {
      if (pass == 1)
      {
         String[] pnt_strs = visit(ctx.pointExpression()).split(" ");
         
         transXExpr = pnt_strs[0];
         transYExpr = pnt_strs[1];
      }
      
      return null;
   }
   
   /**
    * 
    */
   @Override
   public String visitAssignWidthStatement_(FacataParser.AssignWidthStatement_Context ctx)
   {
      widthExpr = visit(ctx.additiveExpression());
      return null;
   }
   
   /**
    * 
    */
   @Override
   public String visitAssignHeightStatement_(FacataParser.AssignHeightStatement_Context ctx)
   {
      heightExpr = visit(ctx.additiveExpression());
      return null;
   }
   
   /**
    * 
    */
   @Override
   public String visitAssignAutoStatement_(FacataParser.AssignAutoStatement_Context ctx)
   {
      String op = ctx.OP.getText();
      
      if (op.equals("On"))
      {
         isAuto = true;
      }
      else if (op.equals("Off"))
      {
         isAuto = false;
      }
      else
      {
         sgh.fctExit("Undefined auto mode " + op + "!");
      }
      
      return null;
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
    * Points are returned with "X Y", which would result in a compile error.
    * No points shall undergo this operation.
    */
   @Override
   public String visitAdditionExpression_(FacataParser.AdditionExpression_Context ctx)
   {
      String s = "";
      
      if (pass == 1)
      {
         s += visit(ctx.additiveExpression());
         s += " " + ctx.OP.getText() + " ";
         s += visit(ctx.multiplicativeExpression());
      }
      
      return s;
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
    * Points are returned with "X Y", which would result in a compile error.
    * No points shall undergo this operation.
    */
   @Override
   public String visitMultiplicationExpression_(FacataParser.MultiplicationExpression_Context ctx)
   {
      String s = "";
      
      if (pass == 1)
      {
         s += visit(ctx.multiplicativeExpression());
         s += " " + ctx.OP.getText() + " ";
         s += visit(ctx.primaryExpression());
      }
      
      return s;
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
   public String visitPointExpression_(FacataParser.PointExpression_Context ctx)
   {
      String s = "";
      
      if (pass == 1)
      {
         s += visit(ctx.XCoord);
         s += " ";
         s += visit(ctx.YCoord);
      }
      
      return s;
   }
   
   /**
    * 
    */
   @Override
   public String visitParenthesisedExpression_(FacataParser.ParenthesisedExpression_Context ctx)
   {
      String s = "";
      
      if (pass == 1)
      {
         s += "(";
         s += visit(ctx.additiveExpression());
         s += ")";
      }
      
      return s;
   }
}
