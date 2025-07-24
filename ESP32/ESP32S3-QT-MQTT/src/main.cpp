#include <Wire.h>
#include <WiFi.h>

#include "MQTT.h"
#include "WS2812.h"

hw_timer_t *timer = NULL;// 硬件定时器指针

/**
 * @brief 定时器中断服务函数
 * @note 在IRAM中执行，用于设置闪烁标志
 */
void IRAM_ATTR TimerEvent()
{
     blinkFlag = true;
}

/**
 * @brief 初始化系统
 * @note 1. 初始化串口通信
 *       2. 初始化MQTT连接
 *       3. 初始化WS2812灯带
 *       4. 配置1秒间隔的硬件定时器
 */
void setup()
{
    Serial.begin(115200);  // 初始化串口，波特率115200
    MQTT_Init();           // 初始化MQTT连接
    InitWS2812();          // 初始化WS2812灯带

  // 配置硬件定时器（1秒周期）
    timer = timerBegin(0, 80, true);          // 使用定时器0，80分频，向上计数
    timerAttachInterrupt(timer, &TimerEvent, true); // 绑定中断处理函数
    timerAlarmWrite(timer, 1000000, true);    // 设置1,000,000微秒(1秒)周期
    //timerAlarmEnable(timer); //	闪烁模式再使能定时器
}

/**
 * @brief 主循环
 * @note 1. 定期上报设备状态
 *       2. 处理MQTT消息
 *       3. 处理LED闪烁逻辑
 */
void loop()
{
    TASK_Capacity_Report();// 上报当前状态
    client.loop(); // 处理MQTT消息接收

    //调试用
    //Serial.print("blinkFlag");
    //Serial.println(blinkFlag);

    // 处理闪烁事件（非中断环境）
    if(blinkFlag) {
        blinkFlag = false;
        //Serial.print("currentLEDState");
        //Serial.println(currentLEDState);
        if(currentLEDState) {
            ledOff();
        } else {
            ledOn(ledColor);  // 使用当前保存的颜色
        }
        currentLEDState = !currentLEDState;
    }
    
    delay(10);  // 适当降低CPU占用
}

