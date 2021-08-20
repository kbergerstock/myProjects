/*
  hat.c - three dimensional hat function
  turboc compatible program
  K.R.BERGERSTOCK
*/

#include "winhat.h"
#include <stdio.h>
#include <math.h>

//#define XP 320                  // (250) increases the width
// #define YP 110                 // (56)  increase the height

const double  ZP =  90.0;        // (64)  increases the display angle
const double  XR = (1.5 * M_PI);
const double  YR  = 1.0;

int CalcCy(int height)
 { return ( ( (height/2) * 9) / 10); }

int CalcCx(int width)
   { return width/2; }

void AppWin::DrawHat(HWND hwnd)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    DWORD StartTime,EndTime;					// holds time data
    char szbuf[255];						// buffer to format output in
    int  lenszbuf;
    double ElapsedTime;

    double XP = 0.5 * float(cxClient);
    double YP = 0.18 * float(cyClient);

    double XF =  (XR / XP);
    double YF =  (YP / YR);
    double ZF =  (XR / ZP);

    int zi, xi, xl, yy;
    double zt, xt, xf, yf, zf;
    double xp2 = XP * XP;
    double dxi;
    int sx,sy;
    int cx = CalcCx(cxClient);
    int cy = CalcCy(cyClient);

    xf = XF;                        /* do these calculations once */
    yf = YF;
    zf = XP / ZP;

    StartTime = GetTickCount();
    hdc = BeginPaint(hwnd,&ps);

    for(zi = -cx ; zi < cx ; zi++)
     if ( abs(zi) <= int(ZP) )
      {
        zt = zf * (double)(zi);
        xl = (int)(0.5 + sqrt(xp2 - (zt * zt)) );

        for(xi = -xl; xi <= xl; xi+=2)
             {
               dxi = (double)(xi);
               xt = sqrt( dxi * dxi +  zt * zt) * xf;
               yy = (int) ( sin( sin(xt) + 0.4 * sin(3*xt) ) * yf);
               sx = (xi+zi+cx); sy = (-yy+zi+cy);
               SetPixel (hdc, sx,sy, RGB(0,255,0)) ;
             }
	  }

   EndTime = GetTickCount();

   ElapsedTime = ((double)(EndTime - StartTime))/1000.0;

   GetClientRect(hwnd,&rect);

   lenszbuf = sprintf(szbuf,"Number Of Seconds to Paint the Hat %5.3f", ElapsedTime);

   DrawText(hdc,szbuf,lenszbuf,&rect,DT_LEFT|DT_BOTTOM|DT_SINGLELINE); 	// display the message

   EndPaint(hwnd,&ps);

 } /* end of function body */
