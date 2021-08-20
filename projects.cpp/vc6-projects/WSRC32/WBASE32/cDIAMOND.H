// slide custom control header file

#ifndef __WINDOWS_H
    #ifndef STRICT
        #define STRICT
    #endif

    #define WIN32_LEAN_AND_MEAN
    
    #include <windows.h>
    #include <windowsx.h>
    #include <mmsystem.h>
#endif

#ifndef __cDIAMOND_H
#define __cDIAMOND_H

class cDIAMOND
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
    	cDIAMOND() { yCenterOld = -1; hBitmap = 0; }
        ~cDIAMOND();
        void Create(HWND,COLORREF,COLORREF);
	    void Draw(HWND,int);
        int  GetXtotal()    { return cxTotal; }
        int  GetYtotal()    { return cyTotal; }
        void Track(int y)   { yCenterOld = y; }
        int  GetYLocation() { return yCenterOld; }
        int  GetXLocation() { return yCenterOld; }
};


#endif