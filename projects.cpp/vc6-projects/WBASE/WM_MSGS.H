
#ifndef __WINDOWS_H
    #define  STRICT
    #include <windows.h>
    #include <windowsx.h>
#endif

#ifndef __WM_MSGS_H
#define __WM_MSGS_H

enum
{
    WM_WIN_CREATED = WM_USER+255,
    WM_WIN_CLEAR,
    WM_CHILD_CLEAR,
    WM_UPDATE,
};

#endif