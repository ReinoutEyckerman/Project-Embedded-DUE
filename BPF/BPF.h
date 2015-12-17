#ifndef BPF_h
#define BPF_h
#include "Arduino.h"
#include "Convolution.h"
class BPF{
    public:
        int run();
        BPF();
        static float kernel[1281];
    private:
        Convolution convo;

};
#endif
