/*
  hat.c - three dimensional hat function
  turboc compatible program
  K.R.BERGERSTOCK
*/

#include "winhat.h"
#include <stdio.h>
#include <math.h>

#define XP 320   				// (250) increases the width
#define YP 110       			// (56)  increase the height
#define ZP 90					// (64)  increases the display angle
#define XR (1.5 * M_PI)
#define YR 1.0
#define XF (XR/XP)
#define YF (YP/YR)
#define ZF (XR/ZP)
#define XX xi
#define ZZ zi

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

    int zi, xi, xl, yy;
    double zt, xt, xf, yf, zf;
    double xp2 = (double)XP * (double)XP;
    double dxi;
    int sx,sy;
    int cx = CalcCx(cxClient);
    int cy = CalcCy(cyClient);

    xf = (double)XF;             /* do these calculations once */
    yf = (double)YF;
    zf = (double)XP/ZP;

    StartTime = GetTickCount();
    hdc = BeginPaint(hwnd,&ps);

    for(zi = -cx ; zi < cx ; zi++)
     if ( abs(zi) <= ZP )
      {
        zt = zf * (double)(zi);
        xl = (int)(0.5 + sqrt(xp2 - (zt * zt)) );

        for(xi = -xl; xi <= xl; xi+=2)
             {
               dxi = (double)(xi);
               xt = sqrt( dxi * dxi +  zt * zt) * xf;
               yy = (int) ( sin( sin(xt) + 0.4 * sin(3*xt) ) * yf);
               sx = (XX+ZZ+cx); sy = (-yy+ZZ+cy);
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
