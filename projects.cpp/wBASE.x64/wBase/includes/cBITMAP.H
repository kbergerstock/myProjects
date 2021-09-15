// cBITMAP.H
// class to handle bitmaps

#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#endif

#ifndef __cBITMAP_H
#define __cBITMAP_H

class cBITMAP
{
	private:
    protected:
    	HBITMAP handle;
        BITMAP  bitmap;

    public:
    cBITMAP();
    virtual ~cBITMAP();

    HBITMAP Create(HDC,long cx, long cy);
    HBITMAP Create(long cx, long cy );
    HBITMAP Create(HINSTANCE,int);
    void 	Destroy(void);

    void Blit(HDC hdc, short xStart, short yStart, DWORD dwRop);
    void Draw(HDC hdc, short xStart, short yStart);
    HBITMAP GetHandle(void) {return handle; }

    int getWidth(void) { return bitmap.bmWidth; }
    int getHeight(void) {return bitmap.bmHeight; }
};



#endif

