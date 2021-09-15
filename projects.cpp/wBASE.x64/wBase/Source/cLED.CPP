// cLED class functions
#include <strsafe.h>
#include "cLED.h"
#include "wmacros.h"

cLED::cLED(HINSTANCE hIinstance, HWND parent) : subWindow(hInstance, 1, LPSTR("LEDCONTROL"))
{
    color = NEUTRAL;
    hParent = parent;

	if(!isRegistered() )
    	Register();
    hWnd = CreateControl(parent);   // FIX
    if (Control_id && hWnd)
    {
        Show(SW_SHOW);
        Update();
    }
}

void cLED::SetTitle(char* t)
{
    StringCchCopy(title, TITLE_SIZE - 1, t); 
}

// once the control is created create the bitmaps needed
void cLED::OnCreated(HWND hWnd)
{
	Red.Create(hWnd,RGB(255,255,255),RGB(255,0,0));
    Green.Create(hWnd,RGB(255,255,255),RGB(0,192,0));
    Neutral.Create(hWnd,RGB(255,255,255),RGB(128,128,128));
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

void cLED::Paint(HWND hwnd,HDC hdc)
{
	int xs = 4 + Red.GetcxTotal();
	StrOut(hdc,xs,0,LPSTR(title));
    Draw(color);
}
