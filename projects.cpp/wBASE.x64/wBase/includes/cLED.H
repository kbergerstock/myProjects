// cLED header file
#ifndef __WINDOWS_H
    #define WIN32_LEAN_AND_MEAN
    #include "windows.h"
#endif

#ifndef __subWindow_h
#include "subWindow.h"
#endif

#ifndef __CLED_H
#define __CLED_H

#include "LED.h"

#define TITLE_SIZE 41

class cLED: public subWindow
{
    
    #define RED 	1
    #define GREEN 	2
    #define NEUTRAL 3
    
	private:
    	char title[TITLE_SIZE];

        short color;

        LED Red;
        LED Green;
        LED Neutral;

        void OnCreated(HWND);
        
    public:
		cLED(HINSTANCE , HWND );
        ~cLED() {};

		void Draw(short);
        void SetTitle(char *t);
		void Paint(HWND,HDC);
};
#endif
