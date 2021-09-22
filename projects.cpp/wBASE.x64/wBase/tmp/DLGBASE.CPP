// -----------------------------------------------
//	dlgbase.cpp
//	(c) K. R. Bergerstock,1998
//	version 1 - initial attempt
// --------------------------------------------------

#include "dlgbase.h"
// --------------------------------------------------

HINSTANCE DLGMAIN::hInstance = 0;
HINSTANCE DLGMAIN::hPinstance = 0;
int DLGMAIN::nCmdShow = 0;
char DLGMAIN::szCurrentDir[MAXPATH];
char DLGMAIN::szINIname[MAXPATH];

DLGMAIN::DLGMAIN(HINSTANCE hinst,HINSTANCE hpinst, int show)
{
  hInstance = hinst;
  hPinstance = hpinst;
  nCmdShow = show;

  lstrcpy(szCurrentDir,"X:\\");
  szCurrentDir[0] = 'A' + getdisk();
  getcurdir(0,szCurrentDir+3);
  lstrcat(szCurrentDir,"\\");
}

void DLGMAIN::CreateINIname(LPSTR szFileName)
{
 lstrcpy(szINIname,szCurrentDir);
 lstrcat(szINIname,szFileName);
}

LPSTR DLGMAIN::GetINIname(void)
{ return szINIname; }

