package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class SphericalMenu extends VariationBase
{
   public SphericalMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms,
            "r2 <- X*X + Y*Y\n" +
            "Return [X/r2, Y/r2]\n");
   }
}
