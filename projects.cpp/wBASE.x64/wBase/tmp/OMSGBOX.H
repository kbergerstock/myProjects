// child messag box control

#ifndef __MSGBOX_H
#define  __MSGBOX_H

#include "windbase.h"
#include "strarray.h"

class cMsgBox : public ChildWindow
{
  private:
   static int isRegistered;
   STRARRAY* data;

  public:
	cMsgBox(HWND,int);						// constructor
	~cMsgBox(); 							// destructor

	BOOL Register(void);

	HWND Create(HWND, int);

	// message cracker handling routines
	virtual void OnPaint(HWND);
	virtual void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	virtual LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );

	void DisplayMsg(char far* szMsg);
	void DisplayMsg(UINT);

	STRARRAY far* GetPtr(void) { return (STRARRAY far *) data; };

};

#endif
