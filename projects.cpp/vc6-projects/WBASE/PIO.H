/*
	generic digital io class

	K. R. Bergerstock
	version 1.0
	@ 1/97
*/

#ifndef __WINDOWS_H
#define  STRICT
#include <windows.h>
#endif

#ifndef __PIO_H
#define  __PIO_H

class DIO
{
   protected:
	 WORD BaseAddress;						   // base address of the board

   public:
	 DIO(); 								  // default constructor
	 DIO(WORD); 							  // primary conctructor
	 ~DIO() {} ;

	 // lolevel routines
	 void WritePort(WORD port, BYTE mask);	   // initilize a port to a given state
	 BYTE ReadPort (WORD port); 			   // read the hadware port

	 void SetBit   (WORD port, BYTE mask);	   // set a bit on <1>
	 void ClearBit (WORD port, BYTE mask);	   // set a bit off <0>
	 BYTE ReadBit  (WORD port, BYTE mask);	   // read the state of a bit
	 void FlipBit  (WORD port, BYTE mask);	   // flip the state of a bit

	 int  GetAddress(void) { return BaseAddress; }

	 void Open(WORD);
	 void Close(void);

};

#endif

