#ifndef LedBar_h
#define LedBar_h
#include "Arduino.h"
class LedBar{
    public:
        void attach(int pin1, int pin2, int pin3, int clk);
        void update(int height);
    private:
        int pin1;
        int pin2;
        int pin3;
        int clk;
};
#endif
