#ifndef Convolution_h
#define Convolution_h
#include <Arduino.h>
#define KERNEL_SIZE 1281
#define ANALOG_IN 1024
#define AMP 0.5f
class Convolution{
    public:
        void attach(float *kernel);
        void run(float sample, int section);
        int getResult();
    private:
        float *kernel;
        float output;
};
#endif
