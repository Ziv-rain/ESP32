#ifndef MQTT_H
#define MQTT_H
#include "ArduinoJson.h"
#include "PubSubClient.h"
#include "WiFi.h"


extern WiFiClient espClient; // ESP32WiFi模型定义
extern PubSubClient client;
extern bool LED_Status;

void MQTT_Init(void);
void TASK_Capacity_Report(bool ledStatus);

#endif //MQTT_H