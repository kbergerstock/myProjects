//*******************************************************************
//              
//  FILE:       cCANVAS.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    dx_test
//              
//  COMPONENT:  -
//              
//  DATE:       07.07.2005
//              
//  COMMENTS:   -   virtual interface for a canvas class
//              
//              
//*******************************************************************

#pragma warning (disable:4786)

// Includes

#ifndef __cCANVAS_h
#define __cCANVAS_h

class cCANVAS
{
    private:
    protected:
        int _width;
        int _height;
                
    public:
        cCANVAS() : _height(0), _width(0) {}
        cCANVAS(int h, int w) : _height(h), _width(w) {}
        ~cCANVAS() {}

        virtual void setRGBpen(int,int,int) = 0;
        virtual void setPixel(int,int) = 0;
        virtual void setPixel(double,double) = 0;

        int height()    { return _height; }
        int width()     { return _width; }
        

        
}; 

#endif

