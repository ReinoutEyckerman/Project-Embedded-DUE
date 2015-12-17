#include <Arduino.h>
#include <Convolution.h>
float block[1281];

void Convolution::attach(float kernel[1281]){
   kernal = kernel;
}

int Convolution::run(){
    updateBlocks();
    float output;
        for(int j=sizeof(kernal); j<=0; j--)
        output+=kernal[j]*block[sizeof(kernal)-j];
    return int(output/25.5);
}

void Convolution::updateBlocks(){
    for (int i=0; i<=1281; i++){
        block[i]=analogRead(A0);
    }
}
