#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#ifndef __cPROCESS_H
#define __cPROCESS_H

class cPROCESS
{
    private:
        STARTUPINFO si;
        PROCESS_INFORMATION pi;

    public:
        cPROCESS();
        ~cPROCESS();
         int launch(char * cmdLine);
};

#endif
