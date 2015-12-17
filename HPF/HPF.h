#ifndef HPF_h
#define HPF_h
#include "Arduino.h"
#include "Convolution.h"
class HPF{
    public:
        int run();
        HPF();
    private:
        float kernel;
        Convolution convo;
};
#endif
