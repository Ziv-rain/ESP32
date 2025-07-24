#ifndef WS2812_H
#define WS2812_H

#include "FastLED.h"            // 此示例程序需要使用FastLED库

/**
 * @brief LED颜色枚举
 */
enum COLOR
{
    RED,
    GREEN,
    BLUE
};

// 全局变量声明
extern COLOR ledColor;

//Flashing Mode所用
extern volatile bool blinkFlag;  // 闪烁触发标志
extern bool currentLEDState;    // 当前LED实际状态
extern hw_timer_t *timer;


void InitWS2812(void);
void ledOn(COLOR color);
void ledOff(void);
void SetLED(const char *power, const char *color, const char *mode);

#endif