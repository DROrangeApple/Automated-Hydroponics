  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////
  ////   _   _           _                             _            ////
  ////  | | | |         | |                           (_)           ////
  ////  | |_| |_   _  __| |_ __ ___  _ __   ___  _ __  _  ___ ___   ////
  ////  |  _  | | | |/ _` | '__/ _ \| '_ \ / _ \| '_ \| |/ __/ __|  ////
  ////  | | | | |_| | (_| | | | (_) | |_) | (_) | | | | | (__\__ \  ////
  ////  \_| |_/\__, |\__,_|_|  \___/| .__/ \___/|_| |_|_|\___|___/  ////
  ////          __/ |               | |                             ////
  ////         |___/                |_|         By Build It         ////
  ////                                                              ////
  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////

// Libraries
#include <ESP8266WiFi.h>
#include <aREST.h>
aREST rest = aREST();
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include "wifilogo.h"

SSD1306Wire  display(0x3c, D2, D1);  //D2=SDK  D1=SCK  As per labeling on NodeMCU

// WIFI Params
const char* ssid = "Build It Hydro";
const char* password = "buildithydro";

// Pinout
const int WaterPumpPin = 15; //D8
const int AirPumpPin = 13; //D7
const int LightPin = 14; //D5
const int FanPin = 2; //D4
const int ExtraPin = 0; //D3
const int StatusPin = 12; //D6

// Defines
#define LISTEN_PORT           80
WiFiServer server(LISTEN_PORT);

//aRest Function Setup
int SetWaterPumpPWM(String command);
int SetAirPumpPWM(String command1);
int SetLightPumpPWM(String command2);
int SetFanPumpPWM(String command3);
int SetExtraPWM(String command4);



void setup(void)
{
  Serial.begin(115200);
//OLED stuff

  display.init();
  display.flipScreenVertically();

//aRest Functions Again
  rest.function("SetWaterPumpPWM",SetWaterPumpPWM);
  rest.function("SetAirPumpPWM",SetAirPumpPWM);
  rest.function("SetLightPumpPWM",SetLightPumpPWM);
  rest.function("SetFanPumpPWM",SetFanPumpPWM);
  rest.function("SetExtraPWM",SetExtraPWM);

//Board Name And Serial Messages
  rest.set_id("1");
  rest.set_name("BuildItHydro");
  WiFi.softAP(ssid, password);
  Serial.println("");
  Serial.println("WiFi created");
  server.begin();
  Serial.println("Server started");
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

//Set used pins as outputs
  pinMode(WaterPumpPin, OUTPUT);
  pinMode(AirPumpPin, OUTPUT);
  pinMode(LightPin, OUTPUT);
  pinMode(FanPin, OUTPUT);
  pinMode(ExtraPin, OUTPUT);
  pinMode(StatusPin, OUTPUT);

//OLED Setup
  display.clear();
  display.drawXbm(1, 0, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
  // display.drawXbm(65, 0, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits); //TODO: replace with AppShed Logo
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);
  display.drawString(64, 44, "LOADING");
  display.display();
  delay(3000);
  display.clear();
  delay(1000);
  display.drawXbm(35, 15, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);//TODO: replace with QR Code
  display.display();
  delay(1000);
}

void loop() {

  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);

}


  ////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////
  ////  ______                _   _                   ////
  ////  |  ___|              | | (_)                  ////
  ////  | |_ _   _ _ __   ___| |_ _  ___  _ __  ___   ////
  ////  |  _| | | | '_ \ / __| __| |/ _ \| '_ \/ __|  ////
  ////  | | | |_| | | | | (__| |_| | (_) | | | \__ \  ////
  ////  \_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/  ////
  ////                                                ////
  ////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////


int SetWaterPumpPWM(String command) {

//PWM variable sent from app
  int state = command.toInt();

//set WaterPumpPin to PWM value from app
  analogWrite(WaterPumpPin, state);

//Percent
  int percent = map(state, 0, 1023, 0, 100);

//Proof that function triggered
  Serial.println((String)"WaterPumpPin Triggered with PWM value of: " + state);
  Serial.print((String)"Which is " + percent + "%");
  digitalWrite(StatusPin, HIGH);
  delay(500); //Dont judge me, doesnt mess with the WIFI loop that much
  digitalWrite(StatusPin, LOW);
  display.clear();
  display.drawString(64, 12, "Water Pump:");
  display.drawString(64, 35, String(percent) + "%");
  display.display();
  
  return 1;
}


int SetAirPumpPWM(String command1) {

//PWM variable sent from app
  int state1 = command1.toInt();

//set AirPumpPin to PWM value from app
  analogWrite(AirPumpPin, state1);

//Percent
  int percent1 = map(state1, 0, 1023, 0, 100);

//Proof that function triggered
  Serial.println((String)"AirPumpPin Triggered with PWM value of: " + state1);
  Serial.print((String)"Which is " + percent1 + "%");
  digitalWrite(StatusPin, HIGH);
  delay(500); //Dont judge me, doesnt mess with the WIFI loop that much
  digitalWrite(StatusPin, LOW);
  display.clear();
  display.drawString(64, 12, "Air Pump:");
  display.drawString(64, 35, String(percent1) + "%");
  display.display();
  
  return 1;
}


int SetLightPumpPWM(String command2) {

//PWM variable sent from app
  int state2 = command2.toInt();

//set LightPin to PWM value from app
  analogWrite(LightPin, state2);

//Percent
  int percent2 = map(state2, 0, 1023, 0, 100);

//Proof that function triggered
  Serial.println((String)"LightPin Triggered with PWM value of: " + state2);
  Serial.print((String)"Which is " + percent2 + "%");
  digitalWrite(StatusPin, HIGH);
  delay(500); //Dont judge me, doesnt mess with the WIFI loop that much
  digitalWrite(StatusPin, LOW);
  display.clear();
  display.drawString(64, 12, "Lights:");
  display.drawString(64, 35, String(percent2) + "%");
  display.display();
  
  return 1;
}


int SetFanPumpPWM(String command3) {

//PWM variable sent from app
  int state3 = command3.toInt();

//set FanPin to PWM value from app
  analogWrite(FanPin, state3);

//Percent
  int percent3 = map(state3, 0, 1023, 0, 100);

//Proof that function triggered
  Serial.println((String)"FanPin Triggered with PWM value of: " + state3);
  Serial.print((String)"Which is " + percent3 + "%");
  digitalWrite(StatusPin, HIGH);
  delay(500); //Dont judge me, doesnt mess with the WIFI loop that much
  digitalWrite(StatusPin, LOW);
  display.clear();
  display.drawString(64, 12, "Fans:");
  display.drawString(64, 35, String(percent3) + "%");
  display.display();
  
  return 1;
}


int SetExtraPWM(String command4) {

//PWM variable sent from app
  int state4 = command4.toInt();

//set ExtraPin to PWM value from app
  analogWrite(ExtraPin, state4);

//Percent
  int percent4 = map(state4, 0, 1023, 0, 100);

//Proof that function triggered
  Serial.println((String)"ExtraPin Triggered with PWM value of: " + state4);
  Serial.print((String)"Which is " + percent4 + "%");
  digitalWrite(StatusPin, HIGH);
  delay(500); //Dont judge me, doesnt mess with the WIFI loop that much
  digitalWrite(StatusPin, LOW);
  display.clear();
  display.drawString(64, 12, "Extra Pin:");
  display.drawString(64, 35, String(percent4) + "%");
  display.display();
  
  return 1;
}
