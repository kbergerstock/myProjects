//*******************************************************************
//              
//  FILE:       3DCURVES.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  AppWin
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - main start file for 3d curves program
//              
//              
//*******************************************************************

// Includes

#include "cAppBase32.h"

#include "surfaceB.h"

class 	AppWin : public cAppWinFrame
{
   private:
    int isOk;
    int wSurface;

	// message cracker handling routines
	void OnDestroy(HWND);
	void OnCreated(HWND);
	void OnCommand(HWND , int , HWND , UINT );
	void OnTimer(HWND , UINT );

   public:
	AppWin(HINSTANCE,int);

	~AppWin() {};

    void Paint(HDC);

    int  IsOk(void) { return isOk;}
};
