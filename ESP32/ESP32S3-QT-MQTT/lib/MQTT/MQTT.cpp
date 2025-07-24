/*
 * 概述：此文件包含ESP32与MQTT服务器连接相关函数
 */

#include "MQTT.h"
#include "WS2812.h"

// 全局变量定义
WiFiClient espClient;                 // WiFi客户端对象
PubSubClient client(espClient);       // MQTT客户端对象
volatile bool blinkFlag = false;      // LED闪烁标志
bool currentLEDState = false;         // LED当前状态
COLOR ledColor = RED;                 // 当前LED颜色（默认红色）
char power[20] = "Off";               // 电源状态
char color[20] = "None";              // 颜色状态
char mode[20] = "Constant light mode";// 工作模式

/* MQTT 连接配置 */
// 连接 WiFi
const char *ssid = "iQOO 7";       // 请替换为你的 WiFi SSID
const char *password = "00000000"; // 请替换为你的 WiFi 密码
// MQTT 服务器信息
const char *mqttServer = "192.168.213.199"; // 请替换为你的 MQTT 服务器地址
const int mqttPort = 1883;                // 请替换为你的 MQTT 端口（建议使用 TLS/SSL）
const char *clientId = "mqtt_Ziv_ESP32"; // 请替换为你的 MQTT 客户端 ID
const char *mqttUser = "Ziv_ESP32";       // 请替换为你的 MQTT 用户名
const char *mqttPassword = "Ziv";         // 请替换为你的 MQTT 密码
//主题设置
const char *topic_Commands_Receive = "ESP32/LED/Control";
const char *topic_Commands_Response = "ESP32/LED/Report";

/*******************************************************/
/**
 * @brief 处理接收到的MQTT控制消息
 * @param message JSON格式的消息字符串
 */
void handleTestTopicMessage(const char *message)
{
    //解析JSON格式消息
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, message);

    if (!error)
    {
        //调试用
        // Serial.println("Handling message: ");
        // Serial.println(power);
        // Serial.println(color);
        // Serial.println(mode);
        // 从JSON中提取参数
        strncpy(power, doc["power"] | "Off", sizeof(power));
        strncpy(color, doc["color"] | "None", sizeof(color));
        strncpy(mode, doc["mode"] | "Constant light mode", sizeof(mode));

        // 添加字符串结束符保证安全
        power[sizeof(power) - 1] = '\0';
        color[sizeof(color) - 1] = '\0';
        mode[sizeof(mode) - 1] = '\0';
        Serial.println(power);
        Serial.println(color);
        Serial.println(mode);
        SetLED(power, color, mode); // 应用LED设置
    }
    else
    {
        Serial.print("JSON parsing failed: ");
        Serial.println(error.c_str());
    }
}

/**
 * @brief MQTT接收消息回调函数
 * @param topic   消息主题
 * @param payload 消息内容
 * @param length  消息长度
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

    // 这里添加消息处理逻辑
    if (strstr(topic, topic_Commands_Receive))
    {
        handleTestTopicMessage(message);
    }
}

/**
 * @brief 初始化MQTT连接
 * @note 1. 连接WiFi网络
 *       2. 连接MQTT服务器
 *       3. 订阅控制主题
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

            // 添加订阅
            if (client.subscribe(topic_Commands_Receive))
            {
                Serial.print("Subscribed to ");
                Serial.println(topic_Commands_Receive);
            }
        }
        else
        {

            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(6000);
        }
    }
    client.setCallback(callback); // 设置消息回调
}

/**
 * @brief 上报当前设备状态
 * @note 发送JSON格式的状态信息到上报主题
 */
void TASK_Capacity_Report()//发信息
{
    // 1. 创建最简化的JSON文档
    constexpr size_t BUFFER_SIZE = 100; // 大幅减小缓冲区
    StaticJsonDocument<BUFFER_SIZE> doc;

    // 2. 添加直接键值对
    doc["power"] = power;
    doc["color"] = color;
    doc["mode"] = mode;

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

