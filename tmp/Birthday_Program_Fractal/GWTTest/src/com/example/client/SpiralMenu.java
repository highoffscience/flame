package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class SpiralMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public SpiralMenu(TextArea codeWindow)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText(
            "M0 <- [ 0.7517, -0.2736, 0.2736, 0.7517, 0.0,    0.0,   0.0/3.0, 0.7 ]\n" +
            "M1 <- [ 0.2,     0.0,    0.0,    0.2,    1.0,   -0.364, 1.0/3.0, 0.1 ]\n" +
            "M2 <- [ 0.2,     0.0,    0.0,    0.2,   -0.364,  1.0,   2.0/3.0, 0.1 ]\n" +
            "M3 <- [ 0.2,     0.0,    0.0,    0.2,   -0.728, -0.728, 3.0/3.0, 0.1 ]\n");

      initWidget(vPanel);
   }

   @Override
   public int getNTransforms()
   {
      return 4;
   }
}
