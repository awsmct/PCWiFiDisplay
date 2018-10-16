#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>;
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //0x27


//Настройки
const char* value;
String payload;
const char* ssid = "Sergei";          //название вашей Wi-Fi сети
const char* password = "sergeiradioisdead";  //пароль от сети
String IP_SRV = "http://192.168.0.103";        //ip адресс, где открывается сервер
void setup(void)
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");

  lcd.begin(4, 5);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("WAKE UP NEO!");
  lcd.setCursor(0, 1);
  lcd.print("WAKE UP");
  Serial.println("...ok...");
  delay(5000);
  lcd.clear();
  lcd.noBacklight();
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
      const size_t bufferSize = 46 * JSON_ARRAY_SIZE(0) + 12 * JSON_ARRAY_SIZE(1) + 4 * JSON_ARRAY_SIZE(2) + 5 * JSON_ARRAY_SIZE(3) + 2 * JSON_ARRAY_SIZE(4) + 2 * JSON_ARRAY_SIZE(5) + 2 * JSON_ARRAY_SIZE(6) + JSON_ARRAY_SIZE(8) + 74 * JSON_OBJECT_SIZE(7) + 7630;
      DynamicJsonBuffer jsonBuffer(bufferSize);

      const char* json = "{\"id\":0,\"Text\":\"Sensor\",\"Children\":[{\"id\":1,\"Text\":\"DESKTOP-0GSCIPU\",\"Children\":[{\"id\":2,\"Text\":\"ASRock A55iCafe\",\"Children\":[{\"id\":3,\"Text\":\"Nuvoton NCT6776F\",\"Children\":[{\"id\":4,\"Text\":\"Voltages\",\"Children\":[{\"id\":5,\"Text\":\"CPU VCore\",\"Children\":[],\"Min\":\"1,400 V\",\"Value\":\"1,416 V\",\"Max\":\"1,432 V\",\"ImageURL\":\"images/transparent.png\"},{\"id\":6,\"Text\":\"Voltage #2\",\"Children\":[],\"Min\":\"1,840 V\",\"Value\":\"1,856 V\",\"Max\":\"1,872 V\",\"ImageURL\":\"images/transparent.png\"},{\"id\":7,\"Text\":\"AVCC\",\"Children\":[],\"Min\":\"3,328 V\",\"Value\":\"3,328 V\",\"Max\":\"3,344 V\",\"ImageURL\":\"images/transparent.png\"},{\"id\":8,\"Text\":\"3VCC\",\"Children\":[],\"Min\":\"3,312 V\",\"Value\":\"3,328 V\",\"Max\":\"3,344 V\",\"ImageURL\":\"images/transparent.png\"},{\"id\":9,\"Text\":\"Voltage #5\",\"Children\":[],\"Min\":\"0,032 V\",\"Value\":\"0,288 V\",\"Max\":\"0,576 V\",\"ImageURL\":\"images/transparent.png\"},{\"id\":10,\"Text\":\"Voltage #6\",\"Children\":[],\"Min\":\"1,696 V\",\"Value\":\"1,704 V\",\"Max\":\"1,720 V\",\"ImageURL\":\"images/transparent.png\"},{\"id\":11,\"Text\":\"Voltage #7\",\"Children\":[],\"Min\":\"0,032 V\",\"Value\":\"0,272 V\",\"Max\":\"0,560 V\",\"ImageURL\":\"images/transparent.png\"},{\"id\":12,\"Text\":\"3VSB\",\"Children\":[],\"Min\":\"3,440 V\",\"Value\":\"3,440 V\",\"Max\":\"3,456 V\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/voltage.png\"},{\"id\":13,\"Text\":\"Temperatures\",\"Children\":[{\"id\":14,\"Text\":\"Temperature #1\",\"Children\":[],\"Min\":\"31,5 °C\",\"Value\":\"45,0 °C\",\"Max\":\"45,5 °C\",\"ImageURL\":\"images/transparent.png\"},{\"id\":15,\"Text\":\"Temperature #2\",\"Children\":[],\"Min\":\"53,0 °C\",\"Value\":\"75,0 °C\",\"Max\":\"125,0 °C\",\"ImageURL\":\"images/transparent.png\"},{\"id\":16,\"Text\":\"Temperature #3\",\"Children\":[],\"Min\":\"30,0 °C\",\"Value\":\"35,0 °C\",\"Max\":\"36,0 °C\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/temperature.png\"},{\"id\":17,\"Text\":\"Fans\",\"Children\":[{\"id\":18,\"Text\":\"Fan #5\",\"Children\":[],\"Min\":\"1396 RPM\",\"Value\":\"1511 RPM\",\"Max\":\"1527 RPM\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/fan.png\"},{\"id\":19,\"Text\":\"Controls\",\"Children\":[{\"id\":20,\"Text\":\"Fan Control #1\",\"Children\":[],\"Min\":\"100,0 %\",\"Value\":\"100,0 %\",\"Max\":\"100,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":21,\"Text\":\"Fan Control #2\",\"Children\":[],\"Min\":\"100,0 %\",\"Value\":\"100,0 %\",\"Max\":\"100,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":22,\"Text\":\"Fan Control #3\",\"Children\":[],\"Min\":\"45,5 %\",\"Value\":\"45,5 %\",\"Max\":\"45,5 %\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/control.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/chip.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/mainboard.png\"},{\"id\":23,\"Text\":\"AMD Athlon II X4 641\",\"Children\":[{\"id\":24,\"Text\":\"Clocks\",\"Children\":[{\"id\":25,\"Text\":\"Bus Speed\",\"Children\":[],\"Min\":\"100 MHz\",\"Value\":\"100 MHz\",\"Max\":\"100 MHz\",\"ImageURL\":\"images/transparent.png\"},{\"id\":26,\"Text\":\"CPU Core #1\",\"Children\":[],\"Min\":\"2795 MHz\",\"Value\":\"2795 MHz\",\"Max\":\"2795 MHz\",\"ImageURL\":\"images/transparent.png\"},{\"id\":27,\"Text\":\"CPU Core #2\",\"Children\":[],\"Min\":\"2795 MHz\",\"Value\":\"2795 MHz\",\"Max\":\"2795 MHz\",\"ImageURL\":\"images/transparent.png\"},{\"id\":28,\"Text\":\"CPU Core #3\",\"Children\":[],\"Min\":\"2795 MHz\",\"Value\":\"2795 MHz\",\"Max\":\"2795 MHz\",\"ImageURL\":\"images/transparent.png\"},{\"id\":29,\"Text\":\"CPU Core #4\",\"Children\":[],\"Min\":\"2795 MHz\",\"Value\":\"2795 MHz\",\"Max\":\"2795 MHz\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/clock.png\"},{\"id\":30,\"Text\":\"Temperatures\",\"Children\":[{\"id\":31,\"Text\":\"Core #1 - #4\",\"Children\":[],\"Min\":\"5,0 °C\",\"Value\":\"27,4 °C\",\"Max\":\"31,1 °C\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/temperature.png\"},{\"id\":32,\"Text\":\"Load\",\"Children\":[{\"id\":33,\"Text\":\"CPU Total\",\"Children\":[],\"Min\":\"0,0 %\",\"Value\":\"35,9 %\",\"Max\":\"100,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":34,\"Text\":\"CPU Core #1\",\"Children\":[],\"Min\":\"0,0 %\",\"Value\":\"18,8 %\",\"Max\":\"100,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":35,\"Text\":\"CPU Core #2\",\"Children\":[],\"Min\":\"0,0 %\",\"Value\":\"15,6 %\",\"Max\":\"100,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":36,\"Text\":\"CPU Core #3\",\"Children\":[],\"Min\":\"0,0 %\",\"Value\":\"78,1 %\",\"Max\":\"100,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":37,\"Text\":\"CPU Core #4\",\"Children\":[],\"Min\":\"0,0 %\",\"Value\":\"31,3 %\",\"Max\":\"100,0 %\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/load.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/cpu.png\"},{\"id\":38,\"Text\":\"Generic Memory\",\"Children\":[{\"id\":39,\"Text\":\"Load\",\"Children\":[{\"id\":40,\"Text\":\"Memory\",\"Children\":[],\"Min\":\"28,1 %\",\"Value\":\"85,4 %\",\"Max\":\"97,4 %\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/load.png\"},{\"id\":41,\"Text\":\"Data\",\"Children\":[{\"id\":42,\"Text\":\"Used Memory\",\"Children\":[],\"Min\":\"1,1 GB\",\"Value\":\"3,4 GB\",\"Max\":\"3,9 GB\",\"ImageURL\":\"images/transparent.png\"},{\"id\":43,\"Text\":\"Available Memory\",\"Children\":[],\"Min\":\"0,1 GB\",\"Value\":\"0,6 GB\",\"Max\":\"2,9 GB\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/power.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/ram.png\"},{\"id\":44,\"Text\":\"NVIDIA GeForce GTS 450\",\"Children\":[{\"id\":45,\"Text\":\"Clocks\",\"Children\":[{\"id\":46,\"Text\":\"GPU Core\",\"Children\":[],\"Min\":\"51 MHz\",\"Value\":\"51 MHz\",\"Max\":\"783 MHz\",\"ImageURL\":\"images/transparent.png\"},{\"id\":47,\"Text\":\"GPU Memory\",\"Children\":[],\"Min\":\"135 MHz\",\"Value\":\"135 MHz\",\"Max\":\"1804 MHz\",\"ImageURL\":\"images/transparent.png\"},{\"id\":48,\"Text\":\"GPU Shader\",\"Children\":[],\"Min\":\"101 MHz\",\"Value\":\"101 MHz\",\"Max\":\"1566 MHz\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/clock.png\"},{\"id\":49,\"Text\":\"Temperatures\",\"Children\":[{\"id\":50,\"Text\":\"GPU Core\",\"Children\":[],\"Min\":\"34,0 °C\",\"Value\":\"38,0 °C\",\"Max\":\"42,0 °C\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/temperature.png\"},{\"id\":51,\"Text\":\"Load\",\"Children\":[{\"id\":52,\"Text\":\"GPU Core\",\"Children\":[],\"Min\":\"0,0 %\",\"Value\":\"1,0 %\",\"Max\":\"61,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":53,\"Text\":\"GPU Memory Controller\",\"Children\":[],\"Min\":\"1,0 %\",\"Value\":\"7,0 %\",\"Max\":\"41,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":54,\"Text\":\"GPU Video Engine\",\"Children\":[],\"Min\":\"0,0 %\",\"Value\":\"0,0 %\",\"Max\":\"16,0 %\",\"ImageURL\":\"images/transparent.png\"},{\"id\":55,\"Text\":\"GPU Memory\",\"Children\":[],\"Min\":\"9,1 %\",\"Value\":\"23,9 %\",\"Max\":\"25,4 %\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/load.png\"},{\"id\":56,\"Text\":\"Fans\",\"Children\":[{\"id\":57,\"Text\":\"GPU\",\"Children\":[],\"Min\":\"1230 RPM\",\"Value\":\"1320 RPM\",\"Max\":\"1320 RPM\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/fan.png\"},{\"id\":58,\"Text\":\"Controls\",\"Children\":[{\"id\":59,\"Text\":\"GPU Fan\",\"Children\":[],\"Min\":\"30,0 %\",\"Value\":\"30,0 %\",\"Max\":\"30,0 %\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/control.png\"},{\"id\":60,\"Text\":\"Data\",\"Children\":[{\"id\":61,\"Text\":\"GPU Memory Free\",\"Children\":[],\"Min\":\"764,3 MB\",\"Value\":\"779,0 MB\",\"Max\":\"931,2 MB\",\"ImageURL\":\"images/transparent.png\"},{\"id\":62,\"Text\":\"GPU Memory Used\",\"Children\":[],\"Min\":\"92,8 MB\",\"Value\":\"245,0 MB\",\"Max\":\"259,7 MB\",\"ImageURL\":\"images/transparent.png\"},{\"id\":63,\"Text\":\"GPU Memory Total\",\"Children\":[],\"Min\":\"1024,0 MB\",\"Value\":\"1024,0 MB\",\"Max\":\"1024,0 MB\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/power.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/nvidia.png\"},{\"id\":64,\"Text\":\"ST3160812AS\",\"Children\":[{\"id\":65,\"Text\":\"Temperatures\",\"Children\":[{\"id\":66,\"Text\":\"Temperature\",\"Children\":[],\"Min\":\"29,0 °C\",\"Value\":\"45,0 °C\",\"Max\":\"45,0 °C\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/temperature.png\"},{\"id\":67,\"Text\":\"Load\",\"Children\":[{\"id\":68,\"Text\":\"Used Space\",\"Children\":[],\"Min\":\"4,9 %\",\"Value\":\"4,9 %\",\"Max\":\"4,9 %\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/load.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/hdd.png\"},{\"id\":69,\"Text\":\"Hitachi HDS721010CLA332\",\"Children\":[{\"id\":70,\"Text\":\"Temperatures\",\"Children\":[{\"id\":71,\"Text\":\"Temperature\",\"Children\":[],\"Min\":\"27,0 °C\",\"Value\":\"43,0 °C\",\"Max\":\"43,0 °C\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/temperature.png\"},{\"id\":72,\"Text\":\"Load\",\"Children\":[{\"id\":73,\"Text\":\"Used Space\",\"Children\":[],\"Min\":\"38,0 %\",\"Value\":\"38,0 %\",\"Max\":\"38,0 %\",\"ImageURL\":\"images/transparent.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/load.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/hdd.png\"}],\"Min\":\"\",\"Value\":\"\",\"Max\":\"\",\"ImageURL\":\"images_icon/computer.png\"}],\"Min\":\"Min\",\"Value\":\"Value\",\"Max\":\"Max\",\"ImageURL\":\"\"}";

      JsonObject& root = jsonBuffer.parseObject(json, 12);

      int id = root["id"]; // 0
      const char* Text = root["Text"]; // "Sensor"

      JsonObject& Children0 = root["Children"][0];
      int Children0_id = Children0["id"]; // 1
      const char* Children0_Text = Children0["Text"]; // "DESKTOP-0GSCIPU"

      JsonArray& Children0_Children = Children0["Children"];

      JsonObject& Children0_Children0 = Children0_Children[0];
      int Children0_Children0_id = Children0_Children0["id"]; // 2
      const char* Children0_Children0_Text = Children0_Children0["Text"]; // "ASRock A55iCafe"

      JsonObject& Children0_Children0_Children0 = Children0_Children0["Children"][0];
      int Children0_Children0_Children0_id = Children0_Children0_Children0["id"]; // 3
      const char* Children0_Children0_Children0_Text = Children0_Children0_Children0["Text"]; // "Nuvoton NCT6776F"

      JsonArray& Children0_Children0_Children0_Children = Children0_Children0_Children0["Children"];

      JsonObject& Children0_Children0_Children0_Children0 = Children0_Children0_Children0_Children[0];
      int Children0_Children0_Children0_Children0_id = Children0_Children0_Children0_Children0["id"]; // 4
      const char* Children0_Children0_Children0_Children0_Text = Children0_Children0_Children0_Children0["Text"]; // "Voltages"

      JsonArray& Children0_Children0_Children0_Children0_Children = Children0_Children0_Children0_Children0["Children"];

      JsonObject& Children0_Children0_Children0_Children0_Children0 = Children0_Children0_Children0_Children0_Children[0];
      int Children0_Children0_Children0_Children0_Children0_id = Children0_Children0_Children0_Children0_Children0["id"]; // 5
      const char* Children0_Children0_Children0_Children0_Children0_Text = Children0_Children0_Children0_Children0_Children0["Text"]; // "CPU VCore"

      const char* Children0_Children0_Children0_Children0_Children0_Min = Children0_Children0_Children0_Children0_Children0["Min"]; // "1,400 V"
      const char* Children0_Children0_Children0_Children0_Children0_Value = Children0_Children0_Children0_Children0_Children0["Value"]; // "1,416 V"
      const char* Children0_Children0_Children0_Children0_Children0_Max = Children0_Children0_Children0_Children0_Children0["Max"]; // "1,432 V"
      const char* Children0_Children0_Children0_Children0_Children0_ImageURL = Children0_Children0_Children0_Children0_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children0_Children0_Children0_Children1 = Children0_Children0_Children0_Children0_Children[1];
      int Children0_Children0_Children0_Children0_Children1_id = Children0_Children0_Children0_Children0_Children1["id"]; // 6
      const char* Children0_Children0_Children0_Children0_Children1_Text = Children0_Children0_Children0_Children0_Children1["Text"]; // "Voltage #2"

      const char* Children0_Children0_Children0_Children0_Children1_Min = Children0_Children0_Children0_Children0_Children1["Min"]; // "1,840 V"
      const char* Children0_Children0_Children0_Children0_Children1_Value = Children0_Children0_Children0_Children0_Children1["Value"]; // "1,856 V"
      const char* Children0_Children0_Children0_Children0_Children1_Max = Children0_Children0_Children0_Children0_Children1["Max"]; // "1,872 V"
      const char* Children0_Children0_Children0_Children0_Children1_ImageURL = Children0_Children0_Children0_Children0_Children1["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children0_Children0_Children0_Children2 = Children0_Children0_Children0_Children0_Children[2];
      int Children0_Children0_Children0_Children0_Children2_id = Children0_Children0_Children0_Children0_Children2["id"]; // 7
      const char* Children0_Children0_Children0_Children0_Children2_Text = Children0_Children0_Children0_Children0_Children2["Text"]; // "AVCC"

      const char* Children0_Children0_Children0_Children0_Children2_Min = Children0_Children0_Children0_Children0_Children2["Min"]; // "3,328 V"
      const char* Children0_Children0_Children0_Children0_Children2_Value = Children0_Children0_Children0_Children0_Children2["Value"]; // "3,328 V"
      const char* Children0_Children0_Children0_Children0_Children2_Max = Children0_Children0_Children0_Children0_Children2["Max"]; // "3,344 V"
      const char* Children0_Children0_Children0_Children0_Children2_ImageURL = Children0_Children0_Children0_Children0_Children2["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children0_Children0_Children0_Children3 = Children0_Children0_Children0_Children0_Children[3];
      int Children0_Children0_Children0_Children0_Children3_id = Children0_Children0_Children0_Children0_Children3["id"]; // 8
      const char* Children0_Children0_Children0_Children0_Children3_Text = Children0_Children0_Children0_Children0_Children3["Text"]; // "3VCC"

      const char* Children0_Children0_Children0_Children0_Children3_Min = Children0_Children0_Children0_Children0_Children3["Min"]; // "3,312 V"
      const char* Children0_Children0_Children0_Children0_Children3_Value = Children0_Children0_Children0_Children0_Children3["Value"]; // "3,328 V"
      const char* Children0_Children0_Children0_Children0_Children3_Max = Children0_Children0_Children0_Children0_Children3["Max"]; // "3,344 V"
      const char* Children0_Children0_Children0_Children0_Children3_ImageURL = Children0_Children0_Children0_Children0_Children3["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children0_Children0_Children0_Min = Children0_Children0_Children0_Children0["Min"]; // ""
      const char* Children0_Children0_Children0_Children0_Value = Children0_Children0_Children0_Children0["Value"]; // ""
      const char* Children0_Children0_Children0_Children0_Max = Children0_Children0_Children0_Children0["Max"]; // ""
      const char* Children0_Children0_Children0_Children0_ImageURL = Children0_Children0_Children0_Children0["ImageURL"]; // "images_icon/voltage.png"

      JsonObject& Children0_Children0_Children0_Children1 = Children0_Children0_Children0_Children[1];
      int Children0_Children0_Children0_Children1_id = Children0_Children0_Children0_Children1["id"]; // 13
      const char* Children0_Children0_Children0_Children1_Text = Children0_Children0_Children0_Children1["Text"]; // "Temperatures"

      JsonArray& Children0_Children0_Children0_Children1_Children = Children0_Children0_Children0_Children1["Children"];

      JsonObject& Children0_Children0_Children0_Children1_Children0 = Children0_Children0_Children0_Children1_Children[0];
      int Children0_Children0_Children0_Children1_Children0_id = Children0_Children0_Children0_Children1_Children0["id"]; // 14
      const char* Children0_Children0_Children0_Children1_Children0_Text = Children0_Children0_Children0_Children1_Children0["Text"]; // "Temperature #1"

      const char* Children0_Children0_Children0_Children1_Children0_Min = Children0_Children0_Children0_Children1_Children0["Min"]; // "31,5 °C"
      const char* Children0_Children0_Children0_Children1_Children0_Value = Children0_Children0_Children0_Children1_Children0["Value"]; // "45,0 °C"
      const char* Children0_Children0_Children0_Children1_Children0_Max = Children0_Children0_Children0_Children1_Children0["Max"]; // "45,5 °C"
      const char* Children0_Children0_Children0_Children1_Children0_ImageURL = Children0_Children0_Children0_Children1_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children0_Children0_Children1_Children1 = Children0_Children0_Children0_Children1_Children[1];
      int Children0_Children0_Children0_Children1_Children1_id = Children0_Children0_Children0_Children1_Children1["id"]; // 15
      const char* Children0_Children0_Children0_Children1_Children1_Text = Children0_Children0_Children0_Children1_Children1["Text"]; // "Temperature #2"

      const char* Children0_Children0_Children0_Children1_Children1_Min = Children0_Children0_Children0_Children1_Children1["Min"]; // "53,0 °C"
      const char* Children0_Children0_Children0_Children1_Children1_Value = Children0_Children0_Children0_Children1_Children1["Value"]; // "75,0 °C"
      const char* Children0_Children0_Children0_Children1_Children1_Max = Children0_Children0_Children0_Children1_Children1["Max"]; // "125,0 °C"
      const char* Children0_Children0_Children0_Children1_Children1_ImageURL = Children0_Children0_Children0_Children1_Children1["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children0_Children0_Children1_Children2 = Children0_Children0_Children0_Children1_Children[2];
      int Children0_Children0_Children0_Children1_Children2_id = Children0_Children0_Children0_Children1_Children2["id"]; // 16
      const char* Children0_Children0_Children0_Children1_Children2_Text = Children0_Children0_Children0_Children1_Children2["Text"]; // "Temperature #3"

      const char* Children0_Children0_Children0_Children1_Children2_Min = Children0_Children0_Children0_Children1_Children2["Min"]; // "30,0 °C"
      const char* Children0_Children0_Children0_Children1_Children2_Value = Children0_Children0_Children0_Children1_Children2["Value"]; // "35,0 °C"
      const char* Children0_Children0_Children0_Children1_Children2_Max = Children0_Children0_Children0_Children1_Children2["Max"]; // "36,0 °C"
      const char* Children0_Children0_Children0_Children1_Children2_ImageURL = Children0_Children0_Children0_Children1_Children2["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children0_Children0_Children1_Min = Children0_Children0_Children0_Children1["Min"]; // ""
      const char* Children0_Children0_Children0_Children1_Value = Children0_Children0_Children0_Children1["Value"]; // ""
      const char* Children0_Children0_Children0_Children1_Max = Children0_Children0_Children0_Children1["Max"]; // ""
      const char* Children0_Children0_Children0_Children1_ImageURL = Children0_Children0_Children0_Children1["ImageURL"]; // "images_icon/temperature.png"

      JsonObject& Children0_Children0_Children0_Children2 = Children0_Children0_Children0_Children[2];
      int Children0_Children0_Children0_Children2_id = Children0_Children0_Children0_Children2["id"]; // 17
      const char* Children0_Children0_Children0_Children2_Text = Children0_Children0_Children0_Children2["Text"]; // "Fans"

      JsonObject& Children0_Children0_Children0_Children2_Children0 = Children0_Children0_Children0_Children2["Children"][0];
      int Children0_Children0_Children0_Children2_Children0_id = Children0_Children0_Children0_Children2_Children0["id"]; // 18
      const char* Children0_Children0_Children0_Children2_Children0_Text = Children0_Children0_Children0_Children2_Children0["Text"]; // "Fan #5"

      const char* Children0_Children0_Children0_Children2_Children0_Min = Children0_Children0_Children0_Children2_Children0["Min"]; // "1396 RPM"
      const char* Children0_Children0_Children0_Children2_Children0_Value = Children0_Children0_Children0_Children2_Children0["Value"]; // "1511 RPM"
      const char* Children0_Children0_Children0_Children2_Children0_Max = Children0_Children0_Children0_Children2_Children0["Max"]; // "1527 RPM"
      const char* Children0_Children0_Children0_Children2_Children0_ImageURL = Children0_Children0_Children0_Children2_Children0["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children0_Children0_Children2_Min = Children0_Children0_Children0_Children2["Min"]; // ""
      const char* Children0_Children0_Children0_Children2_Value = Children0_Children0_Children0_Children2["Value"]; // ""
      const char* Children0_Children0_Children0_Children2_Max = Children0_Children0_Children0_Children2["Max"]; // ""
      const char* Children0_Children0_Children0_Children2_ImageURL = Children0_Children0_Children0_Children2["ImageURL"]; // "images_icon/fan.png"

      JsonObject& Children0_Children0_Children0_Children3 = Children0_Children0_Children0_Children[3];
      int Children0_Children0_Children0_Children3_id = Children0_Children0_Children0_Children3["id"]; // 19
      const char* Children0_Children0_Children0_Children3_Text = Children0_Children0_Children0_Children3["Text"]; // "Controls"

      JsonArray& Children0_Children0_Children0_Children3_Children = Children0_Children0_Children0_Children3["Children"];

      JsonObject& Children0_Children0_Children0_Children3_Children0 = Children0_Children0_Children0_Children3_Children[0];
      int Children0_Children0_Children0_Children3_Children0_id = Children0_Children0_Children0_Children3_Children0["id"]; // 20
      const char* Children0_Children0_Children0_Children3_Children0_Text = Children0_Children0_Children0_Children3_Children0["Text"]; // "Fan Control #1"

      const char* Children0_Children0_Children0_Children3_Children0_Min = Children0_Children0_Children0_Children3_Children0["Min"]; // "100,0 %"
      const char* Children0_Children0_Children0_Children3_Children0_Value = Children0_Children0_Children0_Children3_Children0["Value"]; // "100,0 %"
      const char* Children0_Children0_Children0_Children3_Children0_Max = Children0_Children0_Children0_Children3_Children0["Max"]; // "100,0 %"
      const char* Children0_Children0_Children0_Children3_Children0_ImageURL = Children0_Children0_Children0_Children3_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children0_Children0_Children3_Children1 = Children0_Children0_Children0_Children3_Children[1];
      int Children0_Children0_Children0_Children3_Children1_id = Children0_Children0_Children0_Children3_Children1["id"]; // 21
      const char* Children0_Children0_Children0_Children3_Children1_Text = Children0_Children0_Children0_Children3_Children1["Text"]; // "Fan Control #2"

      const char* Children0_Children0_Children0_Children3_Children1_Min = Children0_Children0_Children0_Children3_Children1["Min"]; // "100,0 %"
      const char* Children0_Children0_Children0_Children3_Children1_Value = Children0_Children0_Children0_Children3_Children1["Value"]; // "100,0 %"
      const char* Children0_Children0_Children0_Children3_Children1_Max = Children0_Children0_Children0_Children3_Children1["Max"]; // "100,0 %"
      const char* Children0_Children0_Children0_Children3_Children1_ImageURL = Children0_Children0_Children0_Children3_Children1["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children0_Children0_Children3_Children2 = Children0_Children0_Children0_Children3_Children[2];
      int Children0_Children0_Children0_Children3_Children2_id = Children0_Children0_Children0_Children3_Children2["id"]; // 22
      const char* Children0_Children0_Children0_Children3_Children2_Text = Children0_Children0_Children0_Children3_Children2["Text"]; // "Fan Control #3"

      const char* Children0_Children0_Children0_Children3_Children2_Min = Children0_Children0_Children0_Children3_Children2["Min"]; // "45,5 %"
      const char* Children0_Children0_Children0_Children3_Children2_Value = Children0_Children0_Children0_Children3_Children2["Value"]; // "45,5 %"
      const char* Children0_Children0_Children0_Children3_Children2_Max = Children0_Children0_Children0_Children3_Children2["Max"]; // "45,5 %"
      const char* Children0_Children0_Children0_Children3_Children2_ImageURL = Children0_Children0_Children0_Children3_Children2["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children0_Children0_Children3_Min = Children0_Children0_Children0_Children3["Min"]; // ""
      const char* Children0_Children0_Children0_Children3_Value = Children0_Children0_Children0_Children3["Value"]; // ""
      const char* Children0_Children0_Children0_Children3_Max = Children0_Children0_Children0_Children3["Max"]; // ""
      const char* Children0_Children0_Children0_Children3_ImageURL = Children0_Children0_Children0_Children3["ImageURL"]; // "images_icon/control.png"

      const char* Children0_Children0_Children0_Min = Children0_Children0_Children0["Min"]; // ""
      const char* Children0_Children0_Children0_Value = Children0_Children0_Children0["Value"]; // ""
      const char* Children0_Children0_Children0_Max = Children0_Children0_Children0["Max"]; // ""
      const char* Children0_Children0_Children0_ImageURL = Children0_Children0_Children0["ImageURL"]; // "images_icon/chip.png"

      const char* Children0_Children0_Min = Children0_Children0["Min"]; // ""
      const char* Children0_Children0_Value = Children0_Children0["Value"]; // ""
      const char* Children0_Children0_Max = Children0_Children0["Max"]; // ""
      const char* Children0_Children0_ImageURL = Children0_Children0["ImageURL"]; // "images_icon/mainboard.png"

      JsonObject& Children0_Children1 = Children0_Children[1];
      int Children0_Children1_id = Children0_Children1["id"]; // 23
      const char* Children0_Children1_Text = Children0_Children1["Text"]; // "AMD Athlon II X4 641"

      JsonArray& Children0_Children1_Children = Children0_Children1["Children"];

      JsonObject& Children0_Children1_Children0 = Children0_Children1_Children[0];
      int Children0_Children1_Children0_id = Children0_Children1_Children0["id"]; // 24
      const char* Children0_Children1_Children0_Text = Children0_Children1_Children0["Text"]; // "Clocks"

      JsonArray& Children0_Children1_Children0_Children = Children0_Children1_Children0["Children"];

      JsonObject& Children0_Children1_Children0_Children0 = Children0_Children1_Children0_Children[0];
      int Children0_Children1_Children0_Children0_id = Children0_Children1_Children0_Children0["id"]; // 25
      const char* Children0_Children1_Children0_Children0_Text = Children0_Children1_Children0_Children0["Text"]; // "Bus Speed"

      const char* Children0_Children1_Children0_Children0_Min = Children0_Children1_Children0_Children0["Min"]; // "100 MHz"
      const char* Children0_Children1_Children0_Children0_Value = Children0_Children1_Children0_Children0["Value"]; // "100 MHz"
      const char* Children0_Children1_Children0_Children0_Max = Children0_Children1_Children0_Children0["Max"]; // "100 MHz"
      const char* Children0_Children1_Children0_Children0_ImageURL = Children0_Children1_Children0_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children1_Children0_Children1 = Children0_Children1_Children0_Children[1];
      int Children0_Children1_Children0_Children1_id = Children0_Children1_Children0_Children1["id"]; // 26
      const char* Children0_Children1_Children0_Children1_Text = Children0_Children1_Children0_Children1["Text"]; // "CPU Core #1"

      const char* Children0_Children1_Children0_Children1_Min = Children0_Children1_Children0_Children1["Min"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children1_Value = Children0_Children1_Children0_Children1["Value"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children1_Max = Children0_Children1_Children0_Children1["Max"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children1_ImageURL = Children0_Children1_Children0_Children1["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children1_Children0_Children2 = Children0_Children1_Children0_Children[2];
      int Children0_Children1_Children0_Children2_id = Children0_Children1_Children0_Children2["id"]; // 27
      const char* Children0_Children1_Children0_Children2_Text = Children0_Children1_Children0_Children2["Text"]; // "CPU Core #2"

      const char* Children0_Children1_Children0_Children2_Min = Children0_Children1_Children0_Children2["Min"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children2_Value = Children0_Children1_Children0_Children2["Value"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children2_Max = Children0_Children1_Children0_Children2["Max"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children2_ImageURL = Children0_Children1_Children0_Children2["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children1_Children0_Children3 = Children0_Children1_Children0_Children[3];
      int Children0_Children1_Children0_Children3_id = Children0_Children1_Children0_Children3["id"]; // 28
      const char* Children0_Children1_Children0_Children3_Text = Children0_Children1_Children0_Children3["Text"]; // "CPU Core #3"

      const char* Children0_Children1_Children0_Children3_Min = Children0_Children1_Children0_Children3["Min"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children3_Value = Children0_Children1_Children0_Children3["Value"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children3_Max = Children0_Children1_Children0_Children3["Max"]; // "2795 MHz"
      const char* Children0_Children1_Children0_Children3_ImageURL = Children0_Children1_Children0_Children3["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children1_Children0_Min = Children0_Children1_Children0["Min"]; // ""
      const char* Children0_Children1_Children0_Value = Children0_Children1_Children0["Value"]; // ""
      const char* Children0_Children1_Children0_Max = Children0_Children1_Children0["Max"]; // ""
      const char* Children0_Children1_Children0_ImageURL = Children0_Children1_Children0["ImageURL"]; // "images_icon/clock.png"

      JsonObject& Children0_Children1_Children1 = Children0_Children1_Children[1];
      int Children0_Children1_Children1_id = Children0_Children1_Children1["id"]; // 30
      const char* Children0_Children1_Children1_Text = Children0_Children1_Children1["Text"]; // "Temperatures"

      JsonObject& Children0_Children1_Children1_Children0 = Children0_Children1_Children1["Children"][0];
      int Children0_Children1_Children1_Children0_id = Children0_Children1_Children1_Children0["id"]; // 31
      const char* Children0_Children1_Children1_Children0_Text = Children0_Children1_Children1_Children0["Text"]; // "Core #1 - #4"

      const char* Children0_Children1_Children1_Children0_Min = Children0_Children1_Children1_Children0["Min"]; // "5,0 °C"
      const char* Children0_Children1_Children1_Children0_Value = Children0_Children1_Children1_Children0["Value"]; // "27,4 °C"
      const char* Children0_Children1_Children1_Children0_Max = Children0_Children1_Children1_Children0["Max"]; // "31,1 °C"
      const char* Children0_Children1_Children1_Children0_ImageURL = Children0_Children1_Children1_Children0["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children1_Children1_Min = Children0_Children1_Children1["Min"]; // ""
      const char* Children0_Children1_Children1_Value = Children0_Children1_Children1["Value"]; // ""
      const char* Children0_Children1_Children1_Max = Children0_Children1_Children1["Max"]; // ""
      const char* Children0_Children1_Children1_ImageURL = Children0_Children1_Children1["ImageURL"]; // "images_icon/temperature.png"
      value = Children0_Children1_Children1_Children0_Value;
      Serial.println(value);

      JsonObject& Children0_Children1_Children2 = Children0_Children1_Children[2];
      int Children0_Children1_Children2_id = Children0_Children1_Children2["id"]; // 32
      const char* Children0_Children1_Children2_Text = Children0_Children1_Children2["Text"]; // "Load"

      JsonArray& Children0_Children1_Children2_Children = Children0_Children1_Children2["Children"];

      JsonObject& Children0_Children1_Children2_Children0 = Children0_Children1_Children2_Children[0];
      int Children0_Children1_Children2_Children0_id = Children0_Children1_Children2_Children0["id"]; // 33
      const char* Children0_Children1_Children2_Children0_Text = Children0_Children1_Children2_Children0["Text"]; // "CPU Total"

      const char* Children0_Children1_Children2_Children0_Min = Children0_Children1_Children2_Children0["Min"]; // "0,0 %"
      const char* Children0_Children1_Children2_Children0_Value = Children0_Children1_Children2_Children0["Value"]; // "35,9 %"
      const char* Children0_Children1_Children2_Children0_Max = Children0_Children1_Children2_Children0["Max"]; // "100,0 %"
      const char* Children0_Children1_Children2_Children0_ImageURL = Children0_Children1_Children2_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children1_Children2_Children1 = Children0_Children1_Children2_Children[1];
      int Children0_Children1_Children2_Children1_id = Children0_Children1_Children2_Children1["id"]; // 34
      const char* Children0_Children1_Children2_Children1_Text = Children0_Children1_Children2_Children1["Text"]; // "CPU Core #1"

      const char* Children0_Children1_Children2_Children1_Min = Children0_Children1_Children2_Children1["Min"]; // "0,0 %"
      const char* Children0_Children1_Children2_Children1_Value = Children0_Children1_Children2_Children1["Value"]; // "18,8 %"
      const char* Children0_Children1_Children2_Children1_Max = Children0_Children1_Children2_Children1["Max"]; // "100,0 %"
      const char* Children0_Children1_Children2_Children1_ImageURL = Children0_Children1_Children2_Children1["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children1_Children2_Children2 = Children0_Children1_Children2_Children[2];
      int Children0_Children1_Children2_Children2_id = Children0_Children1_Children2_Children2["id"]; // 35
      const char* Children0_Children1_Children2_Children2_Text = Children0_Children1_Children2_Children2["Text"]; // "CPU Core #2"

      const char* Children0_Children1_Children2_Children2_Min = Children0_Children1_Children2_Children2["Min"]; // "0,0 %"
      const char* Children0_Children1_Children2_Children2_Value = Children0_Children1_Children2_Children2["Value"]; // "15,6 %"
      const char* Children0_Children1_Children2_Children2_Max = Children0_Children1_Children2_Children2["Max"]; // "100,0 %"
      const char* Children0_Children1_Children2_Children2_ImageURL = Children0_Children1_Children2_Children2["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children1_Children2_Children3 = Children0_Children1_Children2_Children[3];
      int Children0_Children1_Children2_Children3_id = Children0_Children1_Children2_Children3["id"]; // 36
      const char* Children0_Children1_Children2_Children3_Text = Children0_Children1_Children2_Children3["Text"]; // "CPU Core #3"

      const char* Children0_Children1_Children2_Children3_Min = Children0_Children1_Children2_Children3["Min"]; // "0,0 %"
      const char* Children0_Children1_Children2_Children3_Value = Children0_Children1_Children2_Children3["Value"]; // "78,1 %"
      const char* Children0_Children1_Children2_Children3_Max = Children0_Children1_Children2_Children3["Max"]; // "100,0 %"
      const char* Children0_Children1_Children2_Children3_ImageURL = Children0_Children1_Children2_Children3["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children1_Children2_Min = Children0_Children1_Children2["Min"]; // ""
      const char* Children0_Children1_Children2_Value = Children0_Children1_Children2["Value"]; // ""
      const char* Children0_Children1_Children2_Max = Children0_Children1_Children2["Max"]; // ""
      const char* Children0_Children1_Children2_ImageURL = Children0_Children1_Children2["ImageURL"]; // "images_icon/load.png"

      const char* Children0_Children1_Min = Children0_Children1["Min"]; // ""
      const char* Children0_Children1_Value = Children0_Children1["Value"]; // ""
      const char* Children0_Children1_Max = Children0_Children1["Max"]; // ""
      const char* Children0_Children1_ImageURL = Children0_Children1["ImageURL"]; // "images_icon/cpu.png"

      JsonObject& Children0_Children2 = Children0_Children[2];
      int Children0_Children2_id = Children0_Children2["id"]; // 38
      const char* Children0_Children2_Text = Children0_Children2["Text"]; // "Generic Memory"

      JsonObject& Children0_Children2_Children0 = Children0_Children2["Children"][0];
      int Children0_Children2_Children0_id = Children0_Children2_Children0["id"]; // 39
      const char* Children0_Children2_Children0_Text = Children0_Children2_Children0["Text"]; // "Load"

      JsonObject& Children0_Children2_Children0_Children0 = Children0_Children2_Children0["Children"][0];
      int Children0_Children2_Children0_Children0_id = Children0_Children2_Children0_Children0["id"]; // 40
      const char* Children0_Children2_Children0_Children0_Text = Children0_Children2_Children0_Children0["Text"]; // "Memory"

      const char* Children0_Children2_Children0_Children0_Min = Children0_Children2_Children0_Children0["Min"]; // "28,1 %"
      const char* Children0_Children2_Children0_Children0_Value = Children0_Children2_Children0_Children0["Value"]; // "85,4 %"
      const char* Children0_Children2_Children0_Children0_Max = Children0_Children2_Children0_Children0["Max"]; // "97,4 %"
      const char* Children0_Children2_Children0_Children0_ImageURL = Children0_Children2_Children0_Children0["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children2_Children0_Min = Children0_Children2_Children0["Min"]; // ""
      const char* Children0_Children2_Children0_Value = Children0_Children2_Children0["Value"]; // ""
      const char* Children0_Children2_Children0_Max = Children0_Children2_Children0["Max"]; // ""
      const char* Children0_Children2_Children0_ImageURL = Children0_Children2_Children0["ImageURL"]; // "images_icon/load.png"

      JsonObject& Children0_Children2_Children1 = Children0_Children2["Children"][1];
      int Children0_Children2_Children1_id = Children0_Children2_Children1["id"]; // 41
      const char* Children0_Children2_Children1_Text = Children0_Children2_Children1["Text"]; // "Data"

      JsonObject& Children0_Children2_Children1_Children0 = Children0_Children2_Children1["Children"][0];
      int Children0_Children2_Children1_Children0_id = Children0_Children2_Children1_Children0["id"]; // 42
      const char* Children0_Children2_Children1_Children0_Text = Children0_Children2_Children1_Children0["Text"]; // "Used Memory"

      const char* Children0_Children2_Children1_Children0_Min = Children0_Children2_Children1_Children0["Min"]; // "1,1 GB"
      const char* Children0_Children2_Children1_Children0_Value = Children0_Children2_Children1_Children0["Value"]; // "3,4 GB"
      const char* Children0_Children2_Children1_Children0_Max = Children0_Children2_Children1_Children0["Max"]; // "3,9 GB"
      const char* Children0_Children2_Children1_Children0_ImageURL = Children0_Children2_Children1_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children2_Children1_Children1 = Children0_Children2_Children1["Children"][1];
      int Children0_Children2_Children1_Children1_id = Children0_Children2_Children1_Children1["id"]; // 43
      const char* Children0_Children2_Children1_Children1_Text = Children0_Children2_Children1_Children1["Text"]; // "Available Memory"

      const char* Children0_Children2_Children1_Children1_Min = Children0_Children2_Children1_Children1["Min"]; // "0,1 GB"
      const char* Children0_Children2_Children1_Children1_Value = Children0_Children2_Children1_Children1["Value"]; // "0,6 GB"
      const char* Children0_Children2_Children1_Children1_Max = Children0_Children2_Children1_Children1["Max"]; // "2,9 GB"
      const char* Children0_Children2_Children1_Children1_ImageURL = Children0_Children2_Children1_Children1["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children2_Children1_Min = Children0_Children2_Children1["Min"]; // ""
      const char* Children0_Children2_Children1_Value = Children0_Children2_Children1["Value"]; // ""
      const char* Children0_Children2_Children1_Max = Children0_Children2_Children1["Max"]; // ""
      const char* Children0_Children2_Children1_ImageURL = Children0_Children2_Children1["ImageURL"]; // "images_icon/power.png"

      const char* Children0_Children2_Min = Children0_Children2["Min"]; // ""
      const char* Children0_Children2_Value = Children0_Children2["Value"]; // ""
      const char* Children0_Children2_Max = Children0_Children2["Max"]; // ""
      const char* Children0_Children2_ImageURL = Children0_Children2["ImageURL"]; // "images_icon/ram.png"

      JsonObject& Children0_Children3 = Children0_Children[3];
      int Children0_Children3_id = Children0_Children3["id"]; // 44
      const char* Children0_Children3_Text = Children0_Children3["Text"]; // "NVIDIA GeForce GTS 450"

      JsonArray& Children0_Children3_Children = Children0_Children3["Children"];

      JsonObject& Children0_Children3_Children0 = Children0_Children3_Children[0];
      int Children0_Children3_Children0_id = Children0_Children3_Children0["id"]; // 45
      const char* Children0_Children3_Children0_Text = Children0_Children3_Children0["Text"]; // "Clocks"

      JsonArray& Children0_Children3_Children0_Children = Children0_Children3_Children0["Children"];

      JsonObject& Children0_Children3_Children0_Children0 = Children0_Children3_Children0_Children[0];
      int Children0_Children3_Children0_Children0_id = Children0_Children3_Children0_Children0["id"]; // 46
      const char* Children0_Children3_Children0_Children0_Text = Children0_Children3_Children0_Children0["Text"]; // "GPU Core"

      const char* Children0_Children3_Children0_Children0_Min = Children0_Children3_Children0_Children0["Min"]; // "51 MHz"
      const char* Children0_Children3_Children0_Children0_Value = Children0_Children3_Children0_Children0["Value"]; // "51 MHz"
      const char* Children0_Children3_Children0_Children0_Max = Children0_Children3_Children0_Children0["Max"]; // "783 MHz"
      const char* Children0_Children3_Children0_Children0_ImageURL = Children0_Children3_Children0_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children3_Children0_Children1 = Children0_Children3_Children0_Children[1];
      int Children0_Children3_Children0_Children1_id = Children0_Children3_Children0_Children1["id"]; // 47
      const char* Children0_Children3_Children0_Children1_Text = Children0_Children3_Children0_Children1["Text"]; // "GPU Memory"

      const char* Children0_Children3_Children0_Children1_Min = Children0_Children3_Children0_Children1["Min"]; // "135 MHz"
      const char* Children0_Children3_Children0_Children1_Value = Children0_Children3_Children0_Children1["Value"]; // "135 MHz"
      const char* Children0_Children3_Children0_Children1_Max = Children0_Children3_Children0_Children1["Max"]; // "1804 MHz"
      const char* Children0_Children3_Children0_Children1_ImageURL = Children0_Children3_Children0_Children1["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children3_Children0_Children2 = Children0_Children3_Children0_Children[2];
      int Children0_Children3_Children0_Children2_id = Children0_Children3_Children0_Children2["id"]; // 48
      const char* Children0_Children3_Children0_Children2_Text = Children0_Children3_Children0_Children2["Text"]; // "GPU Shader"

      const char* Children0_Children3_Children0_Children2_Min = Children0_Children3_Children0_Children2["Min"]; // "101 MHz"
      const char* Children0_Children3_Children0_Children2_Value = Children0_Children3_Children0_Children2["Value"]; // "101 MHz"
      const char* Children0_Children3_Children0_Children2_Max = Children0_Children3_Children0_Children2["Max"]; // "1566 MHz"
      const char* Children0_Children3_Children0_Children2_ImageURL = Children0_Children3_Children0_Children2["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children3_Children0_Min = Children0_Children3_Children0["Min"]; // ""
      const char* Children0_Children3_Children0_Value = Children0_Children3_Children0["Value"]; // ""
      const char* Children0_Children3_Children0_Max = Children0_Children3_Children0["Max"]; // ""
      const char* Children0_Children3_Children0_ImageURL = Children0_Children3_Children0["ImageURL"]; // "images_icon/clock.png"

      JsonObject& Children0_Children3_Children1 = Children0_Children3_Children[1];
      int Children0_Children3_Children1_id = Children0_Children3_Children1["id"]; // 49
      const char* Children0_Children3_Children1_Text = Children0_Children3_Children1["Text"]; // "Temperatures"

      JsonObject& Children0_Children3_Children1_Children0 = Children0_Children3_Children1["Children"][0];
      int Children0_Children3_Children1_Children0_id = Children0_Children3_Children1_Children0["id"]; // 50
      const char* Children0_Children3_Children1_Children0_Text = Children0_Children3_Children1_Children0["Text"]; // "GPU Core"

      const char* Children0_Children3_Children1_Children0_Min = Children0_Children3_Children1_Children0["Min"]; // "34,0 °C"
      const char* Children0_Children3_Children1_Children0_Value = Children0_Children3_Children1_Children0["Value"]; // "38,0 °C"
      const char* Children0_Children3_Children1_Children0_Max = Children0_Children3_Children1_Children0["Max"]; // "42,0 °C"
      const char* Children0_Children3_Children1_Children0_ImageURL = Children0_Children3_Children1_Children0["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children3_Children1_Min = Children0_Children3_Children1["Min"]; // ""
      const char* Children0_Children3_Children1_Value = Children0_Children3_Children1["Value"]; // ""
      const char* Children0_Children3_Children1_Max = Children0_Children3_Children1["Max"]; // ""
      const char* Children0_Children3_Children1_ImageURL = Children0_Children3_Children1["ImageURL"]; // "images_icon/temperature.png"

      JsonObject& Children0_Children3_Children2 = Children0_Children3_Children[2];
      int Children0_Children3_Children2_id = Children0_Children3_Children2["id"]; // 51
      const char* Children0_Children3_Children2_Text = Children0_Children3_Children2["Text"]; // "Load"

      JsonArray& Children0_Children3_Children2_Children = Children0_Children3_Children2["Children"];

      JsonObject& Children0_Children3_Children2_Children0 = Children0_Children3_Children2_Children[0];
      int Children0_Children3_Children2_Children0_id = Children0_Children3_Children2_Children0["id"]; // 52
      const char* Children0_Children3_Children2_Children0_Text = Children0_Children3_Children2_Children0["Text"]; // "GPU Core"

      const char* Children0_Children3_Children2_Children0_Min = Children0_Children3_Children2_Children0["Min"]; // "0,0 %"
      const char* Children0_Children3_Children2_Children0_Value = Children0_Children3_Children2_Children0["Value"]; // "1,0 %"
      const char* Children0_Children3_Children2_Children0_Max = Children0_Children3_Children2_Children0["Max"]; // "61,0 %"
      const char* Children0_Children3_Children2_Children0_ImageURL = Children0_Children3_Children2_Children0["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children3_Children2_Children1 = Children0_Children3_Children2_Children[1];
      int Children0_Children3_Children2_Children1_id = Children0_Children3_Children2_Children1["id"]; // 53
      const char* Children0_Children3_Children2_Children1_Text = Children0_Children3_Children2_Children1["Text"]; // "GPU Memory Controller"

      const char* Children0_Children3_Children2_Children1_Min = Children0_Children3_Children2_Children1["Min"]; // "1,0 %"
      const char* Children0_Children3_Children2_Children1_Value = Children0_Children3_Children2_Children1["Value"]; // "7,0 %"
      const char* Children0_Children3_Children2_Children1_Max = Children0_Children3_Children2_Children1["Max"]; // "41,0 %"
      const char* Children0_Children3_Children2_Children1_ImageURL = Children0_Children3_Children2_Children1["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children3_Children2_Children2 = Children0_Children3_Children2_Children[2];
      int Children0_Children3_Children2_Children2_id = Children0_Children3_Children2_Children2["id"]; // 54
      const char* Children0_Children3_Children2_Children2_Text = Children0_Children3_Children2_Children2["Text"]; // "GPU Video Engine"

      const char* Children0_Children3_Children2_Children2_Min = Children0_Children3_Children2_Children2["Min"]; // "0,0 %"
      const char* Children0_Children3_Children2_Children2_Value = Children0_Children3_Children2_Children2["Value"]; // "0,0 %"
      const char* Children0_Children3_Children2_Children2_Max = Children0_Children3_Children2_Children2["Max"]; // "16,0 %"
      const char* Children0_Children3_Children2_Children2_ImageURL = Children0_Children3_Children2_Children2["ImageURL"]; // "images/transparent.png"

      JsonObject& Children0_Children3_Children2_Children3 = Children0_Children3_Children2_Children[3];
      int Children0_Children3_Children2_Children3_id = Children0_Children3_Children2_Children3["id"]; // 55
      const char* Children0_Children3_Children2_Children3_Text = Children0_Children3_Children2_Children3["Text"]; // "GPU Memory"

      const char* Children0_Children3_Children2_Children3_Min = Children0_Children3_Children2_Children3["Min"]; // "9,1 %"
      const char* Children0_Children3_Children2_Children3_Value = Children0_Children3_Children2_Children3["Value"]; // "23,9 %"
      const char* Children0_Children3_Children2_Children3_Max = Children0_Children3_Children2_Children3["Max"]; // "25,4 %"
      const char* Children0_Children3_Children2_Children3_ImageURL = Children0_Children3_Children2_Children3["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children3_Children2_Min = Children0_Children3_Children2["Min"]; // ""
      const char* Children0_Children3_Children2_Value = Children0_Children3_Children2["Value"]; // ""
      const char* Children0_Children3_Children2_Max = Children0_Children3_Children2["Max"]; // ""
      const char* Children0_Children3_Children2_ImageURL = Children0_Children3_Children2["ImageURL"]; // "images_icon/load.png"

      JsonObject& Children0_Children3_Children3 = Children0_Children3_Children[3];
      int Children0_Children3_Children3_id = Children0_Children3_Children3["id"]; // 56
      const char* Children0_Children3_Children3_Text = Children0_Children3_Children3["Text"]; // "Fans"

      JsonObject& Children0_Children3_Children3_Children0 = Children0_Children3_Children3["Children"][0];
      int Children0_Children3_Children3_Children0_id = Children0_Children3_Children3_Children0["id"]; // 57
      const char* Children0_Children3_Children3_Children0_Text = Children0_Children3_Children3_Children0["Text"]; // "GPU"

      const char* Children0_Children3_Children3_Children0_Min = Children0_Children3_Children3_Children0["Min"]; // "1230 RPM"
      const char* Children0_Children3_Children3_Children0_Value = Children0_Children3_Children3_Children0["Value"]; // "1320 RPM"
      const char* Children0_Children3_Children3_Children0_Max = Children0_Children3_Children3_Children0["Max"]; // "1320 RPM"
      const char* Children0_Children3_Children3_Children0_ImageURL = Children0_Children3_Children3_Children0["ImageURL"]; // "images/transparent.png"

      const char* Children0_Children3_Children3_Min = Children0_Children3_Children3["Min"]; // ""
      const char* Children0_Children3_Children3_Value = Children0_Children3_Children3["Value"]; // ""
      const char* Children0_Children3_Children3_Max = Children0_Children3_Children3["Max"]; // ""
      const char* Children0_Children3_Children3_ImageURL = Children0_Children3_Children3["ImageURL"]; // "images_icon/fan.png"

      const char* Children0_Children3_Min = Children0_Children3["Min"]; // ""
      const char* Children0_Children3_Value = Children0_Children3["Value"]; // ""
      const char* Children0_Children3_Max = Children0_Children3["Max"]; // ""
      const char* Children0_Children3_ImageURL = Children0_Children3["ImageURL"]; // "images_icon/nvidia.png"

      const char* Children0_Min = Children0["Min"]; // ""
      const char* Children0_Value = Children0["Value"]; // ""
      const char* Children0_Max = Children0["Max"]; // ""
      const char* Children0_ImageURL = Children0["ImageURL"]; // "images_icon/computer.png"

      const char* Min = root["Min"]; // "Min"
      const char* Value = root["Value"]; // "Value"
      const char* Max = root["Max"]; // "Max"
      const char* ImageURL = root["ImageURL"]; // ""
      return;
    }
    http.end();   //Закрытие соединения
  }
}
