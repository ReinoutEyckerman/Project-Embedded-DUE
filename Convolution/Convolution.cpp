#include <Arduino.h>
#include <Convolution.h>

void Convolution::attach(float *kernel){
    this->kernel = kernel;
}

void Convolution::run(float sample, int section){
    //SerialUSB.println(kernel[KERNEL_SIZE-section]);
    output+=kernel[KERNEL_SIZE-section]*sample;
}
int Convolution::getResult(){
    float out=output;
    output=0;
    //SerialUSB.println(out);
    return (int)(out*10)/(ANALOG_IN*AMP);
}
