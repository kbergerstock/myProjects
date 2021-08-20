// -----------------------------------------------
//	dlgbase.h
//	(c) K. R. Bergerstock,1998
//	version 1 - initial attempt
// --------------------------------------------------

#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#ifndef __DIR_H
#include <dir.h>
#endif

#ifndef __DLGBASE_H
#define  __DLGBASE_H

class DLGMAIN
{
  private:

  public:
	static HINSTANCE hInstance;
	static HINSTANCE hPinstance;
	static int nCmdShow;
	static char szCurrentDir[MAXPATH];
	static char szINIname[MAXPATH];

	BOOL bQuit;

	DLGMAIN(HINSTANCE,HINSTANCE,int);
	void  CreateINIname(LPSTR);
	LPSTR GetINIname(void);
};

#endif
