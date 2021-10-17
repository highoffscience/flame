package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class HyperbolicMenu extends VariationBase
{
   public HyperbolicMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r <- Sqrt(X*X + Y*Y)\n" +
            "t <- Atan(X / Y)\n" +
            "Return [Sin(t) / r, Cos(t) * r]\n");
   }
}
