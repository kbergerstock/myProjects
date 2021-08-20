// cLED header file

#ifndef __CWFRAME_H
#include "cwFrame.h"
#endif

#ifndef __LED_H
#include "led.h"
#endif

#define RED 	1
#define GREEN 	2
#define NEUTRAL 3

#ifndef __CLED_H
#define __CLED_H

class cLED: public cWinFrame
{
	private:
    	char title[40];

        short color;

        LED Red;
        LED Green;
        LED Neutral;

        void OnCreated(HWND);
        
    public:
		cLED(HWND);
        ~cLED();

		void Draw(short);

        void SetTitle(char *t) {lstrcpy(LPSTR(title),LPSTR(t)); }

		void Paint(HWND,HDC);

};

#endif