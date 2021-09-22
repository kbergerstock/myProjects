// diamond bitmap used by slide custom control 

#ifndef __WINDOWS_H
    #ifndef STRICT
        #define STRICT
    #endif

    #define WIN32_LEAN_AND_MEAN
    
    #include <windows.h>
    #include <windowsx.h>
    #include <mmsystem.h>
#endif

#ifndef __diamond_h
#define __diamond_h

class Diamond
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
    	Diamond() : yCenterOld(-1),xCenterOld(0),hBitmap(0),cyTotal(0),cxTotal(0),yPixel(0),xPixel(0) { }
        ~Diamond();
        void CreateBitmap(HWND,COLORREF,COLORREF);
	    void Draw(HWND,int);
        int  GetXtotal()    { return cxTotal; }
        int  GetYtotal()    { return cyTotal; }
        void Track(int y)   { yCenterOld = y; }
        int  GetYLocation() { return yCenterOld; }
        int  GetXLocation() { return yCenterOld; }
};


#endif