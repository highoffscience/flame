package com.example.client;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.i18n.client.NumberFormat;
import com.google.gwt.user.client.Window;
import com.google.gwt.user.client.ui.Button;
import com.google.gwt.user.client.ui.HasHorizontalAlignment;
import com.google.gwt.user.client.ui.HorizontalPanel;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.TextBox;
import com.google.gwt.user.client.ui.VerticalPanel;

public class PolygonGasketMenu extends SAMenuElement
{
   private VerticalPanel vPanel;
   private HorizontalPanel nPointsHPanel;
   private HorizontalPanel ratioHPanel;
   private Label nPointsLabel;
   private Label ratioLabel;
   private TextBox nPointsTxtBox;
   private TextBox ratioTxtBox;
   private Button refreshCodeBtn;
   private VariationBlendPanel vbPanel;

   private final TextArea codeWindow;

   public PolygonGasketMenu(TextArea codeWindow, VariationBlendPanel vbPanel)
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      this.vbPanel = vbPanel;

      this.nPointsHPanel = new HorizontalPanel();
      nPointsHPanel.setBorderWidth(1);

      this.nPointsLabel = new Label("Number of Vertices");
      this.nPointsLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.nPointsTxtBox = new TextBox();
      nPointsTxtBox.setVisibleLength(5);
      nPointsTxtBox.setText("3");

      nPointsHPanel.add(nPointsLabel);
      nPointsHPanel.add(nPointsTxtBox);

      this.ratioHPanel = new HorizontalPanel();
      ratioHPanel.setBorderWidth(1);

      this.ratioLabel = new Label("Ratio");
      this.ratioLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.ratioTxtBox = new TextBox();
      ratioTxtBox.setVisibleLength(5);
      ratioTxtBox.setText("0.5");

      ratioHPanel.add(ratioLabel);
      ratioHPanel.add(ratioTxtBox);

      this.refreshCodeBtn = new Button("Refresh Code");
      refreshCodeBtn.addClickHandler(new ClickHandler() {
         @Override
         public void onClick(ClickEvent evt) {
            refresh();
         }
      });

      vPanel.add(nPointsHPanel);
      vPanel.add(ratioHPanel);
      vPanel.add(refreshCodeBtn);

      this.codeWindow = codeWindow;
      refresh();

      initWidget(vPanel);
   }

   @Override
   public void refresh()
   {
      codeWindow.setText(getCodeAsText());
      if (vbPanel != null)
      {
         vbPanel.setNTransforms(getNTransforms());
      }
   }

   @Override
   public int getNTransforms()
   {
      return getNPoints();
   }

   private String getCodeAsText()
   {
      double ratio    = getRatio();
      int    nPoints  = getNPoints();
      double interval = Math.PI * 2.0 / nPoints;
      double prob     = 1.0 / nPoints;

      String code = "";

      for (int i = 0; i < nPoints; ++i)
      {
         double x = Math.sin(i * interval); // x is sin, y is cos is correct
         double y = Math.cos(i * interval);

         code += "M" + String.valueOf(i) + " <- [" +
                 formatDouble(ratio) + ", " +
                 "0, " +
                 "0, " +
                 formatDouble(ratio) + ", " +
                 formatDouble(x * ratio) + ", " +
                 formatDouble(y * ratio) + ", " +
                 formatDouble(i / (nPoints - 1.0)) + ", " +
                 formatDouble(prob) +
                 "]\n";
      }

      return code;
   }

   private String formatDouble(double d)
   {
      return NumberFormat.getFormat("##0.0###########").format(d);
   }

   private double getRatio()
   {
      double ratio = 0.5; // default value

      try
      {
         ratio = Double.parseDouble(ratioTxtBox.getText());

         if (!(ratio > 0.0 && ratio < 1.0))
         {
            Window.alert("Ratio must be greater than 0 and less than 1\n" +
                         "Setting to default of 0.5\n" +
                         "Entered " + ratioTxtBox.getText());

            ratio = 0.5;
            ratioTxtBox.setText("0.5");
         }
      }
      catch (NumberFormatException exc)
      {
         Window.alert("Ratio must be a valid number greater than 0 and less than 1\n" +
                      "Setting to default of 0.5\n" +
                      "Entered " + ratioTxtBox.getText());

         ratio = 0.5;
         ratioTxtBox.setText("0.5");
      }

      return ratio;
   }

   private int getNPoints()
   {
      int nPoints = 3; // default value

      try
      {
         nPoints = Integer.parseInt(nPointsTxtBox.getText());

         if (nPoints < 3 || nPoints > 100)
         {
            Window.alert("Number of points must be at least 3 and at most 100\n" +
                         "Setting to default of 3\n" +
                         "Entered " + nPointsTxtBox.getText());

            nPoints = 3;
            nPointsTxtBox.setText("3");
         }
      }
      catch (NumberFormatException exc)
      {
         Window.alert("Number of points must be at least 3 and at most 100\n" +
                      "Setting to default of 3\n" +
                      "Entered = " + nPointsTxtBox.getText());

         nPoints = 3;
         nPointsTxtBox.setText("3");
      }

      return nPoints;
   }
}
