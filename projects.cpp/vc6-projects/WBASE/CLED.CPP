// cLED class functions

#include "cLED.h"
#include "wmacros.h"

#if defined(__BORLANDC__)
#pragma argsused
#endif
cLED::cLED(HWND hwnd) : cWinFrame()
{
	SetName("LEDCONTROL");
    color = NEUTRAL;

	if(!isRegistered() )
    	Register();
}

cLED::~cLED()
{
}

void cLED::OnCreated(HWND hwnd)
{
	Red.Create(hwnd,RGB(255,255,255),RGB(255,0,0));
    Green.Create(hwnd,RGB(255,255,255),RGB(0,192,0));
    Neutral.Create(hwnd,RGB(255,255,255),RGB(128,128,128));
}

void cLED::Draw(short c)
{
	color = c;
    switch(color)
     {
        case RED:
        	Red.Draw(hWnd);
            break;

        case GREEN:
        	Green.Draw(hWnd);
            break;

        case NEUTRAL:
        	Neutral.Draw(hWnd);
            break;
     }
}

#if defined(__BORLANDC__)
#pragma argsused
#endif
void cLED::Paint(HWND hwnd,HDC hdc)
{
	int xs = 4 + Red.GetcxTotal();
	StrOut(hdc,xs,0,LPSTR(title));
    Draw(color);
}
