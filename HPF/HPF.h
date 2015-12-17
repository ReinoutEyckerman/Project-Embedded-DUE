#ifndef HPF_h
#define HPF_h
#include "Arduino.h"
#include "Convolution.h"
class HPF{
    public:
        int run();
        HPF();
        static float kernel[1281];
    private:
        Convolution convo;
};
#endif
