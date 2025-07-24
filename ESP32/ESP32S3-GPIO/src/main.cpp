#include "Arduino.h"
#include "WS2812.h"    

#define     isOutputExperiment      1       //1-输出模式验证
                                            //0-输入模式验证
#if         isOutputExperiment    
void setup() 
{ 
    pinMode(46, OUTPUT);    //设置Pin46为输出模式
}
 
void loop() 
{ 
    digitalWrite(46, HIGH);
    delay(1000);
    digitalWrite(46, LOW);
    delay(1000);
}

#else 
void setup() 
{ 
    InitWS2812();
    pinMode(0, INPUT);  //设置Pin0为输入模式
}
 
void loop() 
{ 
    if(digitalRead(0) == LOW)
    {
        ledOn(RED);
    }
    if(digitalRead(0) == HIGH)
    {
        ledOff();
    }
}

#endif