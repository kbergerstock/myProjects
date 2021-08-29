// base class to handle create a X window
// Keith R. Bergerstock
// 08/24/2004

#include "cxWIN.h"

cxWIN::cxWIN(cxLIB& d) : display(d)
{
    // calculate the window's width and height. 
    width = 800;
    height = 600;
    
    /* position of the window is top-left corner - 0,0. */
    win_x = 100;
    win_y = 50;
    
    /* the window's border shall be 2 pixels wide. */
    unsigned int border_width = 2;
    
    /* create the window, as specified earlier. */
    id = XCreateSimpleWindow(*display,
                              display.handle(),
                              win_x, win_y,
                              width, height,
                              border_width, 
                              display.bp(),
                              display.wp() );

    // now map the window to the device

    // make the window actually appear on the screen.
    XMapWindow(*display, id);

    selectInput(StructureNotifyMask);

    // flush all pending requests to the x-server
    display.flush();
}

cxWIN::~cxWIN()
{
}

void cxWIN::selectInput(unsigned long events)
{
// set up the default events we want to be notified off
 XSelectInput(*display, id, events);
}
