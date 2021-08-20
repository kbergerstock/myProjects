// cfile function bodies

#include "cfile.h"

LPBYTE  cFILE::ReadFile(LPSTR szFileName)
{
	lpBuffer = NULL;

	HFILE hfile = Open(szFileName);							// open the file
	if(hfile != HFILE_ERROR)                                // if open was successful
	 {
		GetFileLength(hfile);								// get the file length
		if(length < 32000)									// if length is less than 32 k
		 {
			hBuffer = GlobalAlloc(GHND,length+1);			// allocate memory for file
			if(hBuffer != NULL)								// if allocation successful
			 {
				lpBuffer = (LPBYTE) GlobalLock(hBuffer);	// lock the memory into place
				_lread(hfile,lpBuffer,(WORD)length);		// read the file
				lpBuffer[length] = 0;						// null terminate the file
			 }
		 }
		Close();											// close the file
	 }
	return lpBuffer;										// return a pointer to the buffer
}

void	cFILE::WriteFile(LPSTR szFileName)
{
	HFILE hfile = Create(szFileName);							// open the file
	if(hfile != HFILE_ERROR)                                // if open was successful
	 {
		_lwrite(hfile,lpBuffer,length);
		Close();											// close the file
	 }
}

void	cFILE::WriteFile(LPSTR szFileName,LPBYTE _lpBuffer,UINT _length)
{
	HFILE hfile = Create(szFileName);							// open the file
	if(hfile != HFILE_ERROR)                                // if open was successful
	 {
		_lwrite(hfile,_lpBuffer,_length);
		Close();											// close the file
	 }
}
