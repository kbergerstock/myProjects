//*******************************************************************
//              
//  FILE:       cSPRITE.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  -
//              
//  DATE:       03.08.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#ifndef __cBITMAP_H
#include "cBITMAP.h"
#endif

#ifndef __cSPRITE_H
#define __cSPRITE_H

class cSPRITE
{
	protected:
    	short _x;
        short _y;
    	cBITMAP sprite;
		cBITMAP mask;
	public:
    	cSPRITE(){_x = _y = 0;};
		cSPRITE(short x, short y) : _x(x),_y(y) {};
		cSPRITE(HINSTANCE hInstance,int rcBitmap, int rcMask);
        virtual ~cSPRITE();

        void Create(HINSTANCE hInstance,int rcBitmap, int rcMask);

        void Draw(HDC);
        void Move(short x, short y);
};

#endif