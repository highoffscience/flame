package com.example.client;

import com.google.gwt.user.client.ui.VerticalPanel;

public class ApollonianGasketMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public ApollonianGasketMenu()
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      initWidget(vPanel);
   }

   @Override
   public int getNTransforms()
   {
      return 3;
   }

   @Override
   public String getCode()
   {
      return "";
   }
}
