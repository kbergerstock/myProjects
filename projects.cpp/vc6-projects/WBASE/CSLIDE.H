// slide custom control header file

#ifndef __CWFRAME_H
#include "cwFrame.h"
#endif

#ifndef __DIAMOND_H
#include "diamond.h"
#endif

#ifndef __cVALUE_H
#include "cVALUE.h"
#endif

#ifndef __cSLIDE_H
#define __cSLIDE_H

#define  WM_SLIDECONTROL	10005			// function control
#define  SLIDECONTROL		10010			// control id
#define  SBCCONTROL 		10015

#define  RED 1
#define  GREEN 2
#define  YELLOW 3

class cDIAMOND : public cWinFrame
{
	private:
		int position;
		DIAMOND GreenDiamond;
		DIAMOND RedDiamond;
		DIAMOND YellowDiamond;
		void OnCreated(HWND);
	public:
		cDIAMOND(HWND);
		~cDIAMOND() {};
		int Getposition(void) { return position; }
		void Draw(int,int);
		void Draw(double,int);
		void Paint(HWND,HDC);
		void SetPos(int,int,int,int);
};


class cSLIDE : public cWinFrame
{
	private:
		char title[40];
		double value;
		double Max;
		double Min;
		double Location;

		double gL, gH;					 // green line limits
		double yL, yH;					 // yellow line limits

		// sub control access points
		cDIAMOND* cDiamond;
		HWND hDiamond;

		cVALUE* cValue;
		HWND hValue;

		int BarWidth;
		int resolution;

	protected:
		void SetPos(HWND);

	public:
		cSLIDE(HWND);
		~cSLIDE();

		void SetResolution(int);
		void SetBarWidth(int b) { BarWidth = b; }
		void SetMax(double m) { Max = m; }
		void SetMin(double m) { Min = m; }
		void SetGreenHigh(double m) { gH = m; }
		void SetGreenLow(double m) { gL = m; }
		void SetYellowHigh(double m) { yH = m; }
		void SetYellowLow(double m) { yL = m; }
		bool IsOk(void);
		void Reset(void);

		bool Register(void);
		HWND Create(HWND, int);
		void SetPos(int,int,int,int);

		void Draw(int);
		void Draw(double);
		void SetTitle(char *t) {lstrcpy(LPSTR(title),LPSTR(t)); }

		void Paint(HWND,HDC);

};

#endif
