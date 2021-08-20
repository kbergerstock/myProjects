// RANDOM NUMBER GENERATOR CLASS

#include <stdlib.h>

#ifndef __cRANDOM_H
#define __cRANDOM_H

class cRANDOM
{
	private:
    	int 	limit;
        int 	flag;
    public:
    	cRANDOM() { flag = 0; limit = 0; randomize(); }
        cRANDOM(int l) { flag = 1; limit = l; randomize(); }

        int NextThrow(void)	{ return flag ? random(limit) + 1 : rand(); }
        
        double NextVal(double l = 100.0) { return l * (double(rand()) / double(RAND_MAX)); }

};

#endif