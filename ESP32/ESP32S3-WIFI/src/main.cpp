#include <Arduino.h>
#include <WiFi.h>

#define isConnectPhone  0       //1-连接手机热点验证
                                //0-两块ESP32互联验证
#if     isConnectPhone

const char *ssid = "iQOO 7"; //你的网络名称
const char *password = "00000000"; //你的网络密码

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password); //连接网络

  while (WiFi.status() != WL_CONNECTED) //等待网络连接成功
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //打印模块IP
}

void loop()
{
    
}

#else

#define     isAP    1   //1-AP代码
                        //0-STA代码
#if         isAP        //第一块ESP32作为AP代码

void setup()
{
    WiFi.softAP("ESP32_AP_TEST");
}

void loop()
{
    
}

#else               //第二块ESP32作为STA代码

const char *ssid = "ESP32_AP_TEST"; //你的网络名称

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, NULL); //连接网络

  while (WiFi.status() != WL_CONNECTED) //等待网络连接成功
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //打印模块IP
}

void loop()
{
    
}

#endif


#endif
