#ifndef  __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#endif

char GetPrivateProfileChar(LPSTR , LPSTR ,char , LPSTR );

char GetPrivateProfileChar(LPSTR szSection, LPSTR szEntry,char dValue, LPSTR szINI)
{
   char tmp[5];
   char dString[5];
   dString[0] = dValue;
   dString[1] = '\0';

   GetPrivateProfileString(szSection,szEntry,LPSTR(dString),LPSTR(tmp),5,szINI);

   return *tmp;

}
