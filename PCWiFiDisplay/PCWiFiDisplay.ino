#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>;
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); //0x27


//Настройки
String payload;
const char* ssid = "SSID";          //название вашей Wi-Fi сети
const char* password = "PASSWORD";  //пароль от сети
String IP_SRV = "127.0.0.1";        //ip адресс, где открывается сервер
void setup(void)
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("Connecting...");
  }
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("WAKE UP NEO!");
  lcd.setCursor(0, 1);
  lcd.print("WAKE UP");
  Serial.println("...ok...");
}

void loop(void)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;  //Object of class HTTPClient
    http.begin(IP_SRV + ":8085/data.json");
    int httpCode = http.GET();
    //Проверка возвращаемого кода
    if (httpCode > 0)
    {
      const size_t bufferSize = 30*JSON_ARRAY_SIZE(0) + 5*JSON_ARRAY_SIZE(1) + 3*JSON_ARRAY_SIZE(2) + 6*JSON_ARRAY_SIZE(3) + 3*JSON_ARRAY_SIZE(4) + JSON_ARRAY_SIZE(6) + 48*JSON_OBJECT_SIZE(4) + 2260 ;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      int id = root["id"]; // 0
      const char* Text = root["Text"]; // "Sensor"
      JsonObject& Children0 = root["Children"][0];
      JsonArray& Children0_Children = Children0["Children"];
      JsonObject& Children0_Children0 = Children0_Children[0];
int Children0_Children0_id = Children0_Children0["id"]; // 2
const char* Children0_Children0_Text = Children0_Children0["Text"]; // "Lenovo 20160"

const char* Children0_Children0_Value = Children0_Children0["Value"]; // ""

JsonObject& Children0_Children1 = Children0_Children[1];
int Children0_Children1_id = Children0_Children1["id"]; // 3
const char* Children0_Children1_Text = Children0_Children1["Text"]; // "Intel Pentium 2020M"

JsonArray& Children0_Children1_Children = Children0_Children1["Children"];

JsonObject& Children0_Children1_Children0 = Children0_Children1_Children[0];
int Children0_Children1_Children0_id = Children0_Children1_Children0["id"]; // 4
const char* Children0_Children1_Children0_Text = Children0_Children1_Children0["Text"]; // "Clocks"

JsonArray& Children0_Children1_Children0_Children = Children0_Children1_Children0["Children"];

JsonObject& Children0_Children1_Children0_Children0 = Children0_Children1_Children0_Children[0];
int Children0_Children1_Children0_Children0_id = Children0_Children1_Children0_Children0["id"]; // 5
const char* Children0_Children1_Children0_Children0_Text = Children0_Children1_Children0_Children0["Text"]; // "Bus Speed"

const char* Children0_Children1_Children0_Children0_Value = Children0_Children1_Children0_Children0["Value"]; // "100 MHz"

JsonObject& Children0_Children1_Children0_Children1 = Children0_Children1_Children0_Children[1];
int Children0_Children1_Children0_Children1_id = Children0_Children1_Children0_Children1["id"]; // 6
const char* Children0_Children1_Children0_Children1_Text = Children0_Children1_Children0_Children1["Text"]; // "CPU Core #1"

const char* Children0_Children1_Children0_Children1_Value = Children0_Children1_Children0_Children1["Value"]; // "2395 MHz"

JsonObject& Children0_Children1_Children0_Children2 = Children0_Children1_Children0_Children[2];
int Children0_Children1_Children0_Children2_id = Children0_Children1_Children0_Children2["id"]; // 7
const char* Children0_Children1_Children0_Children2_Text = Children0_Children1_Children0_Children2["Text"]; // "CPU Core #2"

const char* Children0_Children1_Children0_Children2_Value = Children0_Children1_Children0_Children2["Value"]; // "2395 MHz"

const char* Children0_Children1_Children0_Value = Children0_Children1_Children0["Value"]; // ""

JsonObject& Children0_Children1_Children1 = Children0_Children1_Children[1];
int Children0_Children1_Children1_id = Children0_Children1_Children1["id"]; // 8
const char* Children0_Children1_Children1_Text = Children0_Children1_Children1["Text"]; // "Temperatures"

JsonArray& Children0_Children1_Children1_Children = Children0_Children1_Children1["Children"];

JsonObject& Children0_Children1_Children1_Children0 = Children0_Children1_Children1_Children[0];
int Children0_Children1_Children1_Children0_id = Children0_Children1_Children1_Children0["id"]; // 9
const char* Children0_Children1_Children1_Children0_Text = Children0_Children1_Children1_Children0["Text"]; // "CPU Core #1"

const char* Children0_Children1_Children1_Children0_Value = Children0_Children1_Children1_Children0["Value"]; // "49,0 °C"

JsonObject& Children0_Children1_Children1_Children1 = Children0_Children1_Children1_Children[1];
int Children0_Children1_Children1_Children1_id = Children0_Children1_Children1_Children1["id"]; // 10
const char* Children0_Children1_Children1_Children1_Text = Children0_Children1_Children1_Children1["Text"]; // "CPU Core #2"

const char* Children0_Children1_Children1_Children1_Value = Children0_Children1_Children1_Children1["Value"]; // "49,0 °C"

JsonObject& Children0_Children1_Children1_Children2 = Children0_Children1_Children1_Children[2];
int Children0_Children1_Children1_Children2_id = Children0_Children1_Children1_Children2["id"]; // 11
const char* Children0_Children1_Children1_Children2_Text = Children0_Children1_Children1_Children2["Text"]; // "CPU Package"

const char* Children0_Children1_Children1_Children2_Value = Children0_Children1_Children1_Children2["Value"]; // "49,0 °C"
      
    }
    http.end();   //Закрытие соединения
  }
}

