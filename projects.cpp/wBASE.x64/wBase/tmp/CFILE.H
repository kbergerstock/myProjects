#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#include <windowsx.h>
#endif

#ifndef __CFILE_H
#define __CFILE_H

class _export cFILE
{
	private:
	  HANDLE hFile; 					// handle to open file
	  DWORD  hError;					// last error message
	  DWORD  length;					// length of file

      DWORD  GetFileLength(HANDLE);

	public:

	  cFILE();
	  ~cFILE();

	  HANDLE Create(LPSTR);
	  HANDLE Open(LPSTR);
      void   Rewind(void);
	  void   Close(void);
	  void   WriteBuf(LPSTR,int);
	  void   ReadBuf(LPSTR,int);
	  void   AddBuf(LPSTR,int);
	  void   AddSzBuf(LPSTR);
	  void   WriteSzBuf(LPSTR);

	  int    GetFileError(void) { return hError; }
	  DWORD	 GetFileLength(void){ return length; }

      /*
	  LPBYTE ReadFile(LPSTR);
	  void	 WriteFile(LPSTR);               		// write an internal buffer
	  void	 WriteFile(LPSTR ,LPBYTE ,UINT );		// write an external buffer
      */
};

#endif
