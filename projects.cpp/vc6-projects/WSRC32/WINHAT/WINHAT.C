/*--------------------------------------------------
   winhat.C -- program to draw the grapic Hat for windows
   (c) K. R. Bergerstock,1996
   version 1 - initial attempt
  --------------------------------------------------*/

#include <windows.h>

long FAR PASCAL _export WndProc (HWND, UINT, UINT, LONG) ;

void DrawHat(HWND hwnd, int Width, int Height);

int PASCAL WinMain (HANDLE hInstance, HANDLE hPrevInstance,
                    LPSTR lpszCmdLine, int nCmdShow)
{
     static char szAppName[] = "WINHAT" ;
     HWND        hwnd ;
     MSG         msg ;
     WNDCLASS    wndclass ;

     if (!hPrevInstance)
          {
          wndclass.style         = CS_HREDRAW | CS_VREDRAW ;
          wndclass.lpfnWndProc   = WndProc ;
          wndclass.cbClsExtra    = 0 ;
          wndclass.cbWndExtra    = 0 ;
          wndclass.hInstance     = hInstance ;
          wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
          wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
		  wndclass.hbrBackground = GetStockObject (BLACK_BRUSH) ;
          wndclass.lpszMenuName  = NULL ;
          wndclass.lpszClassName = szAppName ;

          RegisterClass (&wndclass) ;
          }

     hwnd = CreateWindow (szAppName, "Windows Hat Demo",
						 WS_OVERLAPPEDWINDOW,
                         CW_USEDEFAULT, CW_USEDEFAULT,
                         CW_USEDEFAULT, CW_USEDEFAULT,
                         NULL, NULL, hInstance, NULL) ;

     ShowWindow (hwnd, nCmdShow) ;
     UpdateWindow (hwnd) ;

     while (GetMessage (&msg, NULL, 0, 0))
          {
          TranslateMessage (&msg) ;
          DispatchMessage (&msg) ;
          }
     return msg.wParam ;
}

long FAR PASCAL _export WndProc (HWND hwnd, UINT message, UINT wParam, LONG lParam)
     {
     static short cxClient,cyClient;			// holds width and height of client screen


     switch (message)
        {
          case WM_SIZE:
	       cxClient = LOWORD(lParam);           	// get client window
	       cyClient = HIWORD(lParam);           	// width and height  
		   return 0;

	  case WM_CREATE:
		   MoveWindow(hwnd,0,0,800,600,1);
		   return 0;

	  case WM_PAINT:
		   DrawHat(hwnd, cxClient ,cyClient );		// paint the hat
	       return 0 ;

          case WM_DESTROY:
               PostQuitMessage (0) ;
               return 0 ;
         }

     return DefWindowProc (hwnd, message, wParam, lParam) ;
     }
