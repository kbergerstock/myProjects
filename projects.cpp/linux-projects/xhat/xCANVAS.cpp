    // xcanvas.c;;
// k.r.bergerstock

#include "xCANVAS.h"

xCANVAS::xCANVAS(cxLIB& d, cxWIN& w) : display(d)
{
    id = w.handle();

    /* these variables are used to specify various attributes for the GC. */
    /* initial values for the GC. */
    XGCValues values;
    values.cap_style = CapButt;
    values.join_style = JoinBevel;

    /* which values in 'values' to check when creating the GC. */
    unsigned long valuemask = GCCapStyle | GCJoinStyle;

    // reate a new graphical context.
    gc = XCreateGC(*display, id, valuemask, &values);
    if (gc < 0)
     {
        throw("XCreateGC:");
     }

}

xCANVAS::~xCANVAS()
{
}

void xCANVAS::setForeGround(unsigned long color)
{
    /* change the foreground color of this GC to white. */
    XSetForeground(*display, gc, color);
}
void xCANVAS::drawLine(int x0,int y0,int x1,int y1)
{
    /* draw a line between point '20,20' and point '40,100' of the window. */
    XDrawLine(*display, id, gc, x0,y0,x1,y1);
}

void xCANVAS::setPixel(int x ,int y)
{
    /* draw a pixel at position '5,60' (line 5, column 60) of the given window. */
    XDrawPoint(*display, id, gc, x, y);
}


int xCANVAS::width()
{
    // fix
    return 800;
}

int xCANVAS::height()
{
    // fix
    return 600;
}