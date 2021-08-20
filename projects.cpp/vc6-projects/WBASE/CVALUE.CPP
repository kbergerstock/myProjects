// slide custom control

#include "tfcvt.h"
#include "wmacros.h"

#ifndef __cVALUE_H
#include "cVALUE.h"
#endif

#if defined(__BORLANDC__)
#pragma argsused
#endif
cVALUE::cVALUE() : cWinFrame()
{
	const LPSTR Name = "CELL";
 	resolution = 3;
	SetName(Name);
    SetDesc(Name);
	*buf='\0';
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
cVALUE::cVALUE(HWND hwnd) : cWinFrame()
{
	resolution = 3;
	SetName("VALUECONTROL");
	*buf='\0';
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void cVALUE::SetPos(int xs,int ys, int w, int h)
{
	int width = w/2;
	int height = 20;
	int xStart = w/8;
	int yStart = h - 40;

	SetSize(xStart,yStart,width,height);
}

void cVALUE::SetResolution(int r)
{
	resolution = r;
}

void cVALUE::Draw(double rp)
{

	TFCVT<double> fcvt;
	fcvt.SetDecimalPos(resolution);
	fcvt.Convert(rp,LPSTR(buf));
	Clear();

}

void cVALUE::Draw(long v)
{
	wsprintf(buf,"%ld",v);
    Clear();
}

void cVALUE::Draw(LPSTR s)
{
    lstrcpyn(LPSTR(buf),s,MAX_VALUE_BUF);
    Clear();
}

void cVALUE::Reset(void)
{
	*buf = '\0';
    Clear();
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void cVALUE::Paint(HWND hwnd,HDC hdc)
{
  TextOut(hdc,2,4,LPSTR(buf),lstrlen(LPSTR(buf)) );
}
