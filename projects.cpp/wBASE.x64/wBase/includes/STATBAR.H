// status bar child window header file
// statbar.h

#ifndef __subWindow_H
#include "subWindow.h"
#endif

#ifndef __STATBAR_H
#define __STATBAR_H

#define  STATBAR    10000 				// control id
#define  WM_STATBAR 10001			    // function control

#define	 MSGONE     101
#define  MSGTWO     102
#define  MSGTHREE   103
#define  MSGFOUR    104

#define WM_MSG_ONE 		(WM_STATBAR+MSGONE)
#define WM_MSG_TWO 		(WM_STATBAR+MSGTWO)
#define WM_MSG_THREE 	(WM_STATBAR+MSGTHREE)
#define WM_MSG_FOUR     (WM_STATBAR+MSGFOUR)

inline void SEND_MSG_ONE(HWND wnd,LPSTR szSTR)
	{SendMessage(wnd,WM_COMMAND,WM_MSG_ONE,LPARAM(szSTR) ); }

inline void SEND_MSG_TWO(HWND wnd,LPSTR szSTR)
	{SendMessage(wnd,WM_COMMAND,WM_MSG_TWO,LPARAM(szSTR) ); }

inline void SEND_MSG_THREE(HWND wnd,LPSTR szSTR)
	{SendMessage(wnd,WM_COMMAND,WM_MSG_THREE,LPARAM(szSTR) ); }

inline void SEND_MSG_FOUR(HWND wnd,LPSTR szSTR)
	{SendMessage(wnd,WM_COMMAND,WM_MSG_FOUR,LPARAM(szSTR) ); }

#define MSG_SIZE 40

class cSTATBAR : public subWindow
{
	private:
      char Msg[4][MSG_SIZE];
      int sp[5];

      void GetSize(HWND);

	public:
	  cSTATBAR(HINSTANCE, HWND, int);
	  void Draw(HWND,HWND);
	  void Paint(HWND,HDC);
      void SetMessage(LPSTR,int,int);

	  void SetMessageOne(LPSTR msg) 	{ SetMessage(msg,0,20);  }
	  void SetMessageTwo(LPSTR msg) 	{ SetMessage(msg,1,40); }
	  void SetMessageThree(LPSTR msg)	{ SetMessage(msg,2,12); }
      void SetMessageFour(LPSTR msg )	{ SetMessage(msg,3,8); }

      LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );
};

#endif
