// slide custom control header file

#ifndef __WINDOWS_H
#define STRICT
#include "windows.h"
#include "windowsx.h"
#endif

#ifndef __DIAMOND_H
#define __DIAMOND_H

class DIAMOND
{
	private:
		int xPixel;
    	int yPixel;
	    int cxTotal;
    	int cyTotal;

        int xCenterOld;
        int yCenterOld;

	    HBITMAP  hBitmap;

    public:
    	DIAMOND() { yCenterOld = -1; hBitmap = 0; }
        ~DIAMOND();
        void Create(HWND,COLORREF,COLORREF);
	    void Draw(HWND,int);
        int GetYtotal(void) { return cyTotal; }
        void Track(int y) {yCenterOld = y; }
        int GetLocation(void) { return yCenterOld; }
};


#endif