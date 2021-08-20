//*******************************************************************
//              
//  FILE:       SHELL32.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    shell32
//              
//  COMPONENT:  AppWin
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#include "cAPPBASE.h"

class 	AppWin : public cAppWinFrame
{
   private:
    int isOk;

   public:
	AppWin(HINSTANCE,int);

	~AppWin() {};

    void Paint(HDC);

    int  IsOk(void) { return isOk;}
};
