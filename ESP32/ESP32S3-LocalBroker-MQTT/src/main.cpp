#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include "MQTT.h"
#include "WS2812.h"

// extern WiFiClient espClient; // ESP32WiFi模型定义
// extern PubSubClient client(espClient);

void setup()
{
    Serial.begin(115200);
    MQTT_Init();
    InitWS2812();
}

void loop()
{
    TASK_Capacity_Report(LED_Status);
    client.loop(); // 处理接收消息
    delay(1000);
}
