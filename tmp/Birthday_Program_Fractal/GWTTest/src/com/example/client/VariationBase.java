package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class VariationBase extends SAMenuElement
{
   private VerticalPanel vPanel;

   public VariationBase(TextArea codeWindow, String fullCode)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText(fullCode);

      initWidget(vPanel);
   }

   public static String getCodeBody(int nTransforms, String code)
   {
      return "Var " + getUniformWeights(nTransforms) + "\n" +
             code +
             "End\n";
   }

   private static String getUniformWeights(int nTransforms)
   {
      if (nTransforms <= 0)
      {
         return "()"; // will be a compile error
      }

      String code = "(";

      for (int i = 1; i < nTransforms; ++i)
      {
         code += "1.0, ";
      }
      code += "1.0)";

      return code;
   }
}
