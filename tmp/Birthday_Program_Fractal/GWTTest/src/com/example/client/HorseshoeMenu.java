package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class HorseshoeMenu extends VariationBase
{
   public HorseshoeMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r  <- Sqrt(X*X + Y*Y)\n" +
            "nx <- ((X-Y) * (X+Y)) / r\n" +
            "ny <- (2.0*X*Y) / r\n" +
            "Return [nx, ny]\n");
   }
}
