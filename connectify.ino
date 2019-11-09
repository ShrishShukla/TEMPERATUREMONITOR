#include <ESP8266WiFi.h>

const char* ssid = "AndroidAP48E0"; //giving hotspot credentials
const char* pass = "tejn1097";

//const char* ssid = "RedmiY2";
//const char* pass = "0C505FB6"; 

WiFiClient client; //creating an instance
//int status = WL_IDLE_STATUS;
void connectToInternet(){
WiFi.begin(ssid, pass); //WiFI.begin initializes library n/w setting and provides status
   while(WiFi.status()!=WL_CONNECTED){ 
       Serial.println("[INFO] Connecting to wifi network"); //WL_CONNECTED IS RETURNED BY WIFI.BEGIN
       Serial.println(".");
          
          //status=WiFi.begin(ssid,pass);
       delay(500);
    }   
    Serial.print("[INFO] success");
}


void loop(){}

void setup(){
  Serial.begin(115200);
  connectToInternet();
  
  
  }
