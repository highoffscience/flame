package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class DiamondMenu extends VariationBase
{
   public DiamondMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r <- Sqrt(X*X + Y*Y)\n" +
            "t <- Atan(X / Y)\n" +
            "Return [Sin(t) * Cos(r), Cos(t) * Sin(r)]\n");
   }
}
