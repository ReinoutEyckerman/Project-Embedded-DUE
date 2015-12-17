#include "Arduino.h"
#include "LedBar.h"

void LedBar::attach(int pin1, int pin2, int pin3, int clk){
    this->pin1=pin1;
    this->pin2=pin2;
    this->pin3=pin3;
    this->clk=clk;
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(clk, OUTPUT);
}

//Send in the amount of leds that have to burn.
void LedBar::update(int height){
    if(height>10)
        height=10;
    if(height==10)
    {
        height--;
        digitalWrite(pin3, HIGH);
    }
    else digitalWrite(pin3, LOW);
    if(height==9)
    {
        height--;
        digitalWrite(pin2, HIGH);
    }
    else digitalWrite(pin2, LOW);
    int x=1;
    for(int i=0; i<height;i++)
        x*=2;
    x--;
    shiftOut(pin1,clk,LSBFIRST,byte(x));
}

