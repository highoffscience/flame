package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class SwirlMenu extends VariationBase
{
   public SwirlMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r2 <- X*X + Y*Y\n" +
            "s  <- Sin(r2)\n" +
            "c  <- Cos(r2)\n" +
            "Return [X*s - Y*c, X*c + Y*s]\n");
   }
}
