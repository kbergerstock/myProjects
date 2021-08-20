//*******************************************************************
//              
//  FILE:       CSPRITE.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  cSPRITE
//              
//  DATE:       03.08.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes
#include "cSPRITE.h"

cSPRITE::cSPRITE(HINSTANCE hInstance,int rcBitmap, int rcMask)
{
	Create(hInstance,rcBitmap,rcMask);
}

cSPRITE::~cSPRITE()
{
}

void cSPRITE::Create(HINSTANCE hInstance,int rcBitmap, int rcMask)
{
	HBITMAP s = sprite.Create(hInstance,rcBitmap);
    HBITMAP m = mask.Create(hInstance,rcMask);

	int cx = sprite.getWidth();
    int cy = sprite.getHeight();

    HDC hdc_s = CreateCompatibleDC(NULL);
    SelectObject(hdc_s,s);
	HDC hdc_m = CreateCompatibleDC(NULL);
	SelectObject(hdc_m,m);
    BitBlt(hdc_s,0,0,cx,cy,hdc_m,0,0,SRCAND);

	DeleteDC(hdc_m);
    DeleteDC(hdc_s);
}

void cSPRITE::Draw(HDC hdc)
{
	mask.Blit(hdc,_x,_y,0x220326);
    sprite.Blit(hdc,_x,_y,SRCPAINT);

}

void cSPRITE::Move(short x, short y)
{
	_x = x;
    _y = y;
}
