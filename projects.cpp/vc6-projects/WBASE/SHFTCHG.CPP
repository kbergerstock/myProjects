#include "shftchg.h"
#include <string.h>
#include <stdlib.h>

SHIFTCHANGE::SHIFTCHANGE()
{
	gettime(&ct);
}

SHIFTCHANGE::~SHIFTCHANGE()
{
}

void SHIFTCHANGE::Run(void)
{
	gettime(&ct);
    int now = ct.ti_hour * 60 + ct.ti_min;
    for(int i = 0; i < 3; i++)
    	if( now == zones[i] )
        	ShiftChange = TRUE;
}

int SHIFTCHANGE::parse(LPSTR entry,LPSTR szINI)
{
	char buf[40];
    GetPrivateProfileString("SHIFTS",entry,LPSTR("0,0"),LPSTR(buf),39,szINI);
	char *p = strtok(buf,":");
    int h = atoi(p);
    p = strtok(NULL,":");
    int m = atoi(p);
    return h*60 + m;
}

void SHIFTCHANGE::Init(LPSTR szINI)
{
	zones[0] = parse("SHIFT1",szINI);
    zones[1] = parse("SHIFT2",szINI);
    zones[2] = parse("SHIFT3",szINI);
}

int SHIFTCHANGE::isShiftChange(void)
{
	int r = ShiftChange;
    ShiftChange = FALSE;
    return r;
}