#include "numout.h"

void NumXOut(HDC hdc, int x , int y, DWORD tmp)
{
  char szBuf[10];
  int len = wsprintf(szBuf, "%08lX", tmp );
  TextOut(hdc,x,y,szBuf,len);
}

void NumXOut(HDC hdc, int x , int y, WORD tmp)
{
  char szBuf[10];
  int len = wsprintf(szBuf, "%04X", tmp );
  TextOut(hdc,x,y,szBuf,len);
}

void NumXOut(HDC hdc, int x , int y, BYTE tmp)
{
  char szBuf[15];
  int len = wsprintf(szBuf, "%02X", tmp );
  TextOut(hdc,x,y,szBuf,len);
}

void NumOut(HDC hdc, int x , int y, long tmp)
{
  char szBuf[10];
  int len = wsprintf(szBuf, "%ld", tmp );
  TextOut(hdc,x,y,szBuf,len);
}

void NumOut(HDC hdc, int x , int y, int tmp)
{
  char szBuf[15];
  int len = wsprintf(szBuf, "%5d", tmp );
  TextOut(hdc,x,y,szBuf,len);
}


