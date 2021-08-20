// slide custom control

#ifndef __DIAMOND_H
#include "diamond.h"
#endif

DIAMOND::~DIAMOND()
{
	if(hBitmap)
		DeleteObject(hBitmap);
}

void DIAMOND::Create(HWND hwnd, COLORREF bkGnd, COLORREF color)
{
	RECT rect;
	HBRUSH hBrush;

	HDC hdc = GetDC(hwnd);
	xPixel = GetDeviceCaps(hdc,ASPECTX);
	yPixel = GetDeviceCaps(hdc,ASPECTY);
	GetClientRect(hwnd,&rect);

	cxTotal = rect.right - rect.left;
	cyTotal = ((cxTotal/5) * 2) + 4;

	POINT points[4];
	points[0].x = 0;			points[0].y = cyTotal/2;
	points[1].x = cxTotal/2;	points[1].y = 2;
	points[2].x = cxTotal;		points[2].y = cyTotal/2;
	points[3].x = cxTotal/2;	points[3].y=cyTotal-2;

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
	Polygon(hdcMem,points,4);
	DeleteBrush(hBrush);

	DeleteDC(hdcMem);
	ReleaseDC(hwnd,hdc);
}

void DIAMOND::Draw(HWND hwnd, int yCenter)
{
	HDC    hdc = GetDC(hwnd);
	HDC    hdcMem;
	hdcMem = CreateCompatibleDC(hdc);
	SelectObject(hdcMem,hBitmap);
	int xStart = 0;
	int yStart = yCenter - cyTotal/2;

	if ( yCenterOld == -1)
		BitBlt(hdc,xStart,yStart,cxTotal,cyTotal,hdcMem,0,0,SRCCOPY);
	else
	  {
		int d = yCenter > yCenterOld ? 1 : -1;
		while(yCenterOld != yCenter)
		 {
			yCenterOld += d;
			yStart = yCenterOld-cyTotal/2;
			BitBlt(hdc,xStart,yStart,cxTotal,cyTotal,hdcMem,0,0,SRCCOPY);
		 }
	  }

	DeleteDC(hdcMem);
	ReleaseDC(hwnd,hdc);
	yCenterOld = yCenter;
}


