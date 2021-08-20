/*
  hat.cpp - three dimensional hat function
  windows borland C++ compatible program
  K.R.BERGERSTOCK
  main function is :
	void DrawHat(cCANVAS)
	where the parameters  is the defination of some sort of canvas to draw on

*/

#include "cCANVAS.h"
#include "HAT.H"

#ifndef __MATH_H
#include <math.h>
#endif

#ifndef M_PI
	#define M_PI        3.14159265358979323846
#endif


#define XP 300					// (250) increases the width
#define YP 110					// (56)  increase the height
#define ZP 90					// (64)  increases the display angle
#define XR (1.5 * M_PI)
#define YR 1.0
#define XF (XR/XP)
#define YF (YP/YR)
#define ZF (XR/ZP)
#define XX xi
#define ZZ zi


int cHAT::CalcCy(int height)
 { return ( ( (height/2) * 9) / 10); }

int cHAT::CalcCx(int width)
   { return width/2; }

void cHAT::Draw(cCANVAS& canvas)
{
	int zi, xi, xl, yy;
	double zt, xt, xf, yf, zf;
	double xp2 = (double)XP * (double)XP;
	double dxi;
	int sx,sy;

	int cx = CalcCx(canvas.height() );
	int cy = CalcCy(canvas.width() );

	xf = double(XR)/double(XP);			 	/* do these calculations once */
	yf = double(YP)/double(YR);
	zf = double(XP)/double(ZP);

    canvas.setRGBpen(0,255,0);

	for(zi = -cx ; zi < cx ; zi++)
//	 if ( abs(zi) <= ZP )
     if( zi > -ZP && zi < ZP)
	  {
		zt = zf * (double)(zi);
		xl = (int)(0.5 + sqrt(xp2 - (zt * zt)) );

		for(xi = -xl; xi <= xl; xi+=2)
			 {
			   dxi = (double)(xi);
			   xt = sqrt( dxi * dxi +  zt * zt) * xf;
			   yy = (int) ( sin( sin(xt) + 0.4 * sin(3.0 * xt) ) * yf);
			   sx = (XX+ZZ+cx); sy = (-yy+ZZ+cy);
			   canvas.setPixel(sx,sy);
			 }
	  }

 } /* end of function body */
