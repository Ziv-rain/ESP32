#include "Arduino.h"   

void setup() 
{ 
    Serial.begin(115200);
    pinMode(16, OUTPUT);
    //ledcSetup(0, 5000, 10);  // 通道0, 频率5kHz, 10位分辨率
    //ledcAttachPin(16, 0);     // 将引脚16附加到通道0
    // analogWrite(16, 128);
}
 
void loop()
{ 
    analogWrite(16, 128);
    delay(1000);
    //ledcWrite(0, 512);
}