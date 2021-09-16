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
    	LED() : yCenter(0), xCenter(0), hBitmap(0), cyTotal(0), cxTotal(0), yPixel(0), xPixel(0) { }
        ~LED();

        void CreateBitmap(HWND,COLORREF,COLORREF);
	    void Draw(HWND);

        int GetcxTotal(void) { return cxTotal; }
        int GetcyTotal(void) { return cyTotal; }

        void SetPosition(POINT);
        POINT GetPosition(void);
};

#endif
