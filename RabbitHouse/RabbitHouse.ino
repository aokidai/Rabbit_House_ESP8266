#ifdef ESP32
  #include <WiFi.h>
  #include <HTTPClient.h>
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266HTTPClient.h>
  #include <WiFiClient.h>
#endif
#include <IRremote.h>

#include <Wire.h>
#include "DHT.h"
#define DHTPIN 5 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);  

const char* ssid     = "wifiname";
const char* password = "passwifi";

const char* serverName = "http://rabbithouse.atwebpages.com/MonNhung/esp_data.php";

String apiKeyValue = "kjsjkhjdhfd";

String sensorName = "DHT11";
String sensorLocation = "RabbitHouse";

#define SEALEVELPRESSURE_HPA (1013.25)

int sensorPin = A0;
int enable2 = 13;
int sensorValue2 = 0;

int led = 4;     
int button = 16; 
int temp = 0; 

const int RED = 12;
const int GREEN = 13;
const int BLUE = 15;

int checkrain = 0;

int IR_Recv = 0; 
IRrecv irrecv(IR_Recv);
decode_results results;

void setup() {
  pinMode(enable2, OUTPUT); 
  Serial.begin(115200);
  dht.begin();
  pinMode(led, OUTPUT);   
  pinMode(button, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  irrecv.enableIRIn();
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if(WiFi.status()== WL_CONNECTED){
    WiFiClient client;
    HTTPClient http;
    
    http.begin(client, serverName);
    
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    delay(2000);
    temp = digitalRead(button);
    if (irrecv.decode(&results)){
      long int decCode = results.value;
      Serial.println(decCode);
     if (results.value == 16736925 || results.value == 16769565) {
        digitalWrite(led, HIGH);
        Serial.println("LED Turned ON");
        delay(100);
         float h = dht.readHumidity();
         float t = dht.readTemperature();
         float f = dht.readTemperature(true);
         if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println("Failed to read from DHT sensor!");
          return;
         }
         float hif = dht.computeHeatIndex(f, h);
         float hic = dht.computeHeatIndex(t, h, false);
         sensorValue2 = analogRead(sensorPin);
        sensorValue2 = constrain(sensorValue2, 150, 440); 
        sensorValue2 = map(sensorValue2, 150, 440, 1023, 0); 
        String tmprain;
        if (sensorValue2 == HIGH)
        {
          tmprain = "Co mua";
          Serial.print("rain is detected");
          checkrain = 1;
        digitalWrite(enable2, HIGH);
          }
          else
          
        {
          tmprain = "Khong co mua";
          Serial.print("rain not detected");
          checkrain = 0;
          digitalWrite(enable2, LOW); 
          }
        Serial.println();
        String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName
                              + "&location=" + sensorLocation + "&value1=" + t
                              + "&value2=" + h + "" + "&mua=" + tmprain;
        Serial.print("httpRequestData: ");
        Serial.println(httpRequestData);
        if(t>37)
        {
          if(checkrain == 0)
          {
            analogWrite(RED, HIGH);
            delay(5000);
            analogWrite(RED, LOW);
          }
          else{
            analogWrite(BLUE, HIGH);
            delay(5000);
            analogWrite(BLUE, LOW);
            analogWrite(RED, HIGH);
            delay(5000);
            analogWrite(RED, LOW);
          }
        }
        else{
          if(checkrain == 0)
          {
            analogWrite(GREEN, HIGH);
            delay(5000);
            analogWrite(GREEN, LOW);
          }
          else{
            analogWrite(BLUE, HIGH);
            delay(5000);
            analogWrite(BLUE, LOW);
            analogWrite(GREEN, HIGH);
            delay(5000);
            analogWrite(RED, LOW);
          }
        }
        int httpResponseCode = http.POST(httpRequestData);
            
        if (httpResponseCode>0) {
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
        }
        else {
          Serial.print("Error code: ");
          Serial.println(httpResponseCode);
        }
        http.end();
       }
       decCode = -1;
    }
     else {
        digitalWrite(led, LOW);
        Serial.println("LED Turned OFF");
        delay(100);
       }
       if (temp == HIGH) {
        digitalWrite(led, HIGH);
        Serial.println("LED Turned ON");
        delay(100);
         float h = dht.readHumidity();
         float t = dht.readTemperature();
         float f = dht.readTemperature(true);
         if (isnan(h) || isnan(t) || isnan(f)) {
          Serial.println("Failed to read from DHT sensor!");
          return;
         }
         float hif = dht.computeHeatIndex(f, h);
         float hic = dht.computeHeatIndex(t, h, false);
         sensorValue2 = analogRead(sensorPin);
        sensorValue2 = constrain(sensorValue2, 150, 440); 
        sensorValue2 = map(sensorValue2, 150, 440, 1023, 0); 
        String tmprain;
        if (sensorValue2 == HIGH)
        {
          tmprain = "Co mua";
          Serial.print("rain is detected");
          checkrain = 1;
        digitalWrite(enable2, HIGH);
          }
          else
          
        {
          tmprain = "Khong co mua";
          Serial.print("rain not detected");
          checkrain = 0;
          digitalWrite(enable2, LOW); 
          }
        Serial.println();
        String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName
                              + "&location=" + sensorLocation + "&value1=" + t
                              + "&value2=" + h + "" + "&mua=" + tmprain;
        Serial.print("httpRequestData: ");
        Serial.println(httpRequestData);
        if(t>37)
        {
          if(checkrain == 0)
          {
            analogWrite(RED, HIGH);
            delay(5000);
            analogWrite(RED, LOW);
          }
          else{
            analogWrite(BLUE, HIGH);
            delay(5000);
            analogWrite(BLUE, LOW);
            analogWrite(RED, HIGH);
            delay(5000);
            analogWrite(RED, LOW);
          }
        }
        else{
          if(checkrain == 0)
          {
            analogWrite(GREEN, HIGH);
            delay(5000);
            analogWrite(GREEN, LOW);
          }
          else{
            analogWrite(BLUE, HIGH);
            delay(5000);
            analogWrite(BLUE, LOW);
            analogWrite(GREEN, HIGH);
            delay(5000);
            analogWrite(RED, LOW);
          }
        }
        int httpResponseCode = http.POST(httpRequestData);
       
        if (httpResponseCode>0) {
          Serial.print("HTTP Response code: ");
          Serial.println(httpResponseCode);
        }
        else {
          Serial.print("Error code: ");
          Serial.println(httpResponseCode);
        }
        http.end();
       }
     else {
        digitalWrite(led, LOW);
        Serial.println("LED Turned OFF");
        delay(100);
       }
  }
  else {
    Serial.println("WiFi Disconnected");
  }
}
