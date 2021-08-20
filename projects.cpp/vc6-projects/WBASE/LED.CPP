// led control

#ifndef __LDE_H
#include "led.h"
#endif

LED::LED()
{
	hBitmap = 0;
    xCenter= 0;
    yCenter= 0;
}

LED::~LED()
{
	if(hBitmap)
    	DeleteObject(hBitmap);
}

void LED::SetPosition(POINT p)
{
	xCenter = p.x;
    yCenter = p.y;
}

POINT LED::GetPosition(void)
{
	POINT p;
    p.x = xCenter;
    p.y = yCenter;
    return p;
}

void LED::Draw(HWND hwnd)
{
    HDC    hdc = GetDC(hwnd);
    HDC    hdcMem;
    hdcMem = CreateCompatibleDC(hdc);
    SelectObject(hdcMem,hBitmap);

//    short xStart = 4; // xCenter - cxTotal/2;
    int yStart =  yCenter - cyTotal/2;
    int xStart = yStart;

    BitBlt(hdc,xStart,yStart,cxTotal,cyTotal,hdcMem,0,0,SRCCOPY);

    DeleteDC(hdcMem);
    ReleaseDC(hwnd,hdc);
}

void LED::Create(HWND hwnd, COLORREF bkGnd, COLORREF color)
{
	RECT rect;
    HBRUSH hBrush;

	HDC hdc = GetDC(hwnd);
	xPixel = GetDeviceCaps(hdc,ASPECTX);
    yPixel = GetDeviceCaps(hdc,ASPECTY);
    GetClientRect(hwnd,&rect);

    cyTotal = (rect.bottom - rect.top)-2;
    cxTotal = cyTotal;

    yCenter = (rect.bottom + rect.top) /2;
    xCenter = rect.right - (rect.bottom - rect.top) /2;

    if(hBitmap)
    	DeleteObject(hBitmap);

    HDC hdcMem = CreateCompatibleDC(hdc);
    hBitmap = CreateCompatibleBitmap(hdc,cxTotal,cyTotal);
    SelectObject(hdcMem,hBitmap);

    hBrush = CreateSolidBrush(bkGnd);
    SelectBrush(hdcMem,hBrush);
    Rectangle(hdcMem,-1,-1,cxTotal+1,cyTotal+1);
    DeleteBrush(hBrush);

    hBrush = CreateSolidBrush(color);
    SelectBrush(hdcMem,hBrush);
    Rectangle(hdcMem,1,1,cxTotal - 1, cyTotal - 1);
    DeleteBrush(hBrush);

    DeleteDC(hdcMem);
    ReleaseDC(hwnd,hdc);
}

