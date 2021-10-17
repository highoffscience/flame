package com.example.client;

import com.google.gwt.event.dom.client.ChangeEvent;
import com.google.gwt.event.dom.client.ChangeHandler;
import com.google.gwt.user.client.ui.HasHorizontalAlignment;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.ListBox;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class ColorSchemePanel extends SAMenuElement
{
   private VerticalPanel vPanel;
   private ListBox menu;
   //private SAMenuElement saElement;
   private TextArea codeWindow;

   public ColorSchemePanel()
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      Label title = new Label("Color Scheme");
      title.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.menu = new ListBox();
      menu.addItem("Uniform");
      menu.addItem("Shade");
      menu.addItem("Spectrum");
      menu.addChangeHandler(new MenuHandler());

      this.codeWindow = new TextArea();
      codeWindow.setCharacterWidth(30);
      codeWindow.setVisibleLines(10);

      vPanel.add(title);
      vPanel.add(menu);
      placeNewMenu(new UniformMenu(codeWindow));

      initWidget(vPanel);
   }

   @Override
   public String getCode()
   {
      return codeWindow.getText();
   }

   private String getText()
   {
      return menu.getSelectedItemText();
   }

   private void removeElementIfNecessary()
   {
      if (vPanel.getWidgetCount() == 4)
      {
         //saElement = null;
         vPanel.remove(3);
         vPanel.remove(2);
      }
   }

   private void placeNewMenu(SAMenuElement saElement)
   {
      removeElementIfNecessary();
      vPanel.add(saElement);
      vPanel.add(codeWindow);
      //this.saElement = saElement;
   }

   private class MenuHandler implements ChangeHandler
   {
      @Override
      public void onChange(ChangeEvent evt)
      {
         if (getText().equals("Uniform"))
         {
            placeNewMenu(new UniformMenu(codeWindow));
         }
         else if (getText().equals("Shade"))
         {
            placeNewMenu(new ShadeMenu(codeWindow));
         }
         else if (getText().equals("Spectrum"))
         {
            placeNewMenu(new SpectrumMenu(codeWindow));
         }
      }
   }
}
