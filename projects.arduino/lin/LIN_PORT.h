/*
lin_port.h
header file defining lin port and serial interface to lin device
K.R.Bergerstock 06/2016
*/

#include <Arduino.h>
#include "lin_frame.h"

#ifndef __LIN_PORT_H
#define __LIN_PORT_H


class cLIN_PORT
{
	private:
		bool active;
		float baud_rate;
		float T_bit;
		byte  txPin;
		void wake_up();

	public:
		void begin(float);

		void send(cFrame &);
	
		
};

#endif
