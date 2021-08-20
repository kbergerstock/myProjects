#include "xCANVAS.h"
//#include "my_types.h"

#ifndef _cHAT_H
#define _cHAT_H

class cHAT	
{
	private:
        /*
			DWORD StartTime;				// holds time data
			DWORD EndTime;
			DWORD ElapsedTime;
        */
			char  szBUF[255];				// buffer to format output in
			int   lenszbuf;

			int CalcCy(int);
			int CalcCx(int);
	public:
		void Draw(xCANVAS&);

		cHAT(){}

        cHAT(xCANVAS& gc)
        {
            Draw(gc);    
        }
     
		~cHAT(){}
			
};

#endif

