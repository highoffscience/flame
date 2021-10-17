package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class ShadeMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public ShadeMenu(TextArea codeWindow)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText("shade <- [1.0, 1.0, 1.0]\n" +
                         "Return shade * Color\n");

      initWidget(vPanel);
   }
}
