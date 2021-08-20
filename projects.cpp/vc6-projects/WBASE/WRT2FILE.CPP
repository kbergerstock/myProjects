#include "savebuf.h"


void Write2File(LPSTR szFileName, LPSTR szBuf)
{
    HANDLE hFile = CreateFile(szFileName,
    						  GENERIC_WRITE,
                              FILE_SHARE_READ,
                              NULL,
							  OPEN_ALWAYS,
                              FILE_ATTRIBUTE_NORMAL,
                              NULL );

    if(hFile != INVALID_HANDLE_VALUE)				// if the file was opened
     {
	    SetFilePointer(hFile,0L,NULL,FILE_END);		// then set the pointer
        DWORD nbw;

	    if( GetLastError() == NO_ERROR)				// if no error
	      WriteFile(hFile,szBuf,lstrlen(szBuf),&nbw,NULL);	// write data to file

	    CloseHandle(hFile);							// close the file
     }
}
