#ifndef __WINDOWS_H
    #ifndef STRICT
        #define STRICT
    #endif

    #define WIN32_LEAN_AND_MEAN
    
    #include <windows.h>
#endif

#ifndef __tMUTEX_H
#define __tMUTEX_H

class tMUTEX
{
    protected:
        HANDLE hMutex;
        DWORD  error;
         
        tMUTEX(const tMUTEX&) {}

    public:

    tMUTEX()            { hMutex = 0; error = 0;}

    tMUTEX(bool bi)
     {
      hMutex = CreateMutex(NULL,bi,NULL);
      error = 0;
     }

    tMUTEX(bool bi ,char* mn)
     {
       hMutex = CreateMutex(NULL,bi,mn);
       error = GetLastError();
     }
  

    ~tMUTEX()
      {
        if(hMutex)
            CloseHandle(hMutex);
      }         

    bool doesExist()
     {
        return error == ERROR_ALREADY_EXISTS; 
     }
};

#endif