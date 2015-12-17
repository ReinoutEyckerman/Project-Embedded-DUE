#ifndef LPF_h
#define LPF_h
#include "Arduino.h"
#include "Convolution.h"
class LPF{
    public:
        int run();
        LPF();
        Convolution convo;
    private:
        float kernel;
};
#endif
