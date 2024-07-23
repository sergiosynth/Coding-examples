#include <TFT_eSPI.h>
#include <WiFi.h>
#include <Wire.h>
#include <HTTPClient.h>
#include <NTPClient.h> 
#include <WiFiUdp.h>
#include "secrets.h" // WiFi Configuration (WiFi name and Password)
#include <ArduinoJson.h>

TFT_eSPI tft = TFT_eSPI();


//INTERNET SETUP, BE CAREFUL SHARING THIS STUFF
const char* ssid = "INFINITUM7A8B";
const char* password = "NmdXSCSQX7";

//const int httpsPort = 443;
// Powered by CoinDesk - https://www.coindesk.com/price/bitcoin
const String url = "http://api.coindesk.com/v1/bpi/currentprice/BTC.json";
const String historyURL = "http://api.coindesk.com/v1/bpi/historical/close.json";
const String cryptoCode = "BTC";




WiFiClient client;
HTTPClient http;
String lastPrice;

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;


void setup() {
  // Start the tft display and set it to black
  tft.init();
  tft.setRotation(1); //This is the display in landscape
  
  // Clear the screen before writing to it
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_GREEN);  tft.setTextSize(2);
  tft.println("BITCOIN PRICE TRACKER");
  tft.println("version 1.0");
  
  tft.setTextColor(TFT_WHITE);  tft.setTextSize(1);
  tft.println("");
  tft.println("By Sergio V / VEMS systems");
  

  tft.setTextSize(1);
  tft.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);
  

  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    tft.print(".");
  }
  Serial.print("CONNECTED to SSID: ");
  Serial.print(ssid);
 

  tft.print("Connected to: ");
  tft.print(ssid);
  tft.print("");
  delay(4000);
  tft.fillScreen(TFT_BLACK); //Este comando limpia la pantalla
  tft.print("");
}



void loop() {
  Serial.print("Connecting to ");
  Serial.println(url);

  http.begin(url);
  int httpCode = http.GET();
  StaticJsonDocument<768> doc;
  DeserializationError error = deserializeJson(doc, http.getString());

  if (error) {
    tft.print(F("deserializeJson Failed"));
    tft.print(error.f_str());
    delay(2500);
    return;}
   

  Serial.print("History HTTP Status Code: ");
  Serial.println(httpCode);
  

  String BTCUSDPrice = doc["bpi"]["USD"]["rate_float"].as<String>();
      /*if(BTCUSDPrice == lastPrice) {
        Serial.print("Price hasn't changed (Current/Last): ");
        Serial.print(BTCUSDPrice);
        Serial.print(" : ");
        Serial.println(lastPrice);
        delay(100);//default 1250
        return;
      } else {
        lastPrice = BTCUSDPrice;
      }
      String lastUpdated = doc["time"]["updated"].as<String>();
      http.end();*/

// Todo bien hasta aquí

      /*Serial.println("Getting history...");
      StaticJsonDocument<1536> historyDoc;
      http.begin(historyURL);
      int historyHttpCode = http.GET();
      DeserializationError historyError = deserializeJson(historyDoc, http.getString());

      if (historyError) {
        Serial.print(F("deserializeJson(History) failed: "));
        Serial.println(historyError.f_str());
        delay(2500);
        return;
      }*/


  tft.fillScreen(TFT_BLACK); //Este comando limpia la pantalla
  tft.setTextColor(TFT_WHITE);  tft.setTextSize(1);
  //tft.println("Online");
  //tft.println(ssid);
  tft.setTextColor(TFT_GREEN);  tft.setTextSize(4);
  tft.drawString("BTCUSD PRICE", 20, 75);
  tft.drawString("$" + BTCUSDPrice, 30, 125);
  //tft.println(BTCUSDPrice);

  delay(2000);//Tiempo del loop, default =1250

}
