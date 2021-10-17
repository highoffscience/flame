package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class SpiralVarMenu extends VariationBase
{
   public SpiralVarMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r <- Sqrt(X*X + Y*Y)\n" +
            "t <- Atan(X / Y)\n" +
            "Return [(Cos(t) + Sin(r)) / r, (Sin(t) - Cos(r)) / r]\n");
   }
}
