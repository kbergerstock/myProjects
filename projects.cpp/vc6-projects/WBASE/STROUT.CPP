#ifndef __WINDOWS_H
#define STRICT
#include "windows.h"
#endif

#include "wmacros.h"

void StrOut(HDC hdc,int x, int y, LPSTR szbuf)
{
  int len = lstrlen(szbuf);
  TextOut(hdc,x,y,szbuf,len);
}
