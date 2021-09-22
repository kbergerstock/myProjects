
#ifndef  __PIO_H
#include "PIO.h"
#endif


DIO::DIO()
{ BaseAddress = WORD(0); }

DIO::DIO(WORD base_address)
{  BaseAddress = base_address; }

void DIO::Open(WORD base_address)
{  BaseAddress = base_address; }

void DIO::Close(void)
{ BaseAddress = WORD(0); }

void DIO::WritePort(WORD port, BYTE mask)
{
 if(BaseAddress)
  {
   port += BaseAddress; 		// set up full port address
   asm MOV DX,port; 			// set up port address
   asm MOV AL,mask; 			// place mask into al
   asm OUT DX,AL;				// write mask out to port
  }
}

void DIO::SetBit  (WORD port, BYTE mask)	  // set a bit on <1>
{
 if(BaseAddress)
  {
   port += BaseAddress; 		// set up full port address
   asm mov dx,port; 			// set input address to port
   asm in  al,dx;				// read the port
   asm or  al,mask; 			// or the port content with mask
   asm jmp __SET__; 			// to set the bit
__SET__:
   asm out dx,al;				// write out to port with new value
  }
}


void DIO::ClearBit(WORD port, BYTE mask)	  // set a bit off <0>
{
 if(BaseAddress)
  {
   port += BaseAddress; 		// set up full port address
   asm mov dx,port; 			// set input address to the port
   asm mov bl,mask; 			// flip all the bits in the mask
   asm xor bl,0xFF;
   asm in  al,dx;				// read the port
   asm and al,bl;				// and with the mask to turn off the bit
   asm jmp __CLEAR__;
__CLEAR__:
   asm out dx,al;				// write out new value to th eport
  }
}

BYTE DIO::ReadBit (WORD port, BYTE mask)	  // read the state of a bit
{
   port += BaseAddress; 		// set up full port address
   asm	mov DX,port;			// point dx to the port
   asm	XOR AX,AX;				// CLEAR REGISTER
   asm	IN	AL,DX;				// read the port
   asm	AND AL,mask;			// and input and mask to clear
   return _AL;					// unwanted bits and return status
}								// return states 0 = bit off , nonzero = bit on

void DIO::FlipBit(WORD port, BYTE mask) 	 // flip the state of a bit
{
 if(BaseAddress)
  {
   port += BaseAddress; 		// set up full port address
   asm mov dx,port; 			// set input address to the port
   asm mov bl,mask; 			// flip all the bits in the mask
   asm in  al,dx;				// read the port
   asm xor al,bl;				// and with the mask to turn off the bit
   asm jmp __FLIP__;
__FLIP__:
   asm out dx,al;				// write out new value to th eport
  }
}

BYTE DIO::ReadPort(WORD port)
{
  port += BaseAddress;
  asm mov dx,port;
  asm in al,dx;
  return _AL;
}

