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
void ledOn(COLOR color, u8_t ID);
void ledOff(u8_t ID);

void InitWS2812_1(void);
void InitWS2812_2(void);

#endif