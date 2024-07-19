#include <TFT_eSPI.h>
// A library for interfacing with LCD displays
//
// Can be installed from the library manager (Search for "TFT_eSPI")
//https://github.com/Bodmer/TFT_eSPI

TFT_eSPI tft = TFT_eSPI();

void setup() {
  // Start the tft display and set it to black
  tft.init();
  tft.setRotation(1); //This is the display in landscape
  
  // Clear the screen before writing to it
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_GREEN);  tft.setTextSize(2);
  tft.println("Hello World!");
  tft.println("Este es mi primer Programa");
  tft.println("");
  tft.println("");
  tft.println("");

  tft.setTextColor(TFT_WHITE);  tft.setTextSize(2);
  tft.println("By Sergio V");
}

void loop() {
  // put your main code here, to run repeatedly:

}
