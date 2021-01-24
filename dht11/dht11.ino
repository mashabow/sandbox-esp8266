#include <ESP8266WiFi.h>
#include "DHT.h"

#define DHTPIN D6     // D6 ピンからセンサーの値を得る
#define DHTTYPE DHT11 // DHT 11 を使う

const char *ssid = "ssid";
const char *password = "password";

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(115200);

  // WiFi に接続する

  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  WiFi.printDiag(Serial);

  dht.begin();
}

void loop()
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  Serial.println("Temperature: " + String(t, 1) + "°C\tHumidity: " + String(h, 0) + "%");

  delay(2000);
}
