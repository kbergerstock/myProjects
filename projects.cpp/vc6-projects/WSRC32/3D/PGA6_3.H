//*******************************************************************
//              
//  FILE:       PGA6_3.H
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    3d
//              
//  COMPONENT:  PGA6_3
//              
//  DATE:       29.07.2004
//              
//  COMMENTS:   - complex surface
//              
//              
//*******************************************************************

// Includes

#include "three_d1.h"

#ifndef __PGA6_3_H
#define __PGA6_3_H

class PGA6_3 : ThreeD
{
    private:
      int cWidth;
      int cHgt;

      int px;

      double sqr (double v, double c);
      double fnz( double x, double y);
      void  plane_proj (HDC hdc,double x, double y, COLORREF rgb);

    public:
     PGA6_3(int cW, int cH);

     void Draw(HDC hdc);
};

#endif

