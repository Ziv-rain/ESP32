#ifndef MQTT_H
#define MQTT_H
#include <ArduinoJson.h>  
#include <PubSubClient.h>
#include <WiFi.h>

// 全局变量声明
extern WiFiClient espClient;     // WiFi客户端
extern PubSubClient client;       // MQTT客户端
extern char power[20];            // 电源状态
extern char color[20];            // 颜色状态
extern char mode[20];             // 工作模式

// 函数声明
void MQTT_Init(void);             // 初始化MQTT连接
void TASK_Capacity_Report(void);  // 上报设备状态


#endif //MQTT_H