#ifndef BPF_h
#define BPF_h
#include "Arduino.h"
#include "Convolution.h"
class BPF{
    public:
        int run();
        BPF();
    private:
        Convolution convo;
        float kernel;
};
#endif
