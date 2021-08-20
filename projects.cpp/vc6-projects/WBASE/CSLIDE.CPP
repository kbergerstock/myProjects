// slide custom control

#include "tfcvt.h"
#include "wmacros.h"

#ifndef __cSLIDE_H
#include "cSLIDE.h"
#endif

cSLIDE::cSLIDE(HWND hwnd) : cWinFrame()
{
	SetName("SLIDECONTROL");
	SetStyle(WS_CHILDWINDOW | WS_DLGFRAME | WS_VISIBLE);
	cDiamond = new cDIAMOND(hwnd);
	cValue = new cVALUE(hwnd);
    resolution = 2;
    BarWidth = 200;
	SetPos(hwnd);
	Location = Min = 0.0;
	Max = 100.0;
	gL = 55.0;
	gH = 65.0;
	yH = 75.0;
	yL = 45.0;
	value = 0.0;
    if(!isRegistered())
        Register();
}

cSLIDE::~cSLIDE()
{
	delete cDiamond;
	delete cValue;
}

bool cSLIDE::IsOk(void)
{
	bool r = false;
	if(value > gL && value < gH)
		r = true;
	return r;
}

void cSLIDE::Reset(void)
{
	value = 0.0;
	Draw(value);
}

void cSLIDE::SetResolution(int r)
{
	resolution = r;
	cValue->SetResolution(r);
}

void cSLIDE::SetPos(HWND hwnd)
{
	RECT rect;
	GetClientRect(hwnd,&rect);
	int xstart = (rect.right - 200)/2;
	int ystart = (rect.bottom - 375)/2;
	SetSize(xstart,ystart,200,375);
	cDiamond->SetPos(xstart,ystart,BarWidth,375);
	cValue->SetPos(xstart,ystart,200,375);
}

void cSLIDE::SetPos(int x, int y, int w, int h)
{
	if(BarWidth > w)
		BarWidth = w;
	SetSize(x,y,w,h);
	cDiamond->SetPos(x,y,BarWidth,h);
	cValue->SetPos(x,y,w,h);
}

void cSLIDE::Draw(double position)
{
	value = position;
	cValue->Draw(position);

	if (position > Max)
		position = Max;
	else if(position < Min)
		position = Min;

	double rp = 0.0;
	if((Max - Min) > 0.0)
		rp = (position - Min) / (Max - Min);

	if(position > gL && position < gH)
		cDiamond->Draw(rp,GREEN);
	else if( position > yL && position < yH)
		cDiamond->Draw(rp,YELLOW);
	else
		cDiamond->Draw(rp,RED);
}

void cSLIDE::Draw(int loc)
{
	cDiamond->Draw(loc,RED);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void cSLIDE::Paint(HWND hwnd,HDC hdc)
{
	int ndiv = 10;
	if((_h-75) < 200)
		ndiv = 5;

	StrOut(hdc,4,4,LPSTR(title));
	int d = (_h-75)/ndiv;
	double div = (Max-Min)/double(ndiv);
	int _y = 25+d/2;
	int _x = 4 + (_w/8)+(BarWidth/2);

	TFCVT<double> fcvt;
	fcvt.SetDecimalPos(resolution);
	char buf[20];

	double yf = Max - (div/2.0);
	for(int i = 0;i < ndiv; i++)
	  {

		fcvt.Convert(yf,LPSTR(buf));
		MoveToEx(hdc,_x,_y,NULL); LineTo(hdc,_x+8,_y);
		TextOut(hdc,_x+12,_y-8,LPSTR(buf),lstrlen(LPSTR(buf)) );
		_y += d;
		yf -= div;
	  }
	Draw(value);
}

HWND cSLIDE::Create(HWND hwnd, int id)
{
	HWND tHwnd = cWinFrame::Create(hwnd,id);

	if( tHwnd)
	  {
		hDiamond = cDiamond->Create(tHwnd,id+1);
		hValue = cValue->Create(tHwnd,id+2);
	  }

	return tHwnd;
}

bool cSLIDE::Register(void)
{
	cDiamond->Register();
	cValue->Register();
	return cWinFrame::Register();
}

/* -------------------------------------------------------- */
#if defined(__BORLANDC__)
#pragma argsused
#endif
cDIAMOND::cDIAMOND(HWND hwnd) : cWinFrame()
{
	SetName("DIAMONDCONTROL");
	position = 0;
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void cDIAMOND::SetPos(int xs,int ys, int w, int h)
{
	int width = w/2;
	int height = h - 75;
	int xStart = w/8;
	int yStart = 25;

	SetSize(xStart,yStart,width,height);
}

void cDIAMOND::OnCreated(HWND hwnd)
{
	RedDiamond.Create(hwnd,RGB(255,255,255),RGB(255,0,0));
	GreenDiamond.Create(hwnd,RGB(255,255,255),RGB(0,192,0));
	YellowDiamond.Create(hwnd,RGB(255,255,255),RGB(255,255,0));
}

void cDIAMOND::Draw(int loc,int color)
{
	if(loc > _h) loc = _h;
	if(loc < 0) loc = 0;
	switch(color)
	 {
		case GREEN:
			GreenDiamond.Draw(hWnd,loc);
			RedDiamond.Track(loc);
			YellowDiamond.Track(loc);
			break;
		case YELLOW:
			YellowDiamond.Draw(hWnd,loc);
			RedDiamond.Track(loc);
			GreenDiamond.Track(loc);
			break;
		 default:
			RedDiamond.Draw(hWnd,loc);
			GreenDiamond.Track(loc);
			YellowDiamond.Track(loc);
			break;
	 }
	position = loc;
}

void cDIAMOND::Draw(double rp,int color)
{
	RECT rect;
	GetClientRect(hWnd,&rect);
	int loc = rect.bottom - int(double(rect.bottom) * rp);
	Draw(loc,color);
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void cDIAMOND::Paint(HWND hwnd,HDC hdc)
{
	RedDiamond.Draw(hWnd,_h);
	YellowDiamond.Track(_h);
	GreenDiamond.Track(_h);
}

