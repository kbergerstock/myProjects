// test file

#include "cxWIN.h"
#include "xCANVAS.h"
#include "hat.h"
#include <iostream>
using namespace std;

int  main(int argc, char* argv[])
{
	try
	{
		cxLIB xDisplay;
		cout << "xLib connected" << endl;
        cxWIN w(xDisplay);
        xCANVAS gc(xDisplay,w);
      // Wait for the MapNotify event

      for(;;) {
	    XEvent e;
	    XNextEvent(*xDisplay, &e);
	    if (e.type == MapNotify)
		  break;
      }

        // draw the hat
        cHAT xhat(gc);

        xDisplay.flush();
        sleep(10);
	}
	catch(char*em)
	{
		cout << argv[0] << " >> " << em << endl;
		exit(-1);
	}
	catch(...)
	{
			cout << "Undefined exception" << endl;
			exit(-2);
	}
	
	return 0;
}

