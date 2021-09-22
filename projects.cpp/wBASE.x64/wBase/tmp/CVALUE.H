// slide custom control header file

#ifndef __CWFRAME_H
#include "cwFrame.h"
#endif

#ifndef __cVALUE_H
#define __cVALUE_H

#define MAX_VALUE_BUF 40

class cVALUE : public cWinFrame
{
	private:
		char buf[MAX_VALUE_BUF+1];
		int resolution;
	public:
    	cVALUE();
		cVALUE(HWND);
		~cVALUE() {};
		void Draw(double);
        void Draw(long);
        void Draw(LPSTR);
        void Reset(void);
		void Paint(HWND,HDC);
		void SetPos(int,int,int,int);
		void SetResolution(int);
};

struct cCELL
{
	cVALUE vCell;
    HWND   hCell;

    void SetStyle(DWORD s) { vCell.SetStyle(s); } 
	void Draw(double d) { vCell.Draw(d); }
	void Draw(long l )  { vCell.Draw(l); }
	void Draw(LPSTR s)  { vCell.Draw(s); }
	void Reset(void)	{ vCell.Reset(); }
    void SetSize(int x, int y, int w, int h) { vCell.SetSize(x,y,w,h); }
	void SetResolution(int r) { vCell.SetResolution(r); }
    bool Register(void) { return vCell.Register(); }
    bool IsRegistered(void) { return vCell.isRegistered(); }
	HWND Create(HWND hp, int id) { return hCell = vCell.Create(hp,id); }
};

#endif