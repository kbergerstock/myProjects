
#include "kterm.h"

#ifndef __CTYPE_H
#include <ctype.h>
#endif

kTERMINAL::kTERMINAL()
{
  Port = NULL;
  TTY =  NULL;
}

kTERMINAL::~kTERMINAL() {}

void kTERMINAL::Init(KeyBuffer *port, WSTDIO *wnd)
{
  Port = port;
  TTY = wnd;
}

int kTERMINAL::wputc(char c)
{
  int r = 0;
  if(Port)
   r = Port->PutChar(c);

  if(TTY)
	TTY->wputc(c);

  if(c == '\r')
	wputc('\n');

  return r;
}

int kTERMINAL::NumInBuffer(void)
{
  int r = 0;
  if(Port)
	r = Port->NumInBuffer();
  return r;
}

char kTERMINAL::wgetc(void)
{
  char r = 0;
  if(Port)
   {
	 if(Port->NumInBuffer() )
	  {
		r = Port->GetChar();
	  }
   }

  return (r == 0x20 ? r : (isspace(r) ?  0  : toupper(r)) );
}

int kTERMINAL::wputs(LPSTR szStr)
{
  int r = 0;
  if(Port)
   r = Port->PutStr(szStr);

  if(TTY)
	TTY->wputs(szStr);

  return r;
}

void kTERMINAL::PutStr(LPSTR szStr)
{
  if(TTY)
	TTY->wputs(szStr);
}

HWND kTERMINAL::wopen(HWND hWndParent, bool bQuit)
{
   return TTY ? TTY->wopen(hWndParent,bQuit) : HWND(0);
}

void kTERMINAL::Flush(void)
{
  if(Port)
    Port->Flush();
}
