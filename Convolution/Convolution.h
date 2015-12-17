#ifndef Convolution_h
#define Convolution_h
#include <Arduino.h>
class Convolution{
    public:
        void attach(float *kernel);
        int run();
        float block[1281];
    private:
        float *kernal;
        void updateBlocks();
};
#endif
