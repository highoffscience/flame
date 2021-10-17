package com.example.client;

import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class UniformMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public UniformMenu(TextArea codeWindow)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      codeWindow.setText("Return [1.0, 1.0, 1.0]");

      initWidget(vPanel);
   }
}
