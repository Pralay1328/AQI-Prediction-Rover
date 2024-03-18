// #include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C lcd(0x27, 16, 2);   
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ThingSpeak.h>

const char* ssid= "TP-Link_74F4";
const char* password="book@321";
WiFiClient client;

unsigned long myChannelNo = 2251590;
const char * myWriteAPIKey = "I15R6WAY7SSCQTJZ";
const char * myReadAPIKey = "QSIQNB6XWMSQ8IGN";

int measurePin = A0;
int ledPower = D1;    //Pin LED

int samplingTime = 280;
int deltaTime = 40;
int sleepTime = 9680;

float voMeasured = 0;
float calcVoltage = 0;
float dustDensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPower, OUTPUT);
   WiFi.begin(ssid,password);
    ThingSpeak.begin(client);
  // lcd.begin();
  // lcd.backlight();       // เปิด backlight
}

void loop() {
  digitalWrite(ledPower, LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(measurePin); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(ledPower, HIGH); // turn the LED off
  delayMicroseconds(sleepTime);

  // 0 - 3.3V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (3.3 / 1024);

 
  dustDensity = 0.17 * calcVoltage - 0.1;

  Serial.print("Raw Signal Value (0-1023): ");
  Serial.print(voMeasured);

  Serial.print(" - Voltage: ");
  Serial.print(calcVoltage);

  if (dustDensity <= 0.00) {
    dustDensity = 0.00;
  }


  dustDensity = dustDensity * 1000;

  Serial.print(" - Dust Density: ");
  Serial.print(dustDensity);
  Serial.println(" µg/m³");

  ThingSpeak.setField(1,dustDensity);
  ThingSpeak.writeFields(myChannelNo, myWriteAPIKey);
  // lcd.home();
  // lcd.setCursor(1, 0);
  // lcd.print("Dust Density ");
  // lcd.setCursor(2, 1);
  // lcd.print(dustDensity);
  // lcd.print(" ug/m3  ");
  delay(1000);
}
