package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class BarnsleyFernMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public BarnsleyFernMenu(TextArea codeWindow)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText(
            "M0 <- [ 0.85,  0.04, -0.04, 0.85, 0.0, 1.60, (0.0/3.0), 0.85]\n" +
            "M1 <- [ 0.20, -0.26,  0.23, 0.22, 0.0, 1.60, (1.0/3.0), 0.07]\n" +
            "M2 <- [-0.15,  0.28,  0.26, 0.24, 0.0, 0.44, (2.0/3.0), 0.07]\n" +
            "M3 <- [ 0.00,  0.00,  0.00, 0.16, 0.0, 0.00, (3.0/3.0), 0.01]\n");

      initWidget(vPanel);
   }

   @Override
   public int getNTransforms()
   {
      return 4;
   }
}
