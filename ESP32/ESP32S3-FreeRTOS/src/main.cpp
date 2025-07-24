#include <Arduino.h>
#include "FreeRTOS.h"
#include "FastLED.h"
#include "WS2812.h"

TimerHandle_t UARTHandle;
uint16_t Counter = 0;

void SendUARTCallback(TimerHandle_t xTimer)
{
    Serial.println(Counter);
    Counter++;
}

void xTaskOne(void *xTask1)
{
    InitWS2812_1();
    for(;;)
    {
        ledOn(RED, 1);
        delay(1000);
        ledOff(1);
        delay(1000);
    }
}

void xTaskTwo(void *xTask2)
{
    InitWS2812_2();  
    for(;;)
    {
        ledOn(GREEN, 2);
        delay(3000);
        ledOff(2);
        delay(3000);
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(48,OUTPUT);
    pinMode(16,OUTPUT);



    xTaskCreatePinnedToCore(xTaskOne,
                            "lightWS2812_1",
                            4096,
                            NULL,
                            1,
                            NULL,
                            1);

    xTaskCreatePinnedToCore(xTaskTwo,
                            "lightWS2812_2",
                            4096,
                            NULL,
                            1,
                            NULL,
                            1);

    UARTHandle = xTimerCreate("Send UART",
                            1000,
                            pdTRUE,
                            (void *)0,
                            SendUARTCallback);
    xTimerStart(UARTHandle, portMAX_DELAY);

    vTaskDelete(NULL);
}

void loop()
{

}
