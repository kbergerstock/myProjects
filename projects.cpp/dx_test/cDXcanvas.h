//*******************************************************************
//              
//  FILE:       cDXcanvas.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    dx_test
//              
//  COMPONENT:  -
//              
//  DATE:       19.07.2005
//              
//  COMMENTS:   - implements a canvas object tied ti the direct draw system
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes
#include "cCANVAS.h"
#include "cDX9obj.h"

#ifndef __cDX9canvas_h
#define __cDX9canvas_h

// A structure for the custom vertex type
struct CUSTOMVERTEX
{
    FLOAT x, y, z, rhw; // The transformed position for the vertex
    DWORD color;        // The vertex color
};

// Our custom FVF, which describes the custom vertex structure
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZRHW|D3DFVF_DIFFUSE)

class cDX9canvas : public cCANVAS
{
    private:
        cDX9device & dxDevice;

    public:
        cDX9canvas(cDX9device& _device) : dxDevice(_device), cCANVAS() {}
        ~cDX9canvas() {}

        cDX9canvas(cDX9device & _device, int h, int w) : dxDevice(_device), cCANVAS(h,w) {}

        void setRGBpen(int,int,int);
        void setPixel(int,int);
        void setPixel(double,double);

}; 

#endif

