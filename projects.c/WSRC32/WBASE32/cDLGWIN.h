// cDLGWIN
// class that can be used when you want to create a ,odeless dialog windoa as your main application

#include "cMODELESS.h"

#ifndef __cDLGWIN_H
#define __cDLGWIN_H

class cDLGWIN : public cMODELESS
{
    protected:

    int run(HWND);

    virtual BOOL dlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam);

    void create(LPSTR);

    public:
        cDLGWIN(HINSTANCE);

        virtual ~cDLGWIN();

};
#endif
