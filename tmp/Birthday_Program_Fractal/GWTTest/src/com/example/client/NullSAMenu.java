package com.example.client;

import com.google.gwt.user.client.ui.VerticalPanel;

public class NullSAMenu extends SAMenuElement
{
   private VerticalPanel vPanel;

   public NullSAMenu(VariationBlendPanel vbPanel)
   {
      this.vPanel = new VerticalPanel();

      if (vbPanel != null)
      {
         vbPanel.setNTransforms(0);
      }

      initWidget(vPanel);
   }

   @Override
   public String getCode()
   {
      return "None\n\nEnd\n";
   }
}
