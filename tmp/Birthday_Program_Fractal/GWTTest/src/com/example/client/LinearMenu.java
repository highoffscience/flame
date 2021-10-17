package com.example.client;

import com.google.gwt.user.client.ui.TextArea;

public class LinearMenu extends VariationBase
{
   public LinearMenu(TextArea codeWindow, int nTransforms)
   {
      super(codeWindow, getCodeBody(nTransforms));
   }

   public static String getCodeBody(int nTransforms)
   {
      return getCodeBody(nTransforms, "Return [X, Y]\n");
   }
}
