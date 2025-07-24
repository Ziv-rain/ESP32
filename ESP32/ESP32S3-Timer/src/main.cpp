#include <Arduino.h>
#include "WS2812.h"

hw_timer_t *timer = NULL;
bool LED_Status = true;

void IRAM_ATTR TimerEvent()
{
    if(LED_Status)
    {
        ledOn(RED);
        LED_Status = !LED_Status;
    }
    else
    {
        ledOff();
        LED_Status = !LED_Status;
    }
}

void setup()
{
    InitWS2812();
    //	函数名称：timerBegin()
    //	函数功能：Timer初始化，分别有三个参数
    //	函数输入：1. 定时器编号（0到3，对应全部4个硬件定时器）
    //			 2. 预分频器数值（ESP32计数器基频为80M，80分频单位是微秒）
    //			 3. 计数器向上（true）或向下（false）计数的标志
    //	函数返回：一个指向 hw_timer_t 结构类型的指针
    timer = timerBegin(0, 80, true);

    //	函数名称：timerAttachInterrupt()
    //	函数功能：绑定定时器的中断处理函数，分别有三个参数
    //	函数输入：1. 指向已初始化定时器的指针（本例子：timer）
    //			 2. 中断服务函数的函数指针
    //			 3. 表示中断触发类型是边沿（true）还是电平（false）的标志
    //	函数返回：无
    timerAttachInterrupt(timer, &TimerEvent, true);

    //	函数名称：timerAlarmWrite()
    //	函数功能：指定触发定时器中断的计数器值，分别有三个参数
    //	函数输入：1. 指向已初始化定时器的指针（本例子：timer）
    //			 2. 第二个参数是触发中断的计数器值（1000000 us -> 1s）
    //			 3. 定时器在产生中断时是否重新加载的标志
    //	函数返回：无
    timerAlarmWrite(timer, 1000000, true);
    timerAlarmEnable(timer); //	使能定时器
}

void loop()
{

}
