// class to handle interface to x11 sub system
// keith R. Bergerstock
// 

#include "cxLIB.h"
#include <stdlib.h>		/* getenv(), etc. */

// constructor will open xlib interface
cxLIB::cxLIB()
{
	char *display_name = getenv("DISPLAY");  /* address of the X display.      */
	// open the X display
	display = XOpenDisplay(display_name);
	if (display == NULL) 
	 { 
		throw("cannot connect to X server");
	 }
	// initilize the screen parameters
	init();
}

cxLIB::cxLIB(const char* host_name)
{
	// open he X display
	display = XOpenDisplay(host_name);
	if (display == NULL) 
	 { 
		throw("cannot connect to host X server");
	 }	
	// initilize the screen parameters
	init();
}


// destructor will close it
cxLIB::~cxLIB()
{
	// close the connection to the X server. 
	XCloseDisplay(display);
}

void cxLIB::init()
{
/* this variable will be used to store the "default" screen of the  */
/* X server. usually an X server has only one screen, so we're only */
/* interested in that screen.                                       */
// int screen_num;

/* these variables will store the size of the screen, in pixels.    */
// int screen_width;
// int screen_height;

/* this variable will be used to store the ID of the root window of our */
/* screen. Each screen always has a root window that covers the whole   */
/* screen, and always exists.                                           */
// Window root_window;

/* these variables will be used to store the IDs of the black and white */
/* colors of the given screen. More on this will be explained later.    */
// unsigned long white_pixel;
// unsigned long black_pixel;

    /* check the number of the default screen for our X server. */
    root_screen_num = DefaultScreen(display);
    
    /* find the width of the default screen of our X server, in pixels. */
    root_screen_width = DisplayWidth(display, root_screen_num);
    
    /* find the height of the default screen of our X server, in pixels. */
    root_screen_height = DisplayHeight(display, root_screen_num);
    
    /* find the ID of the root window of the screen. */
    root_window = RootWindow(display, root_screen_num);
    
    /* find the value of a white pixel on this screen. */
    root_white_pixel = WhitePixel(display, root_screen_num);
    
    /* find the value of a black pixel on this screen. */
    root_black_pixel = BlackPixel(display, root_screen_num);
}

void cxLIB::flush()
{
  /* flush all pending requests to the X server. */
  XFlush(display);
}

void cxLIB::sync()
{
  // flush all pending requests to the X server, and wait until 
  // they are processed by the X server.                        
  XSync(display, False);
}

