#include <SPI.h>
#include <SD.h>
#include <SDCard.h>
File myFile;

SDCard::SDCard(int cs){
    this->cs=cs;
    pinMode(cs, OUTPUT);
	SD.begin(cs);
}

void SDCard::fill(){	
	myFile=SD.open("file.txt", FILE_WRITE);
    for(int i=0; i<=1280; i++)
    {
        while((ADC->ADC_ISR & 0x80)==0); // wait for conversion
        myFile.println(ADC->ADC_CDR[7]); //get values
    }
	myFile.close();
}
void SDCard::getBlock(float *block){
	myFile=SD.open("file.txt");
    int index=0;
    int j=0;
    char contents[64];
    while(myFile.peek()!=-1)
    {
      char aChar = myFile.read();
      if(aChar != '\n' && aChar != '\r')
      {
         contents[index++] = aChar;
         contents[index] = '\0'; // NULL terminate the array
      }
      else // the character is CR or LF
      {
         Serial.print("fileContents: [");
         Serial.print(contents);
         Serial.println("]");
         if(strlen(contents) > 0)
         {
            float aVal = atof(contents);
            block[j++]=aVal;
         }

         contents[0] = '\0';
         index = 0;
      }
    }
	myFile.close();
}
