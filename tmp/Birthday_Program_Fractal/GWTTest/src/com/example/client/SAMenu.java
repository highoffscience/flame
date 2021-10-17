package com.example.client;

import com.google.gwt.event.dom.client.ChangeEvent;
import com.google.gwt.event.dom.client.ChangeHandler;
import com.google.gwt.user.client.ui.ListBox;
import com.google.gwt.user.client.ui.VerticalPanel;

public class SAMenu extends SAMenuElement
{
   private VerticalPanel vPanel;
   private ListBox menu;
   private SAMenuElement saElement;
   private VariationBlendPanel vbPanel;

   public SAMenu(VariationBlendPanel vbPanel)
   {
      this("Iterated Affine System", vbPanel);
   }

   public SAMenu(String txt, VariationBlendPanel vbPanel)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      this.vbPanel = vbPanel;

      this.menu = new ListBox();
      menu.addItem("Iterated Affine System");
      menu.addItem("Iterated Function System");
      menu.addItem("Null");
      menu.addChangeHandler(new MenuHandler());

      vPanel.add(menu);

      setSelectedMenuItem(menu, txt);

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
         return saElement.getCode();
      }
   }

   private void setSelectedMenuItem(ListBox menu, String value)
   {
      int index = 0;

      for (int i = 0; i < menu.getItemCount(); ++i)
      {
         if (menu.getItemText(i).equals(value))
         {
            index = i;
            break;
         }
      }

      menu.setItemSelected(index, true);
      selectMenu(value);
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
      vPanel.add(this.saElement);
   }

   private class MenuHandler implements ChangeHandler
   {
      @Override
      public void onChange(ChangeEvent evt)
      {
         selectMenu(getText());
      }
   }

   private void selectMenu(String txt)
   {
      if (txt.equals("Iterated Affine System"))
      {
         placeNewMenu(new IASMenu(vbPanel));
      }
      else if (txt.equals("Iterated Function System"))
      {
         placeNewMenu(new IFSMenu(vbPanel));
      }
      else if (txt.equals("Null"))
      {
         placeNewMenu(new NullSAMenu(vbPanel));
      }
   }
}
