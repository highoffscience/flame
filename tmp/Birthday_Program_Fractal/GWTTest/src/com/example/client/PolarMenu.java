package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class PolarMenu extends VariationBase
{
   public PolarMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r <- Sqrt(X*X + Y*Y)\n" +
            "t <- Atan(X / Y)\n" +
            "Return [t / 3.14159265359, r - 1.0]\n");
   }
}
