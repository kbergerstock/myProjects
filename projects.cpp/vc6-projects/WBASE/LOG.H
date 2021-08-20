#ifndef __ODB3_H
#include "odb3.h"
#endif

#ifndef __LOG_H
#define __LOG_H


#define MAXFLDS 10
#define NUMLINES 20

struct CELL
{
	char contents[40];
	int len;
};

typedef CELL far* LPCELL;

class LOG
{
	protected:
		int numflds;
        long NumRecords;

		NEWFIELD *flds;

		DB3FILE *File;

	public:
		LOG();
		virtual ~LOG();

        void Open(LPSTR);  				// open a dbase file for read only
        void Open(LPSTR,int,NEWFIELD*,int);
        void Close(void);				// close the file

        long GetNumRecords(void) { return NumRecords; }
};

class REPORT : public LOG
{
	private:
		HGLOBAL hCells;
		LPCELL	mCells;

		long start;
		long end;
		long NumCells;
        int  NumLines;

        int cxChar;
        int cyChar;

        void ReadHeader(int );
		void ReadLine(long , int );
		void ReadLines(void);

	public:
		REPORT();
		virtual ~REPORT();

		void Init(void); 				// init the cells
		void ShowData(HDC,RECT); 		// draw the data base on the screen
        void Scroll(HWND,int); 			// scroll the database
        void Top(HWND);
        void Bottom(HWND);
        long GetNumRecords(void) { return NumRecords; }
};

#endif
