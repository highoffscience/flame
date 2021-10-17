package com.example.client;

import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.i18n.client.NumberFormat;
import com.google.gwt.user.client.Window;
import com.google.gwt.user.client.ui.Button;
import com.google.gwt.user.client.ui.CheckBox;
import com.google.gwt.user.client.ui.Grid;
import com.google.gwt.user.client.ui.HasHorizontalAlignment;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.TextBox;
import com.google.gwt.user.client.ui.VerticalPanel;

public class FitterPanel extends SAMenuElement
{
   private VerticalPanel vPanel;

   private CheckBox autoFit;

   private TextBox scaleXTxtBox, scaleYTxtBox;
   private TextBox transXTxtBox, transYTxtBox;

   private Grid layout;

   private TextArea codeWindow;
   private Button   refreshCodeBtn;

   public FitterPanel()
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      autoFit = new CheckBox("Auto-Fit");
      autoFit.setValue(true);

      Label title = new Label("Fitting Panel");
      title.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.scaleXTxtBox = new TextBox();
      this.scaleYTxtBox = new TextBox();
      this.transXTxtBox = new TextBox();
      this.transYTxtBox = new TextBox();

      scaleXTxtBox.setVisibleLength(5);
      scaleYTxtBox.setVisibleLength(5);
      transXTxtBox.setVisibleLength(5);
      transYTxtBox.setVisibleLength(5);

      scaleXTxtBox.setText("1.0");
      scaleYTxtBox.setText("1.0");
      transXTxtBox.setText("0.0");
      transYTxtBox.setText("0.0");

      Label xLabel = new Label("X");
      Label yLabel = new Label("Y");
      Label sLabel = new Label("Scale");
      Label tLabel = new Label("Translation");

      xLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);
      yLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);
      sLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);
      tLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.layout = new Grid(3, 3);
      //layout.setBorderWidth(1);

      layout.setWidget(0, 1, xLabel);
      layout.setWidget(0, 2, yLabel);
      layout.setWidget(1, 0, sLabel);
      layout.setWidget(2, 0, tLabel);
      layout.setWidget(1, 1, scaleXTxtBox);
      layout.setWidget(1, 2, scaleYTxtBox);
      layout.setWidget(2, 1, transXTxtBox);
      layout.setWidget(2, 2, transYTxtBox);

      this.refreshCodeBtn = new Button("Refresh Code");
      refreshCodeBtn.addClickHandler(new ClickHandler() {
         @Override
         public void onClick(ClickEvent evt) {
            refresh();
         }
      });

      this.codeWindow = new TextArea();
      codeWindow.setCharacterWidth(30);
      codeWindow.setVisibleLines(10);

      refresh(); // sets codeWindow text

      vPanel.add(title);
      vPanel.add(autoFit);
      vPanel.add(layout);
      vPanel.add(refreshCodeBtn);
      vPanel.add(codeWindow);

      initWidget(vPanel);
   }

   private String formatDouble(double d)
   {
      return NumberFormat.getFormat("##0.0###").format(d);
   }

   private void updateIfNot0(TextBox txtBox, String value)
   {
      if (!"0".equals(value))
      {
         txtBox.setText(formatDouble(Double.parseDouble(value)));
      }
   }

   public void setScaleX(String value) { updateIfNot0(scaleXTxtBox, value); }
   public void setScaleY(String value) { updateIfNot0(scaleYTxtBox, value); }
   public void setTransX(String value) { updateIfNot0(transXTxtBox, value); }
   public void setTransY(String value) { updateIfNot0(transYTxtBox, value); }

   @Override
   public void refresh()
   {
      codeWindow.setText(getCodeAsText());
   }

   private String getCodeAsText()
   {
      String code = "";

      if (isAutoFit())
      {
         code += "Auto On\n\n";
      }
      else
      {
         code += "Auto Off\n\n";
      }

      code += "// Following is ignored if auto mode is On\n" +
              "\n";

      code += "Scale <- [" + getScaleX() + ", " + getScaleY() + "]\n";
      code += "Trans <- [" + getTransX() + ", " + getTransY() + "]\n";

      return code;
   }

   @Override
   public String getCode()
   {
      return codeWindow.getText();
   }

   public boolean isAutoFit() { return autoFit.getValue(); }

   private String getScaleX()
   {
      try
      {
         double value = Double.parseDouble(scaleXTxtBox.getText());

         if (value <= 0.0)
         {
            Window.alert("X Scale must be greater than 0.\n" +
                         "Entered " + scaleXTxtBox.getText());

            scaleXTxtBox.setText("1.0");
         }
      }
      catch (NumberFormatException exc)
      {
         Window.alert("X Scale must be greater than 0.\n" +
                      "Entered " + scaleXTxtBox.getText());

         scaleXTxtBox.setText("1.0");
      }

      return scaleXTxtBox.getText();
   }

   private String getScaleY()
   {
      try
      {
         double value = Double.parseDouble(scaleYTxtBox.getText());

         if (value <= 0.0)
         {
            Window.alert("Y Scale must be greater than 0.\n" +
                         "Entered " + scaleYTxtBox.getText());

            scaleYTxtBox.setText("1.0");
         }
      }
      catch (NumberFormatException exc)
      {
         Window.alert("Y Scale must be greater than 0.\n" +
                      "Entered " + scaleYTxtBox.getText());

         scaleYTxtBox.setText("1.0");
      }

      return scaleYTxtBox.getText();
   }

   private String getTransX()
   {
      try
      {
         Double.parseDouble(transXTxtBox.getText());
      }
      catch (NumberFormatException exc)
      {
         Window.alert("X Trans must be greater than 0.\n" +
                      "Entered " + transXTxtBox.getText());

         transXTxtBox.setText("0.0");
      }

      return transXTxtBox.getText();
   }

   private String getTransY()
   {
      try
      {
         Double.parseDouble(transYTxtBox.getText());
      }
      catch (NumberFormatException exc)
      {
         Window.alert("Y Trans must be greater than 0.\n" +
                      "Entered " + transYTxtBox.getText());

         transYTxtBox.setText("0.0");
      }

      return transYTxtBox.getText();
   }
}
