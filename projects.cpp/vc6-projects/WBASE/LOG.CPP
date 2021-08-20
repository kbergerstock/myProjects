// log.cpp

#include "log.h"

#define Cells(I,J) mCells[((I)*10)+(J)]

LOG::LOG()
{
	File = NULL;
}

LOG::~LOG()
{
	Close();
}

void LOG::Open(LPSTR FileName)
{
	File = new DB3FILE(FileName,READONLY);
    File->OPEN();
    NumRecords = File->GetNumRecords();
}

void LOG::Close(void)
{
	if(File)
     {
		File->CLOSE();
    	delete File;
        File = NULL;
     }
}



REPORT::REPORT()
{
	hCells= GlobalAlloc(GPTR, 10 * 25 * sizeof(CELL) );
	mCells= LPCELL(GlobalLock(hCells));
}

REPORT::~REPORT()
{
	GlobalUnlock(hCells);
	GlobalFree(hCells);
}


void REPORT::ReadLine(long n, int row)
{
	if(File->GetFileOpenState() == FILE_OPENED) 	// if the file is opened
	 {
		File->ReadRecord(n);						// read the record

		for(int i = 1; i <= NumCells ; i++) 		// for each field
		 {
			Cells(row,i-1).len = 1 + File->GetLen(i);
			lstrcpy(Cells(row,i-1).contents,File->Get(i) );
		 }
	 }
}

void REPORT::ReadHeader(int row)
{
	if(File->GetFileOpenState() == FILE_OPENED) 	// if the file is opened
	 {
		for(int i = 1; i <= NumCells ; i++) 		// for each field
		 {
			Cells(row,i-1).len = 1 + File->GetLen(i);
			lstrcpy(Cells(row,i-1).contents,File->GetFldName(i) );
		 }
	 }
}

void REPORT::Scroll(HWND hwnd,int lines)
{
	NumRecords = File->GetNumRecords();
	if((start + lines) >= 1 && (end + lines) <= NumRecords)
     {
     	RECT client;
        GetClientRect(hwnd,&client);
        client.top += (4+cyChar);
     	start += lines;
        end  += lines;
        ReadLines();
        ScrollWindow(hwnd,0,-cyChar*lines,NULL,&client);
     }
}

void REPORT::Top(HWND hwnd)
{
	start = 1;
    end = start + 20;
    ReadLines();
    InvalidateRect(hwnd,NULL,TRUE);
    UpdateWindow(hwnd);
}

void REPORT::Bottom(HWND hwnd)
{
    end = NumRecords;
	start = end > NUMLINES ? end - NUMLINES : 1;
    ReadLines();
    InvalidateRect(hwnd,NULL,TRUE);
    UpdateWindow(hwnd);
}

void REPORT::ReadLines(void)
{
	File->OPEN();
    long r;
	int i = 1;
    NumLines = 1;
	for(r = start; r <= end && i < 24; r++,i++,NumLines++)
		ReadLine(r,i);
	 File->CLOSE();
}

void REPORT::Init(void)
{
	if(File->GetFileOpenState() != FILE_OPENED) 	// if the file is opened
		File->OPEN();

	NumRecords= File->GetNumRecords();
    end = NumRecords;
	start = end > NUMLINES ? end - NUMLINES : 1;

	NumCells = File->GetNumFields();
	ReadHeader(0);

	ReadLines();
}

void REPORT::ShowData(HDC hdc,RECT update)
{
	 TEXTMETRIC tm;
	 GetTextMetrics(hdc,&tm);
	 cyChar = tm.tmHeight + tm.tmExternalLeading;
	 cxChar = tm.tmAveCharWidth;

	 int x = 4;
	 int y = 4;

	 int i,k;

	 for(i = 0; i < NumLines; i++ ,x = 4,y+=cyChar)
      if(y >= update.top && y <= update.bottom)
	   for( k = 0; k < NumCells; k++)
	    {
			TextOut(hdc,x,y,Cells(i,k).contents,lstrlen(Cells(i,k).contents) );
			x+= Cells(i,k).len * cxChar + cxChar;
	  	}
}

