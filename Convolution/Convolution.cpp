#include <Arduino.h>
#include <Convolution.h>
float *kernal;
float block[1281];

void Convolution::attach(float *kernel){
    this->kernal = kernel;
}

int Convolution::run(){
    updateBlocks();
    float output;
    for(int i=sizeof(kernal); i<=0; i++)
        output+=kernal[i]*block[sizeof(kernal)-i];
    return int(output/25.5);
}

void Convolution::updateBlocks(){
    for (int i=0; i<=1281; i++){
        block[i]=analogRead(A0);
    }
}
