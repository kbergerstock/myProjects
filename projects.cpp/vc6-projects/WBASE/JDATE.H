#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#include "time.h"

#ifndef __JDATE_H
#define __JDATE_H

char *itod(long,char*,int);

char GetPrivateProfileChar(LPSTR , LPSTR ,char , LPSTR );

class JDATECODE
{
	private:
	  char 	datecode_J[5];					// julian day code
	  char  datecode_C[8];					// common date code
	  char 	SHIFT[5];                       // shift id

	  struct tm* tblock;
	  char 	szTimeStr[50];
	  char 	TestCodes[5];

	  int	RollCounter;
	  char  szRollStr[5];

	public:
	  void	Fill(void);
	  char* GetJDC(void);					// get a pointer to a julian date code DDDY
	  char* GetCDC(void);					// get a pointer to a common date code
	  char* GetShift(void);					// get a pointer to a shift id string
	  char* GetTimeStr(void);				// get a pointer to a time string
	  char* GetRollStr(void);				// get a pointer to a roll code string
	  void  SetIds(LPSTR);					// set the shift id symbols
};

#endif
