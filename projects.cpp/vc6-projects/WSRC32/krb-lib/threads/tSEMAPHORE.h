//*******************************************************************
//              
//  FILE:       tSEMAPHORE.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    RX05_START_CELL
//              
//  COMPONENT:  - tSEMAPHORE
//              
//  DATE:       01.04.2004
//              
//  COMMENTS:   - class wrapper for a win 32 semaphore object
//              
//              
//*******************************************************************

// Includes
#ifndef __WINDOWS_H
#ifndef STRICT
	#define STRICT
#endif
#include <windows.h>
#endif

#ifndef __tSEMAPHORE_h
#define __tSEMAPHORE_h

class tSEMAPHORE
{
	private:
    	HANDLE oHandle;
        bool ref_flag;

    public:
        tSEMAPHORE()
         {
            // create a semaphore
            // initial state == non signaled - max 10 count
	        oHandle = CreateSemaphore( NULL,0,1000,NULL);
            ref_flag = oHandle ? true : false;
         }

        tSEMAPHORE(LPSTR sNAME)
         {
            // create a semaphore
            // initial state == non signaled - max 10 count
	        oHandle = CreateSemaphore( NULL,0,1000,sNAME);
            ref_flag = oHandle ? true : false;
         }

        tSEMAPHORE(const tSEMAPHORE& s)
         {
            oHandle = s.oHandle;
            ref_flag = false;
         }

        virtual ~tSEMAPHORE()
         {
            if(ref_flag)
                CloseHandle(oHandle);

            ref_flag = false;
         }

        void  inc()
         {
            LONG pc;
            ReleaseSemaphore(oHandle,1,&pc);
         }

        HANDLE GetHandle()  { return oHandle; }
}; 

#endif

