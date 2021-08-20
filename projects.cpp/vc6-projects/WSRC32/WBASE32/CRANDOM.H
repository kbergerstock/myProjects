// RANDOM NUMBER GENERATOR CLASS

#include <stdlib.h>
#include <time.h>

#ifndef __cRANDOM_H
#define __cRANDOM_H


    class cRANDOM
    {
	    private:

    	    int 	sides;

        public:

    	    cRANDOM() 
             {  
                sides = 100; 
                srand( (unsigned)time( NULL ) );
             }

            cRANDOM(int l) 
             {  
                sides = l; 
                srand( (unsigned)time( NULL ) );
             }

            int     roll()
             {
                return 1 + rand() % sides;
             }

    };

#endif