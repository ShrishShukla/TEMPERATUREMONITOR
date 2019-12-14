
#include<ESP8266HTTPClient.h>
#include<ESP8266WebServer.h>
#include<WiFiClient.h>
#include<ESP8266WiFi.h>



int TEMP_SENSOR_PIN = A0;
float temperatureC=0.0;
float temperatureF=0.0;
//char server[] = "192.168.43.86";
int port = 80;
//const char* ssid = "Red***iY2";                       //   SSID of the wifi network you want to connect to
const char* ssid = "****"; 
//const char* pass = "0****B6";                       // password of the wifi network
const char* pass = "t8*****7";
unsigned long lastConnectionTime = 0;
const unsigned long postingInterval = 10L*1000L;
WiFiClient client;
HTTPClient http;
//int status = WL_IDLE_STATUS;
void readSensorData(){
   float temperatureSensorValue = analogRead(TEMP_SENSOR_PIN);
   temperatureC = (temperatureSensorValue*224.0)/1024;
   //temperatureC = (voltage - .5)*100;
   temperatureF = (9.0*temperatureC)/5.0 + 32.0;
   Serial.print("[INFO] Tempearture Readings in F:  ");
   Serial.print(temperatureF);
   Serial.println("[INFO] Temperature Readings in C:  ");
   Serial.print(temperatureC);
   Serial.println("Sensor Value");
   //Serial.print(temperatureSensorValue);
}void transmitSensorData(){
  Serial.println("xxxxxxxxxxxxxx");
  String requestData="?temperature="+String(temperatureF);
  String Link="http://192.168.43.86/tempmonitor/add.php" + requestData;
  http.begin(Link);
  int httpCode = http.GET();
  String payL = http.getString();
  Serial.println(httpCode);
  Serial.println(payL);
  http.end();
  }
  void connectToInternet(){
   WiFi.begin(ssid,pass);
   while(WiFi.status()!=WL_CONNECTED){
       Serial.println("[INFO] Connecting to wifi network");
       Serial.println(".");
       //WiFi.begin(ssid,pass);
       delay(500);
    } 
    Serial.println("success");  
}
  void setup(){
  Serial.begin(115200);
  pinMode(TEMP_SENSOR_PIN, INPUT);
  connectToInternet();
}
void loop(){
  readSensorData();
  transmitSensorData();
  delay(6000);
}   
