#ifndef FilterController_h
#define FilterController_h
#include <Arduino.h>
#include <Convolution.h>
#include <LedBar.h>
#include <echo.h>
class FilterController{
    public:
        void attach(int ananlogPin, int p11, int p12, int p13, int p1clk, int p21, int p22, int p23, int p2clk, int p31, int p32, int p33, int p3clk);
        void run();
    private:
        int analogPin;
        float HPKernel[KERNEL_SIZE];
        float BPKernel[KERNEL_SIZE];
        float LPKernel[KERNEL_SIZE];
        Convolution LPF;
        Convolution BPF;
        Convolution HPF;
        LedBar LPFBar;
        LedBar BPFBar;
        LedBar HPFBar;
        Echo echo;
};
#endif
