#include <Convolution.h>

bool Convolution::pushSample(int sample){
  // We beginnen pas na enkele samples te skippen, zodat we op OUTPUT_CALC_FREQ blijven.
  if(_index < SKIP_SAMPLES){
    _index++;
    return false; // nog niet klaar.
  }

  // punt van de kernel (achteraan te beginnen) om mee te rekenen.
  int kernelIndex = KERNEL_SIZE - (_index - SKIP_SAMPLES);

  outputHP += _HPKernel[kernelIndex] * sample;
  outputBP += _BPKernel[kernelIndex] * sample;
  outputLP += _LPKernel[kernelIndex] * sample;

  // Als dit nog niet het laatste punt was blijven we gaan.
  if(kernelIndex != 0){
    _index++;
    return false; // nog niet klaar.
  }
  else{
    outputHP = 0;
    outputBP = 0;
    outputLP = 0;
    _index = 0;
    return true; // klaar
  }
}
