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
  
  if(!isRegistered())                   // if this class has not been registered
	{									// then register the class
        WNDCLASSEX  wndclass ;

        wndclass.cbSize         = sizeof(WNDCLASSEX);
        wndclass.style          = class_style;            // typically CS_HREDRAW | CS_VREDRAW;
        wndclass.lpfnWndProc    = ::MainWndProc;
        wndclass.cbClsExtra	    = 0;
        wndclass.cbWndExtra	    = sizeof(cWINBASE*);
        wndclass.hInstance	    = hInstance();
        wndclass.hIcon          = HICON(icon);     
        wndclass.hIconSm        = HICON(iconSm);  
        wndclass.hCursor        = HCURSOR(cursor); 
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
bool cWINBASE::Create(int id)
{
    HMENU _id = id > 0 ? HMENU(MAKEINTRESOURCE(id)) : NULL;
    try
    {
        if (Register())         // REGISTER THE CLASS
        {
            // CREATE THE APPLICATION WINDOW  or the custom control
            setHWND(CreateWindowEx(
                dwExtStyle,
                szWinName,
                szWinDesc,
                dwStyle,
                _x,				// set window orgin
                _y,
                _w,				// set window height
                _h,				// set window width
                hwndParent,     // set the parent window if null this is the top level
                _id,            // set up the menu the control id use NULL for a top level window
                hInstance(),
                NULL
            ));
            if (hWnd())		    // if creation process was successful
            {
                // set a pointer to the class into the CbWndExtra
                SetPointer(hWnd(), LONG_PTR(this));
                // send a window created message to the call back function
                SendMessage(hWnd(), WM_WIN_CREATED, 0, 0L);
                Show(nCmdShow());
            }
            else
            {
                throw "window creation error: ";
            }
        }
        else
        {
            throw "window register error: ";
        }
    }
    catch (const char* errmsg)
    {
        // HANDLE THE ERROR
        MessageBox(NULL, errmsg, szWinName, MB_OK);
        setHWND(NULL);
    }
    // return true if creation process worked
    return (hWnd() ? true : false);
}
