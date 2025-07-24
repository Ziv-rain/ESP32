#include "Arduino.h"
#include <WiFi.h>

#define ISSERVER 0      //1-服务端代码
                        //0-客户端代码

const char *ssid = "iQOO 7";       // 你的网络名称
const char *password = "00000000"; // 你的网络密码

#if ISSERVER

WiFiServer server(8080); // 创建TCP服务器，监听8080端口
WiFiClient client;

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println("Connecting to WIFI...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("WiFi connected!");
    Serial.print("IP location: ");
    Serial.println(WiFi.localIP()); // 记下这个IP地址，客户端将连接到这里

    server.begin();
    Serial.println("TCP server has been started and is waiting for the client connection...");
}

void loop()
{
    // 检查是否有新客户端连接
    if (!client || !client.connected())
    {
        client = server.available();
        if (client)
        {
            Serial.println("New client has been connected!");
        }
    }

    // 如果有客户端连接且有数据可读
    if (client && client.connected() && client.available())
    {
        String message = client.readStringUntil('\n');
        Serial.print("Receved message!");
        Serial.println(message);

        // 回复客户端
        String reply = "Server has been receved message:" + message;
        client.println(reply);
        Serial.println("Has replied client.");
    }

    // 从串口读取数据并发送给客户端
    if (client && client.connected() && Serial.available())
    {
        String message = Serial.readStringUntil('\n');
        client.println(message);
        Serial.println("Sending message " + message);
    }

    delay(10); // 短暂延时以防止CPU过载
}

#else
const char *serverIP = "192.168.101.220"; // 更改为服务器ESP32S3的IP地址
const int serverPort = 8080;

WiFiClient client;

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("WiFi connected!");
    Serial.print("IP location: ");
    Serial.println(WiFi.localIP());

    Serial.print("Connected to the TCP server...");

    while (!client.connect(serverIP, serverPort))
    {
        Serial.print(".");
        delay(1000);
    }

    Serial.println("Connected to the server");
    client.println("Hello! I'm client.");
}

void loop()
{
    // 检查是否连接到服务器
    if (!client.connected())
    {
        Serial.println("The connection to the server has been disconnected and is being reconnected...");
        if (client.connect(serverIP, serverPort))
        {
            Serial.println("Reconnection successful!");
        }
        else
        {
            Serial.println("Reconnection failed. Try again in 1 second...");
            delay(1000);
            return;
        }
    }

    // 如果服务器有数据发送过来
    if (client.available())
    {
        String message = client.readStringUntil('\n');
        Serial.print("Receved server's message: ");
        Serial.println(message);
    }

    // 从串口读取数据并发送给服务器
    if (Serial.available())
    {
        String message = Serial.readStringUntil('\n');
        client.println(message);
        Serial.println("Sending message:" + message);
    }

    delay(10); // 短暂延时以防止CPU过载
}

#endif