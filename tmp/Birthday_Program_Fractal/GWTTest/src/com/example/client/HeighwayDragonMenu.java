package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class HeighwayDragonMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public HeighwayDragonMenu(TextArea codeWindow)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText(
            "M0 <- [ 0.5, -0.5, 0.5,  0.5, 0.0, 0.0, 0.0, 0.5]\n" +
            "M1 <- [-0.5, -0.5, 0.5, -0.5, 1.0, 0.0, 1.0, 0.5]\n");

      initWidget(vPanel);
   }

   @Override
   public int getNTransforms()
   {
      return 2;
   }
}
