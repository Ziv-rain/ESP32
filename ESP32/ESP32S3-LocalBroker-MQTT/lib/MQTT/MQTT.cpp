/*
 * 概述：此文件包含ESP32与MQTT服务器连接相关函数
 */

#include "MQTT.h"
#include "WS2812.h"

WiFiClient espClient; // ESP32WiFi模型定义
PubSubClient client(espClient);
bool LED_Status = false;

/* MQTT 连接配置 */
/*-----------------------------------------------------*/

// 连接 WiFi
const char *ssid = "iQOO 7";       // 请替换为你的 WiFi SSID
const char *password = "00000000"; // 请替换为你的 WiFi 密码

// MQTT 服务器信息
const char *mqttServer = "192.168.213.199"; // 请替换为你的 MQTT 服务器地址
const int mqttPort = 1883;                  // 请替换为你的 MQTT 端口（建议使用 TLS/SSL）
const char *clientId = "mqttx_Ziv_ESP32";   // 请替换为你的 MQTT 客户端 ID
const char *mqttUser = "Ziv_ESP32";         // 请替换为你的 MQTT 用户名
const char *mqttPassword = "Ziv";           // 请替换为你的 MQTT 密码

const char *topic_Commands_Receive = "testtopic/1";
const char *topic_Commands_Response = "testtopic/2";

/*******************************************************/

void handleTestTopicMessage(const char *message)
{
    // 示例：解析JSON格式消息
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, message);

    if (!error)
    {
        const char *msg = doc["msg"];
        Serial.print("Handling message: ");
        Serial.println(msg);

        // 根据消息内容执行操作
        if (strcmp(msg, "ledOn") == 0)
        {
            ledOn(RED);
            LED_Status = true;
        }
        if (strcmp(msg, "ledOff") == 0)
        {
            ledOff();
            LED_Status = false;
        }
    }
    else
    {
        Serial.print("JSON parsing failed: ");
        Serial.println(error.c_str());
    }
}

/*
 * 作用：   监听服务端下发指令并处理回调函数
 * 参数1：  订阅的topic
 * 参数2：  接收到的内容
 * 参数3：  内容的长度
 * 返回值： 无
 */
void callback(char *topic, byte *payload, unsigned int length)
{
    Serial.print("Message received on [");
    Serial.print(topic);
    Serial.println("]");

    // 安全处理接收到的消息
    char message[length + 1];
    memcpy(message, payload, length);
    message[length] = '\0'; // 添加终止符

    Serial.println("Received payload:");
    Serial.println(message);

    // 这里添加您的消息处理逻辑
    if (strstr(topic, "testtopic/1"))
    {
        handleTestTopicMessage(message);
    }
}

/*
 * 作用：  ESP32的WiFi初始化以及与MQTT服务器的连接
 * 参数：  无
 * 返回值：无
 */
void MQTT_Init()
{
    // WiFi网络连接部分
    WiFi.begin(ssid, password); // 开启ESP32的WiFi
    while (WiFi.status() != WL_CONNECTED)
    { // ESP尝试连接到WiFi网络
        delay(3000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to the WiFi network");

    // MQTT服务器连接部分
    client.setServer(mqttServer, mqttPort); // 设置连接到MQTT服务器的参数

    client.setKeepAlive(60); // 设置心跳时间

    while (!client.connected())
    { // 尝试与MQTT服务器建立连接
        Serial.println("Connecting to MQTT...");

        if (client.connect(clientId, mqttUser, mqttPassword))
        {

            Serial.println("connected");

            // 添加订阅（匹配第2、3张图中的主题）
            if (client.subscribe(topic_Commands_Receive))
            {
                Serial.println("Subscribed to testtopic/1");
            }
        }
        else
        {

            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(6000);
        }
    }
    // 接受平台下发内容的初始化
    client.setCallback(callback); // 可以接受任何平台下发的内容
}

void TASK_Capacity_Report(bool LED_Status)
{
    // 1. 创建最简化的JSON文档
    constexpr size_t BUFFER_SIZE = 50; // 大幅减小缓冲区
    StaticJsonDocument<BUFFER_SIZE> doc;

    // 2. 添加直接键值对
    doc["device"] = "ESP32-WS2812";
    doc["status"] = LED_Status ? "ON" : "OFF"; // 直接使用字符串状态

    // 3. 序列化到缓冲区
    char jsonBuffer[BUFFER_SIZE];
    serializeJson(doc, jsonBuffer);

    // 4. 调试输出
    Serial.print("LED Status: ");
    Serial.println(jsonBuffer);

    // 5. 发布消息
    if (client.publish(topic_Commands_Response, jsonBuffer))
    {
        Serial.println("Status sent successfully");
    }
    else
    {
        Serial.println("Failed to send status");
    }
}
