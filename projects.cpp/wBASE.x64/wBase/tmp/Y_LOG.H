#ifndef __ODB3_H
#include "odb3.h"
#endif

#ifndef __LOG_H
#include "log.h"
#endif

#ifndef __Y_LOG_H
#define  __Y_LOG_H

struct YIELD_DATA
{
	char szDATE[15];
    char szTIME[15];
    double total;
    double good;
    double yield;
};

struct YIELD_LOG : public LOG
{
	private:
    public:
    	YIELD_LOG();
        ~YIELD_LOG();
        void Init(LPSTR);
        void Append(YIELD_DATA&);
        YIELD_DATA Read(unsigned long);
};
#endif
