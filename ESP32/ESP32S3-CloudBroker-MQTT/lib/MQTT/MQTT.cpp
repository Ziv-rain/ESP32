/*
 * 概述：此文件包含ESP32与华为云MQTT服务器连接相关函数
 */

#include "MQTT.h"
#include "ArduinoJson.h"

WiFiClient espClient; // ESP32WiFi模型定义
PubSubClient client(espClient);

/* MQTT 连接配置 */
/*-----------------------------------------------------*/

// 连接 WiFi
const char *ssid = "iQOO 7";       // 请替换为你的 WiFi SSID
const char *password = "00000000"; // 请替换为你的 WiFi 密码

// MQTT 服务器信息
const char *mqttServer = "10bdb1c019.st1.iotda-device.cn-north-4.myhuaweicloud.com";           // 请替换为你的 MQTT 服务器地址
const int mqttPort = 1883;                                                                     // 请替换为你的 MQTT 端口（建议使用 TLS/SSL）
const char *clientId = "687a5d2d32771f177b4d6998_6666_0_0_2025071815";                         // 请替换为你的 MQTT 客户端 ID
const char *mqttUser = "687a5d2d32771f177b4d6998_6666";                                        // 请替换为你的 MQTT 用户名
const char *mqttPassword = "bd265494e8721506c416c89ccd4e8756d915403f806244ed24cf0ed383b4fe4c"; // 请替换为你的 MQTT 密码

const char *topic_properties_report = "$oc/devices/687a5d2d32771f177b4d6998_6666/sys/properties/report";
// char* topic_Commands_Response = "$oc/devices/68792265d582f200183c55c4_1111/sys/commands/response/request_id={request_id}";

/*******************************************************/

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
        }
        else
        {

            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(6000);
        }
    }
    // 接受平台下发内容的初始化
    // client.setCallback(callback); //可以接受任何平台下发的内容
}

void TASK_Capacity_Report(int capacity)
{

    // 以下部分代码调用了ArduinoJson库将属性上报消息打包为JSON格式
    // 此部分代码可以通过ArduinoJson库的官方网站直接生成
    StaticJsonBuffer<300> JSONbuffer; // 定义静态的JSON缓冲区用于存储JSON消息
    JsonObject &root = JSONbuffer.createObject();
    JsonArray &services = root.createNestedArray("services");
    JsonObject &service_1 = services.createNestedObject();
    JsonObject &properties_1_1 = service_1.createNestedObject("properties");

    service_1["service_id"] = "1111";
    properties_1_1["1234"] = capacity;

    //  root.prettyPrintTo(Serial);//调试用，将JSON打印到串口

    // 以下将生成好的JSON格式消息格式化输出到字符数组中，便于下面通过PubSubClient库发送到服务器
    char JSONmessageBuffer[100];
    root.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));

    Serial.println("Sending message to MQTT topic..");
    Serial.println(JSONmessageBuffer);

    // 以下代码将打包好的JSON数据包通过PubSubClient库发送到服务器
    if (client.publish(topic_properties_report, JSONmessageBuffer) == true)
    {
        Serial.println("Success sending message");
    }
    else
    {
        Serial.println("Error sending message");
    }
    // 由于本函数是放在loop中不断循环执行，所以添加client.loop()进行保持硬件的活跃度
    // 避免由于长时间未向服务器发送消息而被服务器踢下线
    client.loop(); // mqtt保活
    Serial.println("-------------");
}

/*
 * 作用：   监听华为云IoT平台下发指令并处理回调函数
 * 参数1：  订阅的topic
 * 参数2：  接收到的内容
 * 参数3：  内容的长度
 * 返回值： 无
 */
// void callback(char *topic, byte *payload, unsigned int length)
//  {
//    char *pstr = topic; //指向topic字符串，提取request_id用

//   Serial.println();
//   Serial.println();
//   Serial.print("Message arrived [");
//   Serial.print(topic);  //将收到消息的topic展示出来
//   Serial.print("] ");
//   Serial.println();

//   payload[length] = '\0'; //在收到的内容后面加上字符串结束符
//   char strPayload[255] = {0};
//   strcpy(strPayload, (const char*)payload);
//   Serial.println((char *)payload);  //打印出收到的内容
//   Serial.println(strPayload);

//   /*request_id解析部分*/
//   char arr[100];  //存放request_id
//   int flag = 0;
//   char *p = arr;
//   while(*pstr)  //以'='为标志，提取出request_id
//   {
//     if(flag) *p ++ = *pstr;
//     if(*pstr == '=') flag = 1;
//     pstr++;
//   }
//   *p = '\0';
//   Serial.println(arr);
//   // strcat(topic_Commands_Response, arr);
//   // topic_Commands_Response.concat(arr);

//   /*将命令响应topic与resquest_id结合起来*/
//   char topicRes[200] = {0};
//   strcat(topicRes, topic_Commands_Response);
//   strcat(topicRes, arr);
//   Serial.println(topicRes);

//   /*payload解析*/
//   const size_t capacity_Payload_Receive = JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(5) + 150;
//   DynamicJsonBuffer jsonBuffer_Payload(capacity_Payload_Receive);

//   // const char* json = "{\"paras\":{\"address\":\"88-902\",\"user\":\"wksgogogo\",\"number\":\"3333\",\"day\":\"2022-07-21\",\"time\":\"12:01\"},\"service_id\":\"Users_Delivery_Order\",\"command_name\":\"user_order\"}";

//   JsonObject& root_Payload = jsonBuffer_Payload.parseObject(strPayload);

//  //判断json解析是否成功
//  if (root_Payload.success()){
//     if(!strcmp(root_Payload["command_name"], "user_order"))  //如果收到的内容是“用户下单”
//     {
//       JsonObject& paras_Payload = root_Payload["paras"];
//       const char* paras_address = paras_Payload["address"];
//       const char* paras_user = paras_Payload["user"];
//       const char* paras_number = paras_Payload["number"];
//       const char* paras_day = paras_Payload["day"];
//       const char* paras_time = paras_Payload["time"];

//       Serial.println("__________JSON Received Parse__________");
//       Serial.println(paras_address);
//       Serial.println(paras_user);
//       Serial.println(paras_number);
//       Serial.println(paras_day);
//       Serial.println(paras_time);

//       Info_UserOrder_Structure OrderInfo;
//       strcpy(OrderInfo.userName, paras_user);
//       strcpy(OrderInfo.address, paras_address);
//       strcpy(OrderInfo.orderNum, paras_number);
//       strcpy(OrderInfo.day, paras_day);
//       strcpy(OrderInfo.time, paras_time);

//       //响应
//       Command_Response(topicRes, "user_order", SUCCESS);

//       OrderInfo_Save(OrderInfo);  //订单信息存储
//     }

//     if(!strcmp(root_Payload["command_name"], "open"))   //如果收到的内容是“开锁”
//     {
//       const char* paras_user = root_Payload["paras"]["user"];
//       Serial.println("__________JSON Received Parse__________");
//       Serial.println(paras_user);

//       EOF_ELock_Unlock(paras_user);

//       Command_Response(topicRes, "open", SUCCESS);
//     }
//   }
// }

/*
 * 作用：   华为云IoT命令下发的响应函数
 * 参数1：  命令响应的topic
 * 参数2：  命令响应名
 * 参数3：  响应结果
 * 返回值： 无
 */
// void Command_Response(char *topic, char *responseName, uint8_t response_Result)
// {
// /*发送命令响应部分*/
//   /*构建JSON内容*/
// const size_t capacity = JSON_OBJECT_SIZE(2) + JSON_OBJECT_SIZE(3);
// DynamicJsonBuffer jsonBuffer(capacity);

// JsonObject& root = jsonBuffer.createObject();
// if(response_Result == SUCCESS){
//   root["result_code"] = 0;
//   JsonObject& paras = root.createNestedObject("paras");
//   paras["status"] = 200;
//   paras["msg"] = "success";
// }
// else if(response_Result == FAIL){
//   root["result_code"] = 1;
//   JsonObject& paras = root.createNestedObject("paras");
//   paras["status"] = 400;
//   paras["msg"] = "fail";
// }

// if(!strcmp(responseName, "user_order")){
//   root["response_name"] = "user_order";
// }
// else if(!strcmp(responseName, "open")){
//   root["response_name"] = "open";
// }

// root.printTo(Serial); //串口打印出构建好的JSON内容
// Serial.println();

// char JSONmessageBuffer[300];
// root.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer)); //将构建的JSON消息复制到char数组中

// Serial.println("Sending response to HuaWei Cloud..");
// Serial.println(JSONmessageBuffer);

// if (client.publish(topic, JSONmessageBuffer) == true) {
//   Serial.println("Success sending response command message");
// } else {
//   Serial.println("Error sending response command message");
// }

// Serial.println("-------------");
// }