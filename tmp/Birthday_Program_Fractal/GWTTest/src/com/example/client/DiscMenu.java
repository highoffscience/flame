package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class DiscMenu extends VariationBase
{
   public DiscMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r <- Sqrt(X*X + Y*Y)\n" +
            "t <- Atan(X / Y)\n" +
            "pi <- 3.14159265359\n" +
            "a <- t / pi\n" +
            "Return [a * Sin(pi * r), a * Cos(pi * r)]\n");
   }
}
