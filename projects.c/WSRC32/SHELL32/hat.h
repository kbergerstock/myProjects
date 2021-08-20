
#ifndef __WINDOWS_h
#define  STRICT
#include <windows.h>
#include <mmsystem.h>
#endif

#ifndef _HAT_H
#define _HAT_H

class cHAT
{
	private:
			DWORD	StartTime;				// holds time data
			DWORD	EndTime;
			DWORD	ElapsedTime;
	
			int CalcCy(int);
			int CalcCx(int);
	public:
		void Draw(HDC,SIZE);
		cHAT (HDC _hdc, SIZE _size) { Draw(_hdc,_size); }
};

#endif