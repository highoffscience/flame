package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class SpectrumMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public SpectrumMenu(TextArea codeWindow)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText(
            "begin <- [0.0, 0.0, 0.0]\n" +
            "end   <- [1.0, 1.0, 1.0]\n" +
            "alpha <- end - begin\n" +
            "beta  <- begin\n" +
            "\n" +
            "// now return the linear interpolation\n" +
            "\n" +
            "Return alpha * Color + beta\n");

      initWidget(vPanel);
   }
}
