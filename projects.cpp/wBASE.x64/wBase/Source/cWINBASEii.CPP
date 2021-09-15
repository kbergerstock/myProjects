//*******************************************************************
//              
//  FILE:       cWINBASE
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    wCONTROLS
//              
//  COMPONENT:  cWINBASE
// //              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#include "cWINBASE.h"

bool cWINBASE::Register()
{
  bool  isOk = false;
  
  if(!isRegistered(szWinName))          // if this class has not been registered
	{									// then register the class
        WNDCLASSEX  wndclass ;

        wndclass.cbSize         = sizeof(WNDCLASSEX);
        wndclass.style          = class_style;            // typically CS_HREDRAW | CS_VREDRAW;
        wndclass.lpfnWndProc    = ::MainWndProc;
        wndclass.cbClsExtra	    = 0;
        wndclass.cbWndExtra	    = sizeof(cWINBASE*);
        wndclass.hInstance	    = hinstance ;
        wndclass.hIcon          = HICON(icon);      // FIX LoadIcon(NULL, IDI_APPLICATION);
        wndclass.hIconSm        = HICON(iconSm);  
        wndclass.hCursor        = HCURSOR(cursor);  // FIX LoadCursor(NULL, IDC_ARROW);
        wndclass.hbrBackground  = bkGnd;
        wndclass.lpszMenuName   = LPCSTR(menu);
        wndclass.lpszClassName  = szWinName ;

        isOk =  (RegisterClassEx(&wndclass) ? true: false);
   }
  else
   {
    isOk = true;
   }  
 return isOk;
}
