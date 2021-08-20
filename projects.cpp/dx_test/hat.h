//*******************************************************************
//              
//  FILE:       hat.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    dx_test
//              
//  COMPONENT:  cHAT
//              
//  DATE:       07.07.2005
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes
#include "cCANVAS.h"

#ifndef _HAT_H
#define _HAT_H

class cHAT
{
	private:
			int CalcCy(int);
			int CalcCx(int);
	public:
		void Draw(cCANVAS&);
		cHAT (cCANVAS& canvas){ Draw(canvas); }
};

#endif