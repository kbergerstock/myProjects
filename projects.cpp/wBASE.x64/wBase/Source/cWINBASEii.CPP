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
        wndclass.hInstance	    = hInstance();
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


// create the window
bool cWINBASE::Create()
{
    try
    {
        if (Register())                // REGISTER THE CLASS
        {
            setHWND( CreateWindowEx(   // CREATE THE APPLICATION WINDOW
                dwExtStyle,
                szWinName,
                szWinDesc,
                dwStyle,
                _x,						// set window orgin
                _y,
                _w,						// set window height
                _h,						// set window width
                hwndParent,             // set the parent window if null this is the top level
                HMENU(menu),            // set up the menu handle or the control id
                hInstance(),
                NULL
            ) );
            if (hWnd())					// if creation process was successful
            {
                SetPointer(hWnd(), LONG_PTR(this));		    // set a pointer to the class into the CbWndExtra
                SendMessage(hWnd(), WM_WIN_CREATED, 0, 0L);	// send a window created message to the call back function
                Show(nCmdShow());
            }
            else
            {
                throw "window creation error";
            }
        }
        else
        {
            throw "window register error";
        }
    }
    catch (...)
    {
        // FIX HANDLE THE ERROR
        setHWND(NULL);
    }
    return (hWnd() ? true : false);				    // return true if creation process worked
};
