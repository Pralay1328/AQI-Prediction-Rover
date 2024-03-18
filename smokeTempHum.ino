#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ThingSpeak.h>
#include<DHT.h>
#include<DHT_U.h>

#define DHTPIN D1

const char* ssid= "TP-Link_74F4";
const char* password="book@321";
WiFiClient client;

DHT dht(DHTPIN, DHT11);


unsigned long myChannelNo = 2251218;
const char * myWriteAPIKey = "Z3P2BHGYMBFRQ0ID";
const char * myReadAPIKey = "TMXOLBOS7KIKKHRK";

/*int led_1,led_2,led_3;
int led1=D6;
int led2=D7;
int led3=D8;*/
int mq1=A0;
//int val=0;

void setup()
{
  Serial.begin(9600);
  /*pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);*/

  WiFi.begin(ssid,password);
  dht.begin();
  ThingSpeak.begin(client);
}

void loop()
{
  /*val = analogRead(ldr);
  Serial.println(val);*/
   float mq = analogRead(A0);
float a= mq/1023*100;
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  Serial.print("Gas Level: ");
Serial.println(mq/1023*100);
Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.println("Data Send to Thingspeak");
  Serial.println("");

 
// if (isnan(mq))
// {
// Serial.println("Failed to read from MQ-5 sensor!");
// return;
// }
 
// if (client.connect(server, 80)) // "184.106.153.149" or api.thingspeak.com
// {
// String postStr = apiKey;
// postStr += "&field1=";
// postStr += String(mq/1023*100);
// postStr += "r\n";

// client.print("POST /update HTTP/1.1\n");
// client.print("Host: api.thingspeak.com\n");
// client.print("Connection: close\n");
// client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
// client.print("Content-Type: application/x-www-form-urlencoded\n");
// client.print("Content-Length: ");
// client.print(postStr.length());
// client.print("\n\n");
// client.print(postStr);

//}
delay(500);
// client.stop();
Serial.println("Waiting...");

  //ThingSpeak.writeField(myChannelNo,1,val,myWriteAPIKey);
  //ThingSpeak.writeField(myChannelNo,2,t,myWriteAPIKey);
  //ThingSpeak.writeField(myChannelNo,3,h,myWriteAPIKey);

  ThingSpeak.setField(2,a);
  ThingSpeak.setField(3,t);
  ThingSpeak.setField(4,h);
  ThingSpeak.writeFields(myChannelNo, myWriteAPIKey);

  /*led_1 = ThingSpeak.readIntField(myChannelNo,1,myWriteAPIKey);
  led_2 = ThingSpeak.readIntField(myChannelNo,2,myWriteAPIKey);
  led_3 = ThingSpeak.readIntField(myChannelNo,3,myWriteAPIKey);

  Serial.println(led_1);
  Serial.println(led_2);
  Serial.println(led_3);
  Serial.println("");

  if(led_1>400)
  {
    if(led_2>=32 && led_3>74)
    {
      digitalWrite(led1,HIGH);
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
    }
  }
  else
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }*/

  delay(5000);
}
