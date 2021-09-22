#ifndef __WINDOWS_H
#define   STRICT
#include <windows.h>
#include <windowsx.h>
#endif


#define MEDIT_ID 0x0101

#ifndef __mEDIT_H
#define __mEDIT_H

class mEDIT
{
	private:
		HWND hwndEdit;
		LONG _x;                  // window orgin
		LONG _y;
		LONG _w;                  // window width
		LONG _h;                  // window hieght

		LONG cyChar;
		LONG cxChar;
		LONG cxCaps;

		void GetSize(HWND);
		void getTextMetrics(HWND hwnd);

	public:
		HWND Create(HWND,HINSTANCE);
        HWND Destroy(void);
		void SetFocus(void);
		void Draw(HWND);
		BOOL FileRead(LPSTR );
		void FileWrite(LPSTR );
        void New(void);
};

#endif
