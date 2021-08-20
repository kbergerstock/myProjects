// -----------------------------------------------
//  demo.cpp
//  (c) K. R. Bergerstock,1996
//  version 1 - initial attempt
// --------------------------------------------------

#include <windows.h>
#include "winhat.h"

// --------------------------------------------------

MAIN::MAIN(HINSTANCE hinst,HINSTANCE hpinst, int show)
{
  hInstance = hinst;
  hPinstance = hpinst;
  nCmdShow = show;
}

int MAIN::Run(void)
{
 MSG msg;

 while (GetMessage (&msg, NULL, 0, 0))
    {
      TranslateMessage (&msg) ;
      DispatchMessage (&msg) ;
    }
 return msg.wParam ;
}

//--------------------------------------------------------------------

AppWin::AppWin(HINSTANCE hInst , char* AppName, char* AppDesc)
{
    hInstance = hInst;
    szAppName = AppName;
    szAppDesc = AppDesc;
}


void AppWin::Register(void)
{
  WNDCLASS   wndclass ;

  wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
  wndclass.lpfnWndProc   = ::MainWndProc;
  wndclass.cbClsExtra    = 0 ;
  wndclass.cbWndExtra    = sizeof(AppWin);
  wndclass.hInstance     = hInstance ;
  wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
  wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
  wndclass.hbrBackground = GetStockObject (BLACK_BRUSH) ;
  wndclass.lpszMenuName  = NULL ;
  wndclass.lpszClassName = szAppName ;

  RegisterClass (&wndclass) ;
}

void AppWin::Create(void)
{
  hWnd = CreateWindow ( szAppName,
                        szAppDesc,
                        WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        CW_USEDEFAULT,
                        NULL,
                        NULL,
                        hInstance,
                        NULL) ;
 SetPointer(hWnd,this);

};

//

LRESULT CALLBACK _export MainWndProc (HWND hwnd , UINT msg , WPARAM wParam , LPARAM lParam)
 {

   AppWin* w = (AppWin*)(GetPointer(hwnd) );

     switch (msg)
        {
          case WM_SIZE:
            w->cxClient = LOWORD(lParam);               // get client window
            w->cyClient = HIWORD(lParam);               // width and height  
            return 0;

          case WM_CREATE:
            MoveWindow(hwnd,0,0,800,600,1);
            return 0;

          case WM_PAINT:
            w->DrawHat(hwnd);
            return 0 ;

          case WM_DESTROY:
            PostQuitMessage (0) ;
            return 0 ;
         }

     return DefWindowProc (hwnd, msg, wParam, lParam) ;
 }

//

#pragma argsused

int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
  {
     MAIN main(hInstance,hPrevInstance,nCmdShow);

     static char AppName[] = "WINHAT1" ;
     static char AppDesc[] = "Windows 3D Curve Demo @ KRB";

     AppWin appWin(hInstance,AppName,AppDesc);

     if (!hPrevInstance)
       appWin.Register();

     appWin.Create();

     appWin.Show(nCmdShow);
     appWin.Update();

     return main.Run();
  }

