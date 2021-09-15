// led  custom control header file

#ifndef __WINDOWS_H
    #ifndef STRICT
        #define STRICT
    #endif
    #include "windows.h"
    #include "windowsx.h"
#endif

#ifndef __LED_H
#define __LED_H

class LED
{
	protected:
		int xPixel;
    	int yPixel;

	    int cxTotal;
    	int cyTotal;

        int xCenter;
        int yCenter;

	    HBITMAP  hBitmap;

    public:
    	LED();
        ~LED();

        void Create(HWND,COLORREF,COLORREF);
	    void Draw(HWND);

        int GetcxTotal(void) { return cxTotal; }
        int GetcyTotal(void) { return cyTotal; }

        void SetPosition(POINT);
        POINT GetPosition(void);
};

#endif
