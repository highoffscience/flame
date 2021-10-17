package com.example.client;

import com.google.gwt.user.client.ui.HasHorizontalAlignment;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.VerticalPanel;

public class PreTransformMenu extends SAMenuElement
{
   private VerticalPanel vPanel;
   private SAMenuElement saElement;

   public PreTransformMenu(VariationBlendPanel vbPanel)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      Label title = new Label("Pre Transform");
      title.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.saElement = new SAMenu(vbPanel);

      vPanel.add(title);
      vPanel.add(saElement);

      initWidget(vPanel);
   }

   @Override
   public String getCode()
   {
      return "Pre " + saElement.getCode();
   }

   @Override
   public int getNTransforms()
   {
      return saElement.getNTransforms();
   }
}
