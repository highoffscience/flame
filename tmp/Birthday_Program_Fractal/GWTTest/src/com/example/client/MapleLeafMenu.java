package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class MapleLeafMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public MapleLeafMenu(TextArea codeWindow)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText(
            "M0 <- [ 0.14,  0.01,  0.0 , 0.51, -0.08, -1.31, 0.0/3.0, 0.25 ]\n" +
            "M1 <- [ 0.43,  0.52, -0.45, 0.5 ,  1.49, -0.75, 1.0/3.0, 0.25 ]\n" +
            "M2 <- [ 0.45, -0.49,  0.47, 0.47, -1.62, -0.74, 2.0/3.0, 0.25 ]\n" +
            "M3 <- [ 0.49,  0.0 ,  0.0 , 0.51,  0.02,  1.62, 3.0/3.0, 0.25 ]\n");

      initWidget(vPanel);
   }

   @Override
   public int getNTransforms()
   {
      return 4;
   }
}
