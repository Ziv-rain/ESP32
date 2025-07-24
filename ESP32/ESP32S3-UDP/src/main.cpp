#include "Arduino.h"
#include <WiFi.h>

#define ISSERVER 1
#if ISSERVER

WiFiUDP Udp; // 声明UDP对象

const char *ssid = "iQOO 7";       // 你的网络名称
const char *password = "00000000"; // 你的网络密码

uint16_t udp_port = 8080; // 存储需要监听的端口号

char incomingPacket[255]; // 存储Udp客户端发过来的数据
char uploadingPacket[255]; // 存储Udp客户端发过来的数据

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
    Serial.println(WiFi.localIP()); 

    Udp.begin(udp_port); // 启动UDP监听这个端口
}

void loop()
{
    /*接收发送过来的Udp数据*/
    int Data_length = Udp.parsePacket(); // 获取接收的数据的长度
    if (Data_length)                     // 如果有数据那么Data_length不为0，无数据Data_length为0
    {
        int len = Udp.read(incomingPacket, 255); // 读取数据，将数据保存在数组incomingPacket中
        if (len > 0)                             // 为了避免获取的数据后面乱码做的判断
        {
            incomingPacket[len] = 0;
        }

        /*将接受到的数据发送回去*/
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort()); // 准备发送数据到目标IP和目标端口
        Udp.print("receive data:");                        // 将数据receive data:放入发送的缓冲区
        Udp.println(incomingPacket);                       // 将接收到的数据放入发送的缓冲区
        Udp.endPacket();                                   // 向目标IP目标端口发送数据
    }

    // 从串口读取数据并发送给服务器
    if (Serial.available())
    {
        int len = Serial.read(uploadingPacket, 255); // 读取数据，将数据保存在数组incomingPacket中
        if (len > 0)                             // 为了避免获取的数据后面乱码做的判断
        {
            uploadingPacket[len] = 0;
        }
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort()); // 准备发送数据到目标IP和目标端口
        Udp.print("Sending message:");
        Udp.println(uploadingPacket);
        Udp.endPacket();                                   // 向目标IP目标端口发送数据
    }

    delay(10); // 短暂延时以防止CPU过载*/
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
        Serial.println("与服务器的连接已断开，正在重新连接...");
        if (client.connect(serverIP, serverPort))
        {
            Serial.println("重新连接成功！");
        }
        else
        {
            Serial.println("重新连接失败，1秒后重试...");
            delay(1000);
            return;
        }
    }

    // 如果服务器有数据发送过来
    if (client.available())
    {
        String message = client.readStringUntil('\n');
        Serial.print("Receved server's message ");
        Serial.println(message);
    }

    // 从串口读取数据并发送给服务器
    if (Serial.available())
    {
        String message = Serial.readStringUntil('\n');
        client.println(message);
        Serial.println("Sending message " + message);
    }

    delay(10); // 短暂延时以防止CPU过载
}

#endif