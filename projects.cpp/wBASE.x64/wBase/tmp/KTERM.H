
#ifndef __KEYBUF_H
#include "keybuf.h"
#endif

#ifndef __WSTDIO_H
#include "wstdio.h"
#endif

#ifndef __KTERM_H
#define  __KTERM_H

class kTERMINAL
{
  protected:
	KeyBuffer *Port;
	WSTDIO    *TTY;

  public:
	kTERMINAL();
	~kTERMINAL();

	void Init(KeyBuffer *, WSTDIO *);
	int NumInBuffer(void);

	virtual int  wputc(char);
	virtual char wgetc(void);
	virtual int  wputs(LPSTR);
	HWND wopen(HWND,bool);
	void PutStr(LPSTR);
    void Flush(void);
};

#endif
