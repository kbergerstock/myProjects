/* Header file for use with WSTDIO.c */
#ifndef  subWindow_h
#include "subWindow.h"
#endif 

#ifndef __WSTDIO_H
#define __WSTDIO_H

class WSTDIO : public subWindow
{
  private:
    HMENU hMenu;                            // handle to the system menu
    RECT  wRect;                            // boundries of the window
    short iLinesOut;
    void  AdvanceLine(void);

  protected:
	#define _MaxLines   25
	#define _MaxLine    (_MaxLines - 1)
	#define LINE_LEN 128
	#define LINE_END LINE_LEN + 1
	
	char sScrBuff[_MaxLines][LINE_END];		// Array of characters on TTY
											// could make this heap object so can realloc
	short nFirstLine;						// Index of first line on TTY in the array
	short nLastLine;						// Index of last line on TTY in the array

	short nCurrPos; 						// Current TTY line output position
	long  nStdioCharWidth,
		  nStdioCharHeight; 				// width and height of Stdio font chars


	DWORD StdiobkRGB;						// background color
	DWORD StdiotextRGB; 					// text color

	#define Stdio_FONT SYSTEM_FIXED_FONT	// font used for display

	HFONT hOldFont;
	HINSTANCE hStdioInst;
	bool bStdioQuit;
	bool bInited;

	void SetupStdioDC(HWND , HDC );
	void ResetStdioDC(HDC );
	char *GetStdioLine(int );
	void StdioUpdate(HWND , HDC , int );
	void putStdio(HWND , HDC , WPARAM, LPARAM);
	void StdioPaint(HWND );
	void InitStdio(HWND );
	void Init(void);

  public:
    WSTDIO(HINSTANCE, HWND);
	~WSTDIO();
	LRESULT WndProc( HWND, UINT, WPARAM , LPARAM );
	bool Register();
	HWND Create (HWND, int );
	// message cracker routines
	void OnPaint(HWND );
	void OnCommand(HWND , int , HWND , UINT );
    void OnSysCommand(HWND, UINT, int, int);
	void OnColorChange(HWND);
	void OnGetMinMax(HWND , MINMAXINFO far*);
	void OnChar(HWND ,UINT , int );
	void OnDestroy(HWND);
	void OnKey(HWND , UINT , bool , int , UINT );

	HWND wopen(HWND,bool);
	HWND CreateStdioWindow(LPSTR,DWORD,int,int,int,int,HWND,HINSTANCE,bool);
	bool wputs(LPSTR);
	bool wputc(char);
};

#endif
