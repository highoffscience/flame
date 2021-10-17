package com.example.client;

import com.google.gwt.core.client.EntryPoint;
import com.google.gwt.event.dom.client.ClickEvent;
import com.google.gwt.event.dom.client.ClickHandler;
import com.google.gwt.http.client.Request;
import com.google.gwt.http.client.RequestBuilder;
import com.google.gwt.http.client.RequestCallback;
import com.google.gwt.http.client.RequestException;
import com.google.gwt.http.client.Response;
import com.google.gwt.http.client.URL;
import com.google.gwt.user.client.Window;
import com.google.gwt.user.client.ui.HorizontalPanel;
import com.google.gwt.user.client.ui.Image;
import com.google.gwt.user.client.ui.Label;
import com.google.gwt.user.client.ui.RootPanel;
import com.google.gwt.user.client.ui.SubmitButton;
import com.google.gwt.user.client.ui.VerticalPanel;

/**
 * Entry point classes define <code>onModuleLoad()</code>.
 */
public class GWTTest implements EntryPoint
{
  /**
   * This is the entry point method.
   */
   @Override
   public void onModuleLoad()
   {
      final VerticalPanel vPanel = new VerticalPanel();
      vPanel.setBorderWidth(1);

      HorizontalPanel toolbarPanel = new HorizontalPanel();
      toolbarPanel.setBorderWidth(1);

      final VariationBlendPanel vbPanel  = new VariationBlendPanel();
      final PreTransformMenu    preMenu  = new PreTransformMenu(vbPanel);
      final PostTransformMenu   postMenu = new PostTransformMenu();
      final FitterPanel         fitPanel = new FitterPanel();
      final ColorSchemePanel    csPanel  = new ColorSchemePanel();
      final FlamePanel          faPanel  = new FlamePanel();

      toolbarPanel.add(faPanel);
      toolbarPanel.add(preMenu);
      toolbarPanel.add(postMenu);
      toolbarPanel.add(fitPanel);
      toolbarPanel.add(csPanel);
      toolbarPanel.add(vbPanel);

      final SubmitButton submit = new SubmitButton("Submit");
      final Label genLabel      = new Label("");

      submit.addClickHandler(new ClickHandler() {
         @Override
         public void onClick(ClickEvent evt) {
            String xmlCode = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
            xmlCode += "<root>\n";
            xmlCode += assembleSAXML(preMenu, postMenu);
            xmlCode += assembleFTXML(fitPanel, faPanel);
            xmlCode += assembleVBXML(vbPanel);
            xmlCode += assembleCSXML(csPanel);
            xmlCode += assembleFAXML(faPanel);
            xmlCode += assembleRCXML(faPanel);
            xmlCode += "</root>";

            genLabel.setText("> Generating...");
            RequestBuilder builder = new RequestBuilder(RequestBuilder.POST, URL.encode("./Fractal.php"));
            builder.setHeader("Content-Type", "text/xml");
            try
            {
               builder.sendRequest(xmlCode, new RequestCallback() {
                  @Override
                  public void onError(Request request, Throwable exc) {
                     Window.alert("onError");
                  }
                  @Override
                  public void onResponseReceived(Request request, Response response) {
                     if (vPanel.getWidgetCount() > 2)
                     {
                        vPanel.remove(2);
                     }

                     String responseStr = response.getText();

                     if (responseStr.startsWith("-1"))
                     {
                        // this data is also record on the server log php.log
                        genLabel.setText("");
                        Window.alert("Uh oh!\n" + responseStr);
                     }
                     else
                     {
                        String[] data = responseStr.split(" ");
                        Image img = new Image(data[0]);
                        if (fitPanel.isAutoFit())
                        {
                           fitPanel.setScaleX(data[2]);
                           fitPanel.setScaleY(data[3]);
                           fitPanel.setTransX(data[4]);
                           fitPanel.setTransY(data[5]);
                        }
                        img.setPixelSize(Integer.valueOf(faPanel.getWidth()),
                                         Integer.valueOf(faPanel.getHeight()));
                        vPanel.add(img);
                        genLabel.setText("> Generation time: " + data[1] + " (s)");
                     }
                  }
               });
            }
            catch (RequestException exc)
            {
               Window.alert("exception");
            }
         }
      });

      HorizontalPanel imgGenSpecsHPanel = new HorizontalPanel();
      imgGenSpecsHPanel.add(submit);
      imgGenSpecsHPanel.add(genLabel);

      vPanel.add(toolbarPanel);
      vPanel.add(imgGenSpecsHPanel);

      RootPanel.get().add(vPanel);
   }

   private String xmlize(String code)
   {
      return code.replace("<-", "&lt;-");
   }

   private String xmlize(SAMenuElement menuElement)
   {
      return xmlize(menuElement.getCode());
   }

   public String assembleSAXML(PreTransformMenu preMenu, PostTransformMenu postMenu)
   {
      return "<sa>\n\n" +
             xmlize(preMenu) + "\n" +
             xmlize(postMenu) +
             "\n</sa>\n";
   }

   public String assembleFTXML(FitterPanel fitPanel, FlamePanel faPanel)
   {
      return "<ft>\n\n" +
             xmlize(fitPanel) +
             xmlize(faPanel.getWidthAndHeightCode()) +
             "\n</ft>\n";
   }

   public String assembleVBXML(VariationBlendPanel vbPanel)
   {
      return "<vb>\n\n" +
             xmlize(vbPanel) +
             "\n</vb>\n";
   }

   public String assembleCSXML(ColorSchemePanel csPanel)
   {
      return "<cs>\n\n" +
             xmlize(csPanel) +
             "\n</cs>\n";
   }

   public String assembleFAXML(FlamePanel faPanel)
   {
      return "<fa>\n\n" +
             xmlize(faPanel) +
             xmlize(faPanel.getWidthAndHeightCode()) +
             "\n</fa>\n";
   }

   public String assembleRCXML(FlamePanel faPanel)
   {
      return "<rc>\n\n" +
             xmlize(faPanel.getWidthAndHeightCode()) +
             "\n</rc>\n";
   }
}
