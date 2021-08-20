#include "lin_frame.h"
#include "LIN_PORT.h"

const byte fData[] = { 0x00,0x00,0x00,0x00 };
cFrame scheduleTable[9];
cLIN_PORT Lin;

void dumpData(byte *b, int l)
{
	for (int i = 0; i < l; i++)
	{
		Serial.print(b[i], HEX);
		Serial.print(" ");
	}
	Serial.print("\n");
}

void dumpResponse(int ndx)
{
	byte *o = scheduleTable[ndx].getPacket();
	byte *b = scheduleTable[ndx].getInputBuffer();
	int l = scheduleTable[ndx].getPacketLen();
	switch (scheduleTable[ndx].getType())
	{
		case CMD:
			Serial.print("CMD:TX ");
			dumpData(o,l);
			Serial.print("CMD:RX ");
			dumpData(b, l);
			break;
		case RSP:
			Serial.print("RSP:TX ");
			dumpData(o, 2);
			Serial.print("RSP.RX ");
			dumpData(b,l);
			break;
		default:
			break;
	}

}

void setup() {
  
	scheduleTable[0].initialize(0x0b, CMD,  20, 4);  // 
	scheduleTable[1].initialize(0x0c, RSP,  20, 3);  // 
	scheduleTable[4].initialize(0x00, NOP,  60, 4);
	scheduleTable[2].initialize(0x0b, CMD,  20, 4);  // 
	scheduleTable[3].initialize(0x0c, RSP,  20, 3);  // 
	scheduleTable[4].initialize(0x00, NOP,  60, 4);
	
	for (int i = 0; i < 6; i++)
	{
		if(scheduleTable[i].getType() == CMD)
			scheduleTable[i].setData(fData,4);
		scheduleTable[i].formPacket();
		scheduleTable[i].resetInputBuffer();
	}
	// once the packets are formed it does not need to be done again unless something needs to be changed
	
	Serial.begin(115200);
	Lin.begin(10417);
}

void loop() {
	for (int i = 0; i < 6; i++)
	{
		Lin.send(scheduleTable[i]);
		dumpResponse(i);
	}
  
}
