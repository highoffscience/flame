package com.example.client;

import com.google.gwt.event.dom.client.ChangeEvent;
import com.google.gwt.event.dom.client.ChangeHandler;
import com.google.gwt.user.client.ui.ListBox;
import com.google.gwt.user.client.ui.VerticalPanel;

public class IFSMenu extends SAMenuElement
{
   private VerticalPanel vPanel;
   private ListBox menu;
   private SAMenuElement saElement;
   private VariationBlendPanel vbPanel;

   public IFSMenu(VariationBlendPanel vbPanel)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      this.vbPanel = vbPanel;

      this.menu = new ListBox();
      menu.addItem("Apollonian Gasket");
      menu.addChangeHandler(new MenuHandler());

      vPanel.add(menu);
      placeNewMenu(new ApollonianGasketMenu());

      initWidget(vPanel);
   }

   @Override
   public String getCode()
   {
      if (saElement == null)
      {
         return null;
      }
      else
      {
         return "Ifs\n\n" + saElement.getCode() + "\nEnd\n";
      }
   }

   @Override
   public int getNTransforms()
   {
      if (saElement == null)
      {
         return 0;
      }
      else
      {
         return saElement.getNTransforms();
      }
   }

   private String getText()
   {
      return menu.getSelectedItemText();
   }

   private void removeElementIfNecessary()
   {
      if (vPanel.getWidgetCount() >= 2)
      {
         saElement = null;
         vPanel.remove(1);
      }
   }

   private void placeNewMenu(SAMenuElement saElement)
   {
      removeElementIfNecessary();
      this.saElement = saElement;
      if (vbPanel != null)
      {
         vbPanel.setNTransforms(saElement.getNTransforms());
      }
      vPanel.add(this.saElement);
   }

   private class MenuHandler implements ChangeHandler
   {
      @Override
      public void onChange(ChangeEvent evt)
      {
         if (getText().equals("Apollonian Gasket"))
         {
            placeNewMenu(new ApollonianGasketMenu());
         }
      }
   }
}
