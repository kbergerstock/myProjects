//*******************************************************************
//              
//  FILE:       SURFACEB.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  SurfaceA / Surface B
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#include "three_d1.h"

#ifndef __SURFACE_H
#define __SURFACE_H

class SurfaceA : ThreeD
{
	private:
	  int cWidth;
	  int cHgt;
	  double fnz_a( double x, double y);

	public:
	 SurfaceA(int cW, int cH);

	 void Draw(HDC hdc, COLORREF rgb);
};

class SurfaceB : ThreeD
{
	private:
	  int cWidth;
	  int cHgt;
	  double fnz_b( double x, double y);

	public:
	 SurfaceB(int cW, int cH);

	 void Draw(HDC hdc, COLORREF rgb);
};

#endif
