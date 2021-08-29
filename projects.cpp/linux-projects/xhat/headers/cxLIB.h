// class to handle interface to x11 sub system
// keith R. Bergerstock
// 
#include <X11/Xlib.h>

#ifndef __cxLIB_h
#define __cxLIB_h

class cxLIB
{
	private:
		 Display* display;		// pointer to X Display structure.
		 
		 int root_screen_num;		
		 int root_screen_width;
		 int root_screen_height;
		 Window root_window;
		 unsigned long root_white_pixel;
		 unsigned long root_black_pixel;
		 
		 void init();
		 
	public:
		cxLIB();				// constructor to open xlib interface
		cxLIB(const char*);     // contror to open specified x display on host 
		~cxLIB();				// destructor will close it		
		
		Display* operator*() { return display; }

        int screen_num()    { return root_screen_num; }
        int width()         { return root_screen_width; }
        int height()        { return root_screen_height; }
        unsigned long wp()  { return root_white_pixel; }
        unsigned long bp()  { return root_black_pixel; }  
        Window   handle()   { return root_window; }

        void sync();    
        void flush();  

};
#endif

