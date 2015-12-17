#ifndef LPF_h
#define LPF_h
#include "Arduino.h"
#include "Convolution.h"
class LPF{
    public:
        int run();
        LPF();
        static float kernel[1281];
    private:
        Convolution convo;

};
#endif
