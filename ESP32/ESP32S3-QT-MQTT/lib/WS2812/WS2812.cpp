#include "WS2812.h"

#define NUM_LEDS 1             // LED灯珠数量
#define DATA_PIN 48             // Arduino输出控制信号引脚 接LED灯环的DI
#define LED_TYPE WS2812         // LED灯环型号
#define COLOR_ORDER GRB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序
 
uint8_t max_bright = 16;       // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高

CRGB leds[NUM_LEDS];            // 建立灯带leds

/**
 * @brief 初始化WS2812灯带
 */
void InitWS2812(void)
{
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化灯带
    FastLED.setBrightness(max_bright);                            // 设置灯带亮度
    FastLED.clear();        // 清除所有LED颜色
    FastLED.show();         // 应用设置
}


/**
 * @brief 开启指定颜色的LED
 * @param color 颜色枚举值(RED/GREEN/BLUE)
 */
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
    FastLED.show();// 应用颜色设置
}

/**
 * @brief 关闭LED
 */
void ledOff(void)
{
    leds[0] = CRGB(0, 0, 0);// 设置为黑色（关闭）
    FastLED.show();
}

/**
 * @brief 根据指令设置LED状态
 * @param power 电源状态("On"/"Off")
 * @param color 颜色值("Red"/"Green"/"Blue")
 * @param mode  工作模式("Constant light mode"/"Flashing mode")
 */
void SetLED(const char *power, const char *color, const char *mode)
{
    if (strcmp(power, "On") == 0) {
        // 设置颜色
        if (strcmp(color, "Red") == 0) ledColor = RED;
        else if (strcmp(color, "Green") == 0) ledColor = GREEN;
        else if (strcmp(color, "Blue") == 0) ledColor = BLUE;

        // 设置工作模式
        if (strcmp(mode, "Constant light mode") == 0) {
            ledOn(ledColor);           // 常亮模式
            timerAlarmDisable(timer);  // 禁用定时器
        }
        else if (strcmp(mode, "Flashing mode") == 0) {
            currentLEDState = false;   // 初始状态：灭
            ledOff();                  // 关闭LED
            timerAlarmEnable(timer);   // 启用定时器闪烁
        }
    }
    else if (strcmp(power, "Off") == 0) {
        timerAlarmDisable(timer); // 禁用定时器
        ledOff();                 // 关闭LED
    }
}