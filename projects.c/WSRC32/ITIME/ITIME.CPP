#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#include "iDialog.h"
#include "itimedlg.rh"


int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    try
     {
        iDialog MainDialog(hInstance,"MAIN_DIALOG");
     }
    catch(char *em)
     {
     	char buf[100];
        wsprintf(buf,"Error x%x",GetLastError() );
      	MessageBox(NULL,buf,em,MB_ICONSTOP | MB_OK);
     }


	return 0;
}


