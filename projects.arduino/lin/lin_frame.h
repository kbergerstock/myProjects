/* 
	lin_frame.h
	header file defining lin frame and lin frame subroutines
	K.R.Bergerstock 06/2016
*/

#include <Arduino.h>

#ifndef __LIN_FRAME_H
#define __LIN_FRAME_H

typedef enum HEADER_TYPE {
	NOP = 0,
	RSP,
	CMD
};

class cFrame
{
private:
	byte header;				
	byte data[8];
	byte len;
	byte outBuf[12];
	HEADER_TYPE type;
	int frame_delay;
	byte input_buffer[12];

	void parity();
	byte cksum();

public:
	cFrame();

	void initialize(byte, HEADER_TYPE, int, byte);
	void resetInputBuffer();

	HEADER_TYPE getType() { return type; }
	byte* getInputBuffer() { return input_buffer; }
	byte* getPacket() { return outBuf; }
	byte  getPacketLen() { return len + 3; }
	int   getDelay() { return frame_delay; }

	void setData(const byte* d, byte Len);

	void formPacket();
};

byte calcCksum(byte* data, byte len);
byte calcParity(byte cmd);

#endif