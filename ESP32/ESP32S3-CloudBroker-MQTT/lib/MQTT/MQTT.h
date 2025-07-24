#ifndef MQTT_H
#define MQTT_H
#include "PubSubClient.h"
#include "WiFi.h"





void MQTT_Init(void);
void TASK_Capacity_Report(int capacity);

#endif //MQTT_H