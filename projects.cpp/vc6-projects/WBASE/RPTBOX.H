// reportbox.h

#ifndef __APPBASE_H
#include "appbase.h"
#endif

#ifndef __LOG_H
#include "log.h"
#endif

#ifndef __REPORTBOX_H
#define __REPORTBOX_H

class REPORTBOX : public AppWinFrame
{

	private:
	HINSTANCE hI;
	int isOk;
	BOOL bRptQuit;
	HWND hParent;
    UINT ExitKey;

	REPORT Report;
	int ReportId;

	void  Scroll(HWND,int );
	LONG  cyChar;
	float nVscrollPos;
	float nVscrollInc;

	void OnCreated(HWND);
	/// message cracker functions

	void OnKey(HWND , UINT , BOOL , int , UINT );
	void OnKeyDown(HWND , UINT , BOOL , int , UINT );
	void OnVScroll(HWND , HWND , UINT , int );
	void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void OnPaint(HWND);
	void OnDestroy(HWND);

    void SetReport(LPSTR);

	public:
		REPORTBOX(HINSTANCE hInst,int x = 6, int y = 22, int w = 550, int h = 396);
		~REPORTBOX();

		HWND Display(HWND , BOOL );
		LRESULT WndProc(HWND,UINT,WPARAM,LPARAM);
		void SetTitle(int id);
        void SetTitle(char *fName);
        void SetExitKey(UINT key) { ExitKey = key; }

};

#endif

