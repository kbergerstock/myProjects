//*******************************************************************
//              
//  FILE:       THREE_D1.CPP
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  ThreeD
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - ThreeD class functions
//              
//              
//*******************************************************************

// Includes

#include "three_d1.h"

#ifndef __MATH_H
 #include <math.h>
#endif

#ifndef __WINDOWS_H
 #include <windows.h>
#endif

ThreeD::ThreeD()
{
  h_yx = GlobalAlloc(GPTR,1200*sizeof(int) );
  h_yn = GlobalAlloc(GPTR,1200*sizeof(int) );

  fl = 0;
}

ThreeD::~ThreeD()
{
  GlobalFree(h_yx);
  GlobalFree(h_yn);
}

// initialize 3d coordinate system

void ThreeD::Init(double RHO, double THETA, double PHI, double DIS, int cW, int cH )
{
  rho = RHO;
  s1 = sin(THETA);
  c1 = cos(THETA);
  s2 = sin(PHI);
  c2 = cos(PHI);
  dis=  DIS;

  Init(cW,cH);
}

void ThreeD::Init( int cW, int cH )
{
  cWidth = cW;
  cHeigth = cH;

  cx =  cW / 2;
  cy =  cH /2;
  
  sx = sy = 0;

  yn = LPINT(GlobalLock(h_yn) );
  yx = LPINT(GlobalLock(h_yx) );
  
  for( int i = 0; i < 1200; yn[i] = cH, yx[i] = 0, i++) ;

  GlobalUnlock(h_yn);
  GlobalUnlock(h_yx);
  
}


// caculate screen coordinates from x,y,z spatial coordinates
// returns a value indicating if screen coordinate is on screen
// or off screen [null] 

int ThreeD::CalcScreenCoordinates( double x, double y, double z)
{
    double xe = -x * s1 + y * c1;
    double ye = -x * c1 * c2 - y * s1 * c2 + z * s2;
    double ze = -x * s2 * c1 - y * s1 * s2 - z * c2 + rho;

    sx = cx + (int) (dis * xe/ze);
    sy = cy - (int) (dis * ye/ze);


    return !( sx < 0 || sx > cWidth || sy < 0 || sy > cHeigth );

}

void ThreeD::plot_3d(HDC hdc, double x, double y, double z, COLORREF rgb)
{
    CalcScreenCoordinates(x,y,z);  // calc screen coordinates
    SetPixel(hdc,sx,sy,rgb);       // plot the pixel in spcified color

    lx = sx;                       // save the plotted coordinates
    ly = sy;

}  

void ThreeD::hwire( HDC hdc, double x, double y, double z, COLORREF rgb)
{
  int sf = CalcScreenCoordinates(x,y,z);    // calc screen coordinates

  if( fl && sf )
     { hLine(hdc, lx,ly,sx,sy,rgb); lx = sx; ly = sy ; }
  else if( sf  && !fl )
     { lx = sx; ly = sy ; fl = 1; }
  else
     fl = 0;
}



//  hline.c  [ hidden - line ]
//  draw a line in specified color
//  using Bresenham's integer based Alogorithm
//  routine form C: the complete reference.
//  also incorperates a hidden line check function for three dimensional
//  graphing

void ThreeD::hLine(HDC hdc, int startx, int starty, int endx, int endy, COLORREF rgb)
{
  int t, distance;
  int xerr = 0, yerr = 0;
  int delta_x, delta_y;
  int incx, incy;

  /* compute the distance in both directions */
  delta_x = endx - startx;
  delta_y = endy - starty;

  /*
    compute the direction of the increment
    an increment of 0 means either a vert. or horz. line.
  */

  incx = (delta_x > 0 ? 1 : (delta_x == 0 ? 0 : -1) );
  incy = (delta_y > 0 ? 1 : (delta_y == 0 ? 0 : -1) );

  /* make delta_x and delta_y positive */
  delta_x *=incx;
  delta_y *=incy;

  /* determine which distance is greater */
   distance = (delta_y > delta_x ? delta_y : delta_x);

  yn = LPINT(GlobalLock(h_yn) );		
  yx = LPINT(GlobalLock(h_yx) );		

  /* draw the line */
  for(t = 0; t <= distance+1; t++)
     {

        if( starty <= yn[startx] || starty >= yx[startx] )
          {
           SetPixel(hdc,startx, starty, rgb);
           if(starty < yn[startx] ) yn[startx] = starty;
           if(starty > yx[startx] ) yx[startx] = starty;
          }

     xerr += delta_x;
     yerr += delta_y;
     if(xerr > distance)
       {
         xerr -= distance ;
         startx += incx ;
       }
     if(yerr > distance)
       {
         yerr -= distance ;
         starty += incy ;
       }
	 } /* end of for loop */

  GlobalUnlock(h_yn);
  GlobalUnlock(h_yx);

} /* end of hLine */


//  line.c  [ line ]
//  draw a line in specified color
//  using Bresenham's integer based Alogorithm
//  routine form C: the complete reference.

void ThreeD::Line(HDC hdc, int startx, int starty, int endx, int endy, COLORREF rgb)
{
  int t, distance;
  int xerr = 0, yerr = 0;
  int delta_x, delta_y;
  int incx, incy;

  /* compute the distance in both directions */
  delta_x = endx - startx;
  delta_y = endy - starty;

  /*
    compute the direction of the increment
    an increment of 0 means either a vert. or horz. line.
  */

  incx = (delta_x > 0 ? 1 : (delta_x == 0 ? 0 : -1) );
  incy = (delta_y > 0 ? 1 : (delta_y == 0 ? 0 : -1) );

  /* make delta_x and delta_y positive */
  delta_x *=incx;
  delta_y *=incy;

  /* determine which distance is greater */
   distance = (delta_y > delta_x ? delta_y : delta_x);

  /* draw the line */
  for(t = 0; t <= distance+1; t++)
    {

     SetPixel(hdc,startx, starty, rgb);

     xerr += delta_x;
     yerr += delta_y;
     if(xerr > distance)
       {
         xerr -= distance ;
         startx += incx ;
       }
     if(yerr > distance)
       {
         yerr -= distance ;
         starty += incy ;
       }
     } /* end of for loop */

} /* end of Line */
