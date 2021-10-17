package com.example.client;

import com.google.gwt.user.client.ui.HasHorizontalAlignment;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.VerticalPanel;

public class PostTransformMenu extends SAMenuElement
{
   private VerticalPanel vPanel;
   private SAMenuElement saElement;

   public PostTransformMenu()
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      Label title = new Label("Post Transform");
      title.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.saElement = new SAMenu("Null", null);

      vPanel.add(title);
      vPanel.add(saElement);

      initWidget(vPanel);
   }

   @Override
   public String getCode()
   {
      return "Post " + saElement.getCode();
   }

   @Override
   public int getNTransforms()
   {
      return saElement.getNTransforms();
   }
}
