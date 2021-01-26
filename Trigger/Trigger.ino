#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#define pirPin D1
int val = 0;

const char* ssid     = ****;
const char* password = ****;  

const uint16_t port = 8080;
const char *host = "192.168.1.20";
WiFiClient client;
void setup()
{
    Serial.begin(115200);
    Serial.println("Connecting...\n");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid,password); 
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    pinMode(pirPin, INPUT);
           
}

void loop()
{
    val = digitalRead(pirPin);  // read input value
    if (!client.connect(host, port))
    {
        Serial.println("Connection to host failed");
        delay(1000);
        return;
    }
   
    if (val) 
    { delay(250);
      client.println("Escape");
      delay(2000);
     
    }
    
    client.stop();
}
