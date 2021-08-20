//*******************************************************************
//              
//  FILE:       SURFACEB.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  SurfaceB
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#include "surfaceb.h"
#include <math.h>

double const RHO    =  30.0;
double const THETA  =  0.4;
double const PHI    =  1.250;
double const DIS    = 420.0;

SurfaceB::SurfaceB(int cW, int cH)
{
   cWidth = cW;
   cHgt = cH;
   ThreeD::Init(RHO,THETA,PHI,DIS,cWidth,cHgt);
};


double SurfaceB::fnz_b( double x, double y)
{
   return 12.5 * exp(-.1 * (x*x + y*y) );
}

void SurfaceB::Draw(HDC hdc, COLORREF rgb)
{
  double x,y;

  for( x = 10.0; x >= -10.0; x -= 0.2)
	for(fl = 0, y = -10.0; y <= 10; y += 0.2)
		hwire(hdc,x,y,fnz_b(x,y) ,rgb );
}


