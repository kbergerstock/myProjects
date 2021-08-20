#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#endif

void BlitBitMap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart,DWORD dwRop)
{

    BITMAP bm;
    HDC    hdcMem;
    POINT  ptSize, ptOrg;

    hdcMem = CreateCompatibleDC(hdc);
    SelectObject(hdcMem,hBitmap);
    SetMapMode(hdcMem,GetMapMode(hdc));

    GetObject(hBitmap,sizeof(BITMAP), (LPSTR) &bm);
    ptSize.x = bm.bmWidth;
    ptSize.y = bm.bmHeight;
    DPtoLP(hdc,&ptSize,1);

    ptOrg.x = 0;
    ptOrg.y = 0;
    DPtoLP(hdcMem,&ptOrg,1);

    BitBlt(hdc,xStart,yStart,ptSize.x,ptSize.y,hdcMem,ptOrg.x,ptOrg.y, dwRop);

    DeleteDC(hdcMem);
}

void DrawBitMap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart)
{
	BlitBitMap(hdc,hBitmap,xStart,yStart,SRCCOPY);
}
