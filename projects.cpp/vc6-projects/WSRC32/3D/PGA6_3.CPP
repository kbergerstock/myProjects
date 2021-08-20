#include "pga6_3.h"
#include <math.h>

double const RHO    =  65.0;
double const THETA  =  0.4;
double const PHI    =  1.250;
double const DIS    = 750.0;

#define XS 8
#define YS -8
#define X2 -9
#define Y2 8
#define SP (Y2 - YS) / (X2 - XS)

double PGA6_3::sqr (double v, double c)
  {
    return (v + c) * (v + c);
  }

double PGA6_3::fnz( double x, double y)
  {
	double z = 4 * exp(-0.1 * sqr(y,10) - .02 * sqr(x,10) );
         z += 4 * exp( -0.1 * sqr(x,10) - 0.3 * sqr(y,-6) );
         z += 3 * exp( -0.1 * sqr(y,8) - .02 * sqr(x,-10) );
         z += -9 * exp(-.09 * sqr(x,-5) - .09 * sqr(y,-7) );
    return z;
  }


void PGA6_3::plane_proj (HDC hdc,double x, double y, COLORREF rgb)
  {
    int i;

    CalcScreenCoordinates( x,y,5.0);
    if(sx < 0 || sx > cWidth) return;
    if(sy < 0) sy = 0;
    Line(hdc,sx,sy,sx,(yn[sx]-2),rgb);
    lx = sx;
    for(i = px; i <= sx; i++) yn[i] = sy;

    CalcScreenCoordinates( x,y,-7.0);
    if(sy > cHeigth) sy = cHeigth;
	if(sy > yx[lx]+2) Line(hdc,lx,sy,lx,(yx[lx]+2),rgb);
    px = lx;
  }

void PGA6_3::Draw(HDC hdc)
{
  double x,y;
  COLORREF C1 = RGB(0,0,255);
  COLORREF C2 = RGB(0,255,0);

  /* closer part of surface */
  for( x = 14.0 ; x >= -18.0; x -= 1.0)
    for( fl = 0, y = (YS + (x - XS) * SP); y <= 17.0; y+= 0.4 )
      hwire(hdc,x,y,fnz(x,y),C1);

  /* curve of intersection */
  for( fl = 0, x = 14.0; x >= -18.0; x -= 0.4)
     {
     y = YS + (x - XS) * SP ;
     hwire(hdc,x,y,fnz(x,y),C1);
     }

  /* plane */
    for( x = 13.6 ; x >= -18; x -= 0.12)
     {
     y = YS + (x - XS) * SP ;
     plane_proj(hdc,x,y,C2);
     }

  /* further part of surface */
    for(x = -5; x >= -18; x -= 1.0)
      for( fl = 0, y = -13; y <= 0; y+= 0.4)
       hwire(hdc,x,y,fnz(x,y),C1);

 }

PGA6_3::PGA6_3(int cW, int cH)
{
   cWidth = cW;
   cHgt = cH;
   px = 0;
   ThreeD::Init(RHO,THETA,PHI,DIS,cWidth,cHgt);
};
