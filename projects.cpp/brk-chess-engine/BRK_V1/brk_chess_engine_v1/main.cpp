#include "cAPP.h"
#include <iostream>

// fix add commnad line parameters and handlers for them
int main(void)
{
    try
     {
        cAPP app;
     }
    catch(...)
     {
        cerr << " unhandled exception \n " << endl;
     }
    return 0;
}
