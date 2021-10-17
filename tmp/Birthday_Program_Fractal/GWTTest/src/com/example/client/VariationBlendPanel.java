package com.example.client;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.user.client.ui.Button;
import com.google.gwt.user.client.ui.HasHorizontalAlignment;
import com.google.gwt.user.client.ui.HorizontalPanel;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.ListBox;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.VerticalPanel;

public class VariationBlendPanel extends SAMenuElement
{
   private VerticalPanel vPanel;
   private ListBox menu;
   private TextArea codeWindow;
   private Label nXformsLabel;
   private int nTransforms;
   private HorizontalPanel hPanel;
   private Button addBtn;
   private Button resetBtn;

   public VariationBlendPanel()
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      Label title = new Label("Variation Blend");
      title.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.addBtn = new Button("Add");
      addBtn.addClickHandler(new AddHandler());

      this.resetBtn = new Button("Reset");
      resetBtn.addClickHandler(new ResetHandler());

      this.menu = new ListBox();
      menu.addItem("Linear");
      menu.addItem("Sinusoidal");
      menu.addItem("Spherical");
      menu.addItem("Swirl");
      menu.addItem("Horseshoe");
      menu.addItem("Polar");
      menu.addItem("Handkerchief");
      menu.addItem("Heart");
      menu.addItem("Disc");
      menu.addItem("Spiral");
      menu.addItem("Hyperbolic");
      menu.addItem("Diamond");
      menu.addItem("Ex");

      this.hPanel = new HorizontalPanel();
      hPanel.add(menu);
      hPanel.add(addBtn);
      hPanel.add(resetBtn);

      this.nXformsLabel = new Label();
      setNTransforms(0); // will be overwritten

      this.codeWindow = new TextArea();
      codeWindow.setCharacterWidth(30);
      codeWindow.setVisibleLines(10);

      vPanel.add(title);
      vPanel.add(nXformsLabel);
      vPanel.add(hPanel);
      placeNewMenu(new LinearMenu(codeWindow, 3)); // TODO 3 is a cheat, we are assuming this

      initWidget(vPanel);
   }

   public void setNTransforms(int nTransforms)
   {
      this.nTransforms = nTransforms;
      nXformsLabel.setText("Number of transforms is " + nTransforms);
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
      if (vPanel.getWidgetCount() == 5)
      {
         vPanel.remove(4);
         vPanel.remove(3);
      }
   }

   private void placeNewMenu(SAMenuElement saElement)
   {
      removeElementIfNecessary();
      vPanel.add(saElement);
      vPanel.add(codeWindow);
   }

   private class ResetHandler implements ClickHandler
   {
      @Override
      public void onClick(ClickEvent evt)
      {
         if (getText().equals("Linear"))
         {
            placeNewMenu(new LinearMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Sinusoidal"))
         {
            placeNewMenu(new SinusoidalMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Spherical"))
         {
            placeNewMenu(new SphericalMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Swirl"))
         {
            placeNewMenu(new SwirlMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Horseshoe"))
         {
            placeNewMenu(new HorseshoeMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Polar"))
         {
            placeNewMenu(new PolarMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Handkerchief"))
         {
            placeNewMenu(new HandkerchiefMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Heart"))
         {
            placeNewMenu(new HeartMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Disc"))
         {
            placeNewMenu(new DiscMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Spiral"))
         {
            placeNewMenu(new SpiralVarMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Hyperbolic"))
         {
            placeNewMenu(new HyperbolicMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Diamond"))
         {
            placeNewMenu(new DiamondMenu(codeWindow, nTransforms));
         }
         else if (getText().equals("Ex"))
         {
            placeNewMenu(new ExMenu(codeWindow, nTransforms));
         }
      }
   }

   private class AddHandler implements ClickHandler
   {
      @Override
      public void onClick(ClickEvent evt)
      {
         if (getText().equals("Linear"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + LinearMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Sinusoidal"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + SinusoidalMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Spherical"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + SphericalMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Swirl"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + SwirlMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Horseshoe"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + HorseshoeMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Polar"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + PolarMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Handkerchief"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + HandkerchiefMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Heart"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + HeartMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Disc"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + DiscMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Spiral"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + SpiralVarMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Hyperbolic"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + HyperbolicMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Diamond"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + DiamondMenu.getCodeBody(nTransforms));
         }
         else if (getText().equals("Ex"))
         {
            codeWindow.setText(codeWindow.getText() + "\n" + ExMenu.getCodeBody(nTransforms));
         }
      }
   }
}
