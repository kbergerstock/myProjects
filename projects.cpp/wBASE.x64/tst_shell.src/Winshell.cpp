// csn be used as 32 or 64 bit start point
// library converted to use universal window functions
// keith r. bergerstock  2021-08-25

#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#include "WinSHELL.h"
#include "cMUTEX.h"
#include "cDIALOG.H"
#include "ABOUT.H"
#include "shell_menu.rh"

cWINSHELL::cWINSHELL(int nc) : cAppWinFrame(nc){
    // setMenu(IDR_MENU1);
    setIcon(IDI_ICON1);
    setSmIcon(IDI_ICON1);
    if(Create() ) {
        Show(nc);
    }        
}

cWINSHELL::~cWINSHELL(){ }

LRESULT cWINSHELL::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

    switch (msg){
        HANDLE_MSG(hwnd, WM_COMMAND, OnCommand);
    }
    return cAppWinFrame::WndProc(hwnd, msg, wParam, lParam);
}

void cWINSHELL::OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch (id)
    {

        case IDM_EXIT:
            ExitWindow();
            break;

        case IDM_ABOUT_CMD:
        {
            pDIALOGBOX pBox = new AboutBox(hInstance());
            pBox->Display(hwnd, "AboutBox");
            delete pBox;
        }
        break;

        default:
            cAppWinFrame::OnCommand(hwnd, id, hwndCtl, codeNotify);
            break;
    }
}

void cWINSHELL::Paint(HDC hdc) {

}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    // the following three lines verify that only one copy of this program
    // is capable of runing under a win32 enviroment.
    tMUTEX prg(true,"WINSHELL");
    if(!prg.doesExist() )
     {
        cWINBASE::set_hInstance(hInstance);
        cWINSHELL shell(nCmdShow);
        cMSGLOOP  app;
        app.run();

     }
    else
     {
        MessageBox(NULL,"Application already running","ERROR",MB_OK);
     }

    return 0;
}
