#include <Arduino.h>

#include <WiFi.h>

#include <Espalexa.h>

#define RelayPin1   13 //D5
#define RelayPin2   12 //D2
#define RelayPin3  14  //D13
#define RelayPin4  27 //D4
#define RelayPin5  26 //D15
#define RelayPin6 25
#define RelayPin7 33
#define RelayPin8 32

boolean connectWifi();

void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);
void fourthLightChanged(uint8_t brightness);
void fifthLightChanged(uint8_t brightness);
void firstswitchChanged(uint8_t brightness);
void secondswitchChanged(uint8_t brightness);
void thirdswitchChanged(uint8_t brightness);

#define WIFI_SSID    "Sage"
#define WIFI_PASSWORD "plasticgirl"

String Device_1_Name = "Kitchen light";
String Device_2_Name = "Bedroom light";
String Device_3_Name = "Surronding light";
String Device_4_Name = "Security A light";
String Device_5_Name = "Security B light";
String Device_6_Name = "Security module";
String Device_7_Name = "Open gate";
String Device_8_Name = "Close gate";

bool isConnected = false;

Espalexa espalexa;

void firstLightChanged(uint8_t brightness)
{
  //Control the device
  
  if (brightness == 255)
    {
      digitalWrite(RelayPin1, HIGH);
      Serial.println("Device1 ON");
    }
  else
  {
    digitalWrite(RelayPin1, LOW);
    Serial.println("Device1 OFF");
  }
}

void secondLightChanged(uint8_t brightness)
{
  //Control the device 
  
  if (brightness == 255)
    {
      digitalWrite(RelayPin2, HIGH);
      Serial.println("Device2 ON");
    }
  else
  {
    digitalWrite(RelayPin2, LOW);
    Serial.println("Device2 OFF");
  }
}

void thirdLightChanged(uint8_t brightness)
{
  //Control the device  
  if (brightness == 255)
    {
      digitalWrite(RelayPin3, HIGH);
      Serial.println("Device3 ON");
    }
  else
  {
    digitalWrite(RelayPin3, LOW);
    Serial.println("Device3 OFF");
  }
}
void halfLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin4, HIGH);
      Serial.println("Device4 ON");
    }
  else
  {
    digitalWrite(RelayPin4, LOW);
    Serial.println("Device4 OFF");
  }
}

void fullLightChanged(uint8_t brightness)
{
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin5, HIGH);
      digitalWrite(RelayPin4, HIGH);

      Serial.println("Device4 ON");
      Serial.println("Device5 ON");
    }
  else
  {
    digitalWrite(RelayPin5, LOW);
    digitalWrite(RelayPin4, LOW);

    Serial.println("Device4 OFF");
    Serial.println("Device5 OFF");
  }
}

void firstswitchChanged(uint8_t brightness){
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin6 , HIGH);
      Serial.println("Device6 ON");
    }
  else
  {
    digitalWrite(RelayPin6 , LOW);
    Serial.println("Device6 OFF");
  }
}

void secondswitchChanged(uint8_t brightness){
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin7, HIGH);
      Serial.println("Device7 ON");
      delay(6000);
    digitalWrite(RelayPin7, LOW);
    Serial.println("Device7 OFF");
  }
}

void thirdswitchChanged(uint8_t brightness){
  //Control the device 
  if (brightness == 255)
    {
      digitalWrite(RelayPin8, HIGH);
      Serial.println("Device8 ON");
      delay(6000);
    digitalWrite(RelayPin8, LOW);
    Serial.println("Device8 OFF");
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.println("starting...");


  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT);
  pinMode(RelayPin6, OUTPUT);
  pinMode(RelayPin7, OUTPUT);
  pinMode(RelayPin8, OUTPUT);

  espalexa.addDevice(Device_1_Name, firstLightChanged); //simplest definition, default state off
  espalexa.addDevice(Device_2_Name, secondLightChanged);
  espalexa.addDevice(Device_3_Name, thirdLightChanged);
  espalexa.addDevice(Device_4_Name, halfLightChanged);
  espalexa.addDevice(Device_5_Name, fullLightChanged);
   espalexa.addDevice(Device_6_Name, firstswitchChanged);
  espalexa.addDevice(Device_7_Name, secondswitchChanged);
  espalexa.addDevice(Device_8_Name, thirdswitchChanged);

    espalexa.begin();
    Serial.println("connect");
  
}

void loop() {
  Serial.println("conne");
  if(WiFi.status() == WL_CONNECTED){
     Serial.println("connected");
  digitalWrite(LED_BUILTIN, HIGH);
    
  isConnected = true;
  }

  if (WiFi.status() != WL_CONNECTED){
    Serial.println("...");
    digitalWrite(LED_BUILTIN, LOW); 
    delay(1000);
    isConnected = false;
  }
  espalexa.loop();
  delay(1);
  
}