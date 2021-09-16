// status bar child window function bodies
// statbar.cpp

#include <ctype.h>
#include <strsafe.h>

#ifndef __STATBAR_H
#include "statbar.h"
#endif


cSTATBAR::cSTATBAR(HINSTANCE hInstance, HWND hPwnd, int control_id) :
	subWindow(hInstance, SW_SHOW, LPSTR("STATBAR"))
{

    if(!isRegistered() )
        Register();        
	   
	if (isRegistered())
	{
		SetId(control_id);
		SetBkGnd(bkGnd);
		SetWinStyle(WS_CHILDWINDOW | WS_VISIBLE);
		SetExtStyle(WS_EX_STATICEDGE);
		GetSize(hPwnd);
		for (int i = 0; i < 4; i++)
			Msg[i][0] = '\0';

		setHWND(CreateControl(hPwnd, Control_id));
		Show(nCmdShow());
		Update();
	}
}

void cSTATBAR::GetSize(HWND hPwnd)
{
   RECT rect;
   // get the size of the parent window
   GetClientRect(hPwnd,&rect);					
   getTextMetrics(hPwnd);
   _h = cyChar + 4;
   _w = rect.right;
   _x = rect.left;
   _y = rect.bottom - _h;

   // calc the start positions of the message areas
   sp[0] = 4;
   sp[1] = 4 + ((2 * _w) / 8);
   sp[2] = 4 + ((11 * _w) / 16);
   sp[3] = 4 + ((15 * _w) / 16);
   sp[4] = _w;
}

void cSTATBAR::Draw(HWND hPwnd,HWND hCwnd)
{
  GetSize(hPwnd);
  MoveWindow(hCwnd,_x,_y,_w,_h,TRUE);
}

void cSTATBAR::Paint(HWND hwnd ,HDC hdc)
{
	LOGBRUSH lb;
	GetObject(bkGnd,sizeof(LOGBRUSH),LPSTR(&lb) );

	MoveToEx(hdc,0,0,NULL);				// draw the status bar top delimieter								
	LineTo(hdc,_w,0);

	oldBK = SetBkColor(hdc,lb.lbColor);
    for(int i = 0; i < 4; i++)
     {
     	TextOut(hdc,sp[i],2,LPSTR(Msg[i]),lstrlen(Msg[i]) );
     }
	SetBkColor(hdc,oldBK);
}


void cSTATBAR::SetMessage(LPSTR msg,int i ,int n)
{
	StringCchCopy(LPSTR(Msg[i]), MSG_SIZE, LPSTR(msg));
	RECT rect;
	GetClientRect(hWnd(),&rect);
	rect.left = sp[i];								// clear the message area
	rect.right = sp[i+1] - 1;
	InvalidateRect(hWnd(),&rect,TRUE);
	Update();
}

// THE CLASS CALL BACK FUNCTION
LRESULT cSTATBAR::WndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
 {
	 switch (msg)
	   {
		  case WM_STATBAR:
				switch(wParam)
				 {
				  case MSGONE:
                    SetMessageOne(LPSTR(lParam));		break;
				  case MSGTWO:
                  	SetMessageTwo(LPSTR(lParam));		break;
				  case MSGTHREE:
                  	SetMessageThree(LPSTR(lParam));		break;
				  case MSGFOUR:
                  	SetMessageFour(LPSTR(lParam));		break;
				 }
			return 0;

		  default:
			return subWindow::WndProc (hwnd , msg , wParam , lParam);

		 }
 }

