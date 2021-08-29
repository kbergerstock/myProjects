// base class to handle create a X window
// Keith R. Bergerstock
// 08/24/2004

#include "cxLIB.h"

#ifndef __cxWIN_h
#define __cxWIN_h

class cxWIN
{
    private:
        cxLIB&  display;    
        // this variable will store the ID of the newly created window. 
        Window id;
        
        // these variables will store the window's width and height. 
        unsigned int width;
        unsigned int height;
        
        // these variables will store the window's location. 
        unsigned int win_x;
        unsigned int win_y;

    public:
        cxWIN(cxLIB&);
        ~cxWIN();

        void selectInput(unsigned long events);

        Window handle() { return id; }

};
#endif
