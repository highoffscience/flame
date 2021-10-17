package com.example.client;

import com.google.gwt.user.client.Window;
import com.google.gwt.user.client.ui.Grid;
import com.google.gwt.user.client.ui.HasHorizontalAlignment;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.TextArea;
import com.google.gwt.user.client.ui.TextBox;
import com.google.gwt.user.client.ui.VerticalPanel;

public class FlamePanel extends SAMenuElement
{
   private VerticalPanel vPanel;

   private TextBox widthTxtBox, heightTxtBox;
   //private TextBox gammaTxtBox, nitersTxtBox;

   private Grid layout;

   private TextArea codeWindow;
   //private Button   refreshCodeBtn;

   public FlamePanel()
   {
      this.vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      Label title = new Label("Flame Panel");
      title.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.widthTxtBox  = new TextBox();
      this.heightTxtBox = new TextBox();
      //this.gammaTxtBox  = new TextBox();
      //this.nitersTxtBox = new TextBox();

      widthTxtBox .setVisibleLength(5);
      heightTxtBox.setVisibleLength(5);
      //gammaTxtBox .setVisibleLength(5);
      //nitersTxtBox.setVisibleLength(5);

      widthTxtBox .setText("960");
      heightTxtBox.setText("540");
      //gammaTxtBox .setText("4.0");
      //nitersTxtBox.setText("10000000");

      Label wLabel = new Label("Width");
      Label hLabel = new Label("Height");
      //Label gLabel = new Label("Gamma");
      //Label iLabel = new Label("# Iterations");

      wLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);
      hLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);
      //gLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);
      //iLabel.setHorizontalAlignment(HasHorizontalAlignment.ALIGN_CENTER);

      this.layout = new Grid(2, 2);
      //layout.setBorderWidth(1);

      layout.setWidget(0, 0, wLabel);
      layout.setWidget(1, 0, hLabel);
      //layout.setWidget(2, 0, gLabel);
      //layout.setWidget(3, 0, iLabel);
      layout.setWidget(0, 1, widthTxtBox );
      layout.setWidget(1, 1, heightTxtBox);
      //layout.setWidget(2, 1, gammaTxtBox );
      //layout.setWidget(3, 1, nitersTxtBox);

      //this.refreshCodeBtn = new Button("Refresh Code");
      //refreshCodeBtn.addClickHandler(new ClickHandler() {
      //   @Override
      //   public void onClick(ClickEvent evt) {
      //      refresh();
      //   }
      //});

      this.codeWindow = new TextArea();
      codeWindow.setCharacterWidth(20);
      codeWindow.setVisibleLines(10);
      codeWindow.setText(
            "Gamma  <- 4.0\n" +
            "NIters <- 10000000\n");

      //refresh(); // sets codeWindow text

      vPanel.add(title);
      vPanel.add(layout);
      //vPanel.add(refreshCodeBtn);
      vPanel.add(codeWindow);

      initWidget(vPanel);
   }

   //@Override
   //public void refresh()
   //{
   //   codeWindow.setText(getCodeAsText());
   //}

   //private String getCodeAsText()
   //{
   //   return "Width  <- " + getWidth () + "\n" +
   //          "Height <- " + getHeight() + "\n" +
   //          "Gamma  <- " + getGamma () + "\n" +
   //          "NIters <- " + getNIters() + "\n";
   //}

   public String getWidthAndHeightCode()
   {
      return "Width  <- " + getWidth () + "\n" +
             "Height <- " + getHeight() + "\n";
   }

   @Override
   public String getCode()
   {
      return codeWindow.getText();
   }

   public String getWidth()
   {
      try
      {
         int value = Integer.parseInt(widthTxtBox.getText());

         if (value < 16 || value > 3840)
         {
            Window.alert("Width must be greater than or equal to 16 and less than or equal to 3840\n" +
                         "Entered " + widthTxtBox.getText());

            widthTxtBox.setText("960");
         }
      }
      catch (NumberFormatException exc)
      {
         Window.alert("Width must be greater than or equal to 16 and less than or equal to 3840\n" +
                      "Entered " + widthTxtBox.getText());

         widthTxtBox.setText("960");
      }

      return widthTxtBox.getText();
   }

   public String getHeight()
   {
      try
      {
         int value = Integer.parseInt(heightTxtBox.getText());

         if (value < 16 || value > 2160)
         {
            Window.alert("Height must be greater than or equal to 16 and less than or equal to 2160\n" +
                         "Entered " + heightTxtBox.getText());

            heightTxtBox.setText("540");
         }
      }
      catch (NumberFormatException exc)
      {
         Window.alert("Height must be greater than or equal to 16 and less than or equal to 3840\n" +
                      "Entered " + heightTxtBox.getText());

         heightTxtBox.setText("540");
      }

      return heightTxtBox.getText();
   }

   //private String getGamma()
   //{
   //   try
   //   {
   //      double value = Double.parseDouble(gammaTxtBox.getText());
   //
   //      if (value <= 0.0 || value > 100)
   //      {
   //         Window.alert("Gamma must be greater than 0 and less than or equal to 100\n" +
   //                      "Entered " + gammaTxtBox.getText());
   //
   //         gammaTxtBox.setText("4.0");
   //      }
   //   }
   //   catch (NumberFormatException exc)
   //   {
   //      Window.alert("Gamma must be greater than 0 and less than or equal to 100\n" +
   //                   "Entered " + gammaTxtBox.getText());
   //
   //      gammaTxtBox.setText("4.0");
   //   }
   //
   //   return gammaTxtBox.getText();
   //}
   //
   //private String getNIters()
   //{
   //   try
   //   {
   //      long value = Long.parseLong(nitersTxtBox.getText());
   //
   //      if (value <= 0.0)
   //      {
   //         Window.alert("# Iterations must be greater than 0\n" +
   //                      "Entered " + nitersTxtBox.getText());
   //
   //         nitersTxtBox.setText("10000000");
   //      }
   //   }
   //   catch (NumberFormatException exc)
   //   {
   //      Window.alert("# Iterations must be greater than 0\n" +
   //                   "Entered " + nitersTxtBox.getText());
   //
   //      nitersTxtBox.setText("10000000");
   //   }
   //
   //   return nitersTxtBox.getText();
   //}
}
