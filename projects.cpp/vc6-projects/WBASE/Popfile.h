// popup file functions

#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#endif

#ifndef  __COMMDLG_H
#include <commdlg.h>
#endif

#ifndef  __STDLIB_H

/* Constants for MSC pathname functions */

#define _MAX_PATH       80
#define _MAX_DRIVE      3
#define _MAX_DIR        66
#define _MAX_FNAME      9
#define _MAX_EXT        5

#endif

#define _MAX_NAME (_MAX_FNAME + _MAX_EXT)

#ifndef  __POPFILE_H
#define  __POPFILE_H

class POPFILE
{

  private:
	OPENFILENAME ofn;					// open file name struct
	char szfilter[256]; 			    // file filters
	DWORD Errval;						// Error value
	char buf[5];						// Error buffer

  public:
   POPFILE(HWND,LPSTR);
   ~POPFILE() {};

   BOOL OpenDlg(HWND, LPSTR, LPSTR);
   BOOL SaveDlg(HWND, LPSTR, LPSTR);

};

#endif
