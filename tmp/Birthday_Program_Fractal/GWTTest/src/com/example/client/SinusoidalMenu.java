package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class SinusoidalMenu extends VariationBase
{
   public SinusoidalMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms, "Return [Sin(X), Sin(Y)]\n");
   }
}
