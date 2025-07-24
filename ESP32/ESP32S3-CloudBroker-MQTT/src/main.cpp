#include <Wire.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include "MQTT.h"



void setup() {
  Serial.begin(115200);
  MQTT_Init();

}

void loop() {
    for (int i = 0; i < 256; i++)
    {
        delay(1000);
        TASK_Capacity_Report(i);
    }
}

