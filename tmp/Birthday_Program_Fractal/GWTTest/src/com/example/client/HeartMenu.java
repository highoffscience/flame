package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class HeartMenu extends VariationBase
{
   public HeartMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r <- Sqrt(X*X + Y*Y)\n" +
            "t <- Atan(X / Y)\n" +
            "Return [r * Sin(t * r), -r * Cos(t * r)]\n");
   }
}
