
#include "LIN_PORT.h"

void cLIN_PORT::begin(float br)
{
	if (br > 9500.0 && br < 19300.0)
	{
		baud_rate = br;
		T_bit = 1000000.0 / baud_rate;
		Serial1.begin(baud_rate);
		active = true;
		txPin = 18;
	}
	else
	{
		T_bit = 0;
		active = false;
		Serial1.end();
	}

}

void cLIN_PORT::wake_up()
{
	if (active)
	{
		unsigned int dly = int(0.5 + 14.0 * T_bit);
		Serial1.end();
		pinMode(txPin, OUTPUT);
		digitalWrite(txPin, LOW);   // Send BREAK
		delayMicroseconds(dly);		// wake up pulse duration
		digitalWrite(txPin, HIGH);  // Send BREAK delimiter
		delayMicroseconds(0.5 + T_bit);
		Serial1.begin(baud_rate);	// restart serial 1 on pins 18 and 19
	}
}

void cLIN_PORT::send(cFrame &frame)
{
	unsigned long start_time;
	unsigned long end_time;
	unsigned long d_time;

	switch (frame.getType())
	{
	case CMD:
		start_time = millis();
		wake_up();
		Serial1.setTimeout(frame.getDelay());
		Serial1.write(frame.getPacket(), frame.getPacketLen());
		frame.resetInputBuffer();
		Serial1.readBytes(frame.getInputBuffer(), frame.getPacketLen());
		end_time = millis();
		break;
	case RSP:
		start_time = millis();
		wake_up();
		Serial1.setTimeout(frame.getDelay());
		Serial1.write(frame.getPacket(), 2);
		frame.resetInputBuffer();
		Serial1.readBytes(frame.getInputBuffer(), frame.getPacketLen());
		end_time = millis();
		break;
	default:
		end_time = start_time = millis();
		break;
	}

	d_time = end_time - start_time;
	if (d_time > frame.getDelay())
	{
		d_time = 5;
	}
	else
	{
		d_time = frame.getDelay() - d_time;
	}

	if (d_time < 5)
		d_time = 5;

	delay(d_time);
}