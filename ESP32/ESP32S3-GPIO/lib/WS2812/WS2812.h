#ifndef WS2812_H
#define WS2812_H

#include "FastLED.h"            // 此示例程序需要使用FastLED库

enum COLOR
{
    RED,
    GREEN,
    BLUE
};


void InitWS2812(void);
void ledOn(COLOR color);
void ledOff(void);

#endif