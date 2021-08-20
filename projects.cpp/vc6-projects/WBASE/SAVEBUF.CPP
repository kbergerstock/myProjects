#ifndef __WINDBASE_H
#include "windbase.h"
#endif

#include "savebuf.h"


void SaveBuffer(LPSTR szSection,LPSTR szBuf)
{
	char szFileName[80];

	LPSTR szINI = (LPSTR)cMAIN::szINIname;
	GetPrivateProfileString("TITLE",szSection,"DATA.LOG",LPSTR(szFileName),80,szINI);
	Write2File(LPSTR(szFileName),szBuf);
}
