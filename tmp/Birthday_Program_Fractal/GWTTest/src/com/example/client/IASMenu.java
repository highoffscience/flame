package com.example.client;

import com.google.gwt.event.dom.client.ChangeEvent;
import com.google.gwt.event.dom.client.ChangeHandler;
import com.google.gwt.user.client.ui.ListBox;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class IASMenu extends SAMenuElement
{
   private VerticalPanel vPanel;
   private ListBox menu;
   private SAMenuElement saElement;
   private TextArea codeWindow;
   private VariationBlendPanel vbPanel;

   public IASMenu(VariationBlendPanel vbPanel)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1); // Coders Without Borders haha

      this.vbPanel = vbPanel;

      this.menu = new ListBox();
      menu.addItem("Polygon Gasket");
      menu.addItem("Heighway Dragon");
      menu.addItem("Maple Leaf");
      menu.addItem("Spiral");
      menu.addItem("Barnsley Fern");
      menu.addChangeHandler(new MenuHandler());

      this.codeWindow = new TextArea();
      codeWindow.setCharacterWidth(40);
      codeWindow.setVisibleLines(10);

      vPanel.add(menu);
      placeNewMenu(new PolygonGasketMenu(codeWindow, vbPanel));

      initWidget(vPanel);
   }

   @Override
   public String getCode()
   {
      String code = "Ias\n\n";
      code += codeWindow.getText();
      code += "\nEnd\n";

      return code;
   }

   @Override
   public int getNTransforms()
   {
      return saElement.getNTransforms();
   }

   private String getText()
   {
      return menu.getSelectedItemText();
   }

   private void removeElementIfNecessary()
   {
      if (vPanel.getWidgetCount() == 3)
      {
         saElement = null;
         vPanel.remove(2);
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
      vPanel.add(saElement);
      vPanel.add(codeWindow);
   }

   private class MenuHandler implements ChangeHandler
   {
      @Override
      public void onChange(ChangeEvent evt)
      {
         if (getText().equals("Polygon Gasket"))
         {
            placeNewMenu(new PolygonGasketMenu(codeWindow, vbPanel));
         }
         else if (getText().equals("Heighway Dragon"))
         {
            placeNewMenu(new HeighwayDragonMenu(codeWindow));
         }
         else if (getText().equals("Maple Leaf"))
         {
            placeNewMenu(new MapleLeafMenu(codeWindow));
         }
         else if (getText().equals("Spiral"))
         {
            placeNewMenu(new SpiralMenu(codeWindow));
         }
         else if (getText().equals("Barnsley Fern"))
         {
            placeNewMenu(new BarnsleyFernMenu(codeWindow));
         }
      }
   }
}
