#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#endif

// display formattting functions

void  NumXOut(HDC,int,int,DWORD);
void  NumXOut(HDC,int,int,WORD);
void  NumXOut(HDC,int,int,BYTE);
void  NumOut(HDC,int,int,int);
void  NumOut(HDC,int,int,long);

void  StrOut(HDC,int,int,LPSTR);


