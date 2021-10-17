package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class ExMenu extends VariationBase
{
   public ExMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r <- Sqrt(X*X + Y*Y)\n" +
            "t <- Atan(X / Y)\n" +
            "p0  <- Sin(t + r)\n" +
            "p03 <- p0 * p0 * p0\n" +
            "p1  <- Cos(t - r)\n" +
            "p13 <- p1 * p1 * p1\n" +
            "Return [r * (p03 + p13), r * (p03 - p13)]\n");
   }
}
