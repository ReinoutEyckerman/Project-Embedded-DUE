#ifndef LPF_h
#define LPF_h
#include "Arduino.h"
#include "Convolution.h"
class LPF{
    public:
        int run();
        LPF();
    private:
        Convolution convo;
        float kernel;
};
#endif
