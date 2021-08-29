#include "W32SHELL.h"
#include "cMUTEX.h"


cW32SHELL::cW32SHELL(HINSTANCE hi,int nc) : cAppWinFrame(hi,nc)
{
    
   if(Create() )
     {
        Show(nc);
        Run();
     }        

}

cW32SHELL::~cW32SHELL()
{
}

int PASCAL WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    // the following three lines verify that only one copy of this program
    // is capable of runing under a win32 enviroment.
    tMUTEX prg(true,"W32SHELL");
    if(!prg.doesExist() )
     {
         cW32SHELL shell(hInstance,nCmdShow);
     }
    else
     {
        MessageBox(NULL,"Application already running","ERROR",MB_OK);
     }

    return 0;
}
