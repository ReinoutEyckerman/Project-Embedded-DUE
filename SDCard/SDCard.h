#ifndef SDCard_h
#define SDCard_h
#include "Arduino.h"
class SDCard{
	public:
		SDCard(int cs);
		void fill();
		void getBlock(float *block);
	private:
		int cs;
};
#endif