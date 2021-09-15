//*******************************************************************
//              
//  FILE:       CBITMAP.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  cBITMAP
//              
//  DATE:       03.08.2004
//              
//  COMMENTS:   - class to handle bitmaps
//              
//              
//*******************************************************************

// Includes

#include "cBITMAP.H"

cBITMAP::cBITMAP()
{
}

cBITMAP::~cBITMAP()
{
	Destroy();
}

HBITMAP cBITMAP::Create(HDC hdc ,long cx, long cy)
{
	handle = CreateCompatibleBitmap(hdc,cx,cy);
    return handle;
}

HBITMAP cBITMAP::Create(long cx, long cy )
{
	handle = CreateBitmap(cx,cy,1,1,NULL);
    return handle;
}

HBITMAP cBITMAP::Create(HINSTANCE hInstance,int rcBitmap)
{
	handle = LoadBitmap(hInstance,MAKEINTRESOURCE(rcBitmap) );
    GetObject(handle,sizeof(BITMAP),&bitmap);
    return handle;
}

void cBITMAP::Destroy(void)
{
	DeleteObject(handle);
}

void cBITMAP::Blit(HDC hdc, short xStart, short yStart, DWORD dwRop)
{
    HDC    hdcMem;
    POINT  ptSize, ptOrg;

    hdcMem = CreateCompatibleDC(hdc);
    SelectObject(hdcMem,handle);
    SetMapMode(hdcMem,GetMapMode(hdc));

    ptSize.x = bitmap.bmWidth;
    ptSize.y = bitmap.bmHeight;
    DPtoLP(hdc,&ptSize,1);

    ptOrg.x = 0;
    ptOrg.y = 0;
    DPtoLP(hdcMem,&ptOrg,1);

    BitBlt(hdc,xStart,yStart,ptSize.x,ptSize.y,hdcMem,ptOrg.x,ptOrg.y, dwRop);

    DeleteDC(hdcMem);
}

void cBITMAP::Draw(HDC hdc, short xStart, short yStart)
{
	Blit(hdc,xStart,yStart,SRCCOPY);
}
