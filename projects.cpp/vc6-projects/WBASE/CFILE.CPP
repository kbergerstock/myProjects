// class cFILE function bodies

#ifndef __CFILE_H
#include "cfile.h"
#endif

cFILE::cFILE()
{
/*
	hBuffer = NULL;
	lpBuffer = NULL;
*/
}

cFILE::~cFILE()
{
 /*
	if(hBuffer != NULL)
		{
			GlobalUnlock(hBuffer);
			GlobalFree(hBuffer);
		}
*/        
}

HANDLE cFILE::Open(LPSTR szFileName)
{
	hFile = CreateFile( szFileName,
                        GENERIC_READ | GENERIC_WRITE,
                        FILE_SHARE_READ,
                        NULL,
                        OPEN_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL );

    if((hError=GetLastError() ) == ERROR_ALREADY_EXISTS)
    	hError = 0;
    GetFileLength(hFile);
	return hFile;
}

HANDLE cFILE::Create(LPSTR szFileName)
{
	hFile = CreateFile( szFileName,
                        GENERIC_READ | GENERIC_WRITE,
                        FILE_SHARE_READ,
                        NULL,
                        CREATE_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL,
                        NULL );

	hError = GetLastError();
    GetFileLength(hFile);
	return hFile;
}


void cFILE::Close(void)
{
  if(hFile != INVALID_HANDLE_VALUE)
	 CloseHandle(hFile);
}

void cFILE::Rewind(void)
{
	if(hFile != INVALID_HANDLE_VALUE)
    	SetFilePointer(hFile,0L,NULL,FILE_BEGIN);
}

void cFILE::WriteBuf(LPSTR buf, int len)
{
	DWORD nbw;
	if(hFile != INVALID_HANDLE_VALUE)
     {
     	SetFilePointer(hFile,0L,NULL,FILE_BEGIN);
		WriteFile(hFile,buf,len,&nbw,NULL);		// write data to file
        GetFileLength(hFile);
      }
}

void cFILE::ReadBuf(LPSTR buf, int len)
{
	DWORD nbr;
	if(hFile !=INVALID_HANDLE_VALUE)
		ReadFile(hFile,buf,len,&nbr,NULL);

	hError = GetLastError();
}

void cFILE::AddBuf(LPSTR buf, int len)
{
	if(hFile !=INVALID_HANDLE_VALUE)
	{
    	DWORD nbw;
 		SetFilePointer(hFile,0L,NULL,FILE_END);
        WriteFile(hFile,buf,len,&nbw,NULL);
        GetFileLength(hFile);
	}
}

void cFILE::AddSzBuf(LPSTR szBuf)
{
	AddBuf(szBuf,lstrlen(szBuf));
}

void cFILE::WriteSzBuf(LPSTR szBuf)
{
	WriteBuf(szBuf,lstrlen(szBuf));
}

DWORD cFILE::GetFileLength(HANDLE hfile)
{
	DWORD lCurrentPos = SetFilePointer(hfile,0L,NULL,FILE_CURRENT);
	DWORD lFileLength = SetFilePointer(hfile,0L,NULL,FILE_END);
	length = lFileLength;
	SetFilePointer(hfile,lCurrentPos,NULL,FILE_BEGIN);
    return length;
}


