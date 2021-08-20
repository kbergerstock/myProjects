
// cDLGWIN
// class that can be used when you want to create a modeless dialog windoa as your main application

#include "cDLGWIN.h"

cDLGWIN::cDLGWIN(HINSTANCE hInstance ) : cMODELESS(hInstance)
{

}

cDLGWIN::~cDLGWIN()
{
}

void cDLGWIN::create(LPSTR lpszTemplate)
{
    // creat e the dialgo from the template
    HWND hd = cMODELESS::Create(NULL,lpszTemplate);

    // if successfule run the main loop
    if( hd != NULL)
        run(hd);
    else
        throw("DIALOG CREATION ERROR");
}

int cDLGWIN::run(HWND hwnd)
{
    MSG msg;
    
    while(  GetMessage(&msg,0,0,0) )     // while not WM_QUIT
     {
        if(!IsDialogMessage(hwnd,&msg))
         {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
         }
     }
    return msg.wParam;
}

BOOL cDLGWIN::dlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	bool r = false;

	switch(msg)
     {
     	case WM_CLOSE:
        	PostQuitMessage(0);
        	DestroyWindow(hDlg);
            r = true;
            break;

	    case WM_WIN_CREATED:
        	r = true;
        	break;
     }

	return r;
}