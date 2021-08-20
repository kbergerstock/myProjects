//*******************************************************************
//              
//  FILE:       SURFACEA.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  SurfaceA
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

double const RHO    =   18.0;
double const THETA  =    0.45;
double const PHI    =    1.02;
double const DIS    = 300.0;

SurfaceA::SurfaceA(int cW, int cH)
{
   cWidth = cW;
   cHgt = cH;
   ThreeD::Init(RHO,THETA,PHI,DIS,cWidth,cHgt);
};


double SurfaceA::fnz_a( double x, double y)
{
   return cos(0.120 * (x*x + y*y) );
}

void SurfaceA::Draw(HDC hdc, COLORREF rgb)
{
  double x,y;
  const double E = 15.0;

  for( x = E; x >= -E; x -= 0.15)
	for(fl = 0, y = -E; y <= E; y += 0.15)
		hwire(hdc,x,y,fnz_a(x,y) ,rgb );

}


