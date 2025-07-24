#include "WS2812.h"

#define NUM_LEDS 1             // LED灯珠数量
#define DATA_PIN 48             // Arduino输出控制信号引脚 接LED灯环的DI
#define LED_TYPE WS2812         // LED灯环型号
#define COLOR_ORDER GRB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序
 
uint8_t max_bright = 16;       // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高

CRGB leds[NUM_LEDS];            // 建立灯带leds

void InitWS2812(void)
{
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化灯带
    FastLED.setBrightness(max_bright);                            // 设置灯带亮度
    FastLED.clear();
    FastLED.show();
}

void ledOn(COLOR color)
{
    switch (color)
    {
    case RED:
        leds[0] = CRGB(255, 0, 0);
        break;
    case GREEN:
        leds[0] = CRGB(0, 255, 0);
        break;     
    case BLUE:
        leds[0] = CRGB(0, 0, 255);
        break;     
    default:
        break;
    }
    FastLED.show();
}

void ledOff(void)
{
    leds[0] = CRGB(0, 0, 0);
    FastLED.show();
}