#include <Arduino.h>
#include <LedBar.h>
#include <Convolution.h>
#include <echo.h>

/* Preprocessor directives */
#define TESTING
#define DEBUG
#define SAMPLERATE 16000  // overwrites echo.h & convolution.h
#define OUTPUT_CALC_FREQ 10 // overwrites convolution.h
#define ECHO_DELAY 0.5    // overwrites echo.h
#define ECHO_AMP 0.5      // overwrites echo.h

/* Objects */
Echo echo;                // hardcoded DAC0;
Convolution filter;
LedBar LowBar;
LedBar MidBar;
LedBar HighBar;

/* Pins */
int samplePin = A0;

void setup() {
  SerialUSB.begin(9600);
  while(!Serial){}
  LowBar.attach(22,23,24,25);
  MidBar.attach(26,27,28,29);
  HighBar.attach(30,31,32,33);
  SerialUSB.println("startup succesful");
  }

void loop() {
  #ifdef DEBUG
    ulong startTimeLoop = micros();
  #endif
  
  #ifdef TESTING
    int currentSample = random(1024);
  #else
    int currentSample = analogRead(samplePin);
  #endif
  
  echo.pushSample(currentSample);
  
  // true als de filter klaar is met rekenen.
  if(filter.pushSample(currentSample)){
     LowBar.update(filter.outputLP);
     MidBar.update(filter.outputBP);
     HighBar.update(filter.outputHP);
  }
  
  echo.emit();
  
  #ifdef DEBUG
    ulong loopDuration = micros() - startTimeLoop;
    float freq = 1/loopDuration;
    SerialUSB.print(F("Periode: "));
    SerialUSB.print(loopDuration);
    SerialUSB.print(F(" | Freq: "));
    SerialUSB.println(freq);
  #endif
}
