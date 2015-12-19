#include <LedBar.h>
#include <Convolution.h>
#include <FilterController.h>
#include <echo.h>

FilterController filter;
void setup() {
  SerialUSB.begin(9600);
  while(!Serial){
    
  }
  SerialUSB.println("run succesful");
  SerialUSB.println("run succesful");
  filter.attach(A0,22,23,24,25,26,27,28,29,30,31,32,33);

  }

void loop() {
  filter.run();
  SerialUSB.println();
}
