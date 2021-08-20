// xcanvas.h
// k.r.bergerstock

#include "cxWIN.h"

#ifndef	__xCANVAS_H
#define __xCANVAS_H

class xCANVAS
{
	private:
        cxLIB& display;         // reference to the x display object
        Window id;              // the id of the window we want to draw on    
        GC     gc;              // the graphics context

	public:
		xCANVAS(cxLIB&,cxWIN&);
        ~xCANVAS();
        void setForeGround(unsigned long);
        void drawLine(int,int,int,int);
		void setPixel(int,int);
        
        int width();
        int height();
};

#endif

