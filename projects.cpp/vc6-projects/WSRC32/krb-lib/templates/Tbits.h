// template class tBits
// K. R. Bergerstock
// @ 09/24/97

#ifndef __TBITS_H
#define  __TBITS_H

#ifdef _MSC_VER
	#include <cstdlib>
    #include <cctype>
#endif

#ifdef __BORLANDC__
	#include <_null.h>
	#include <mem.h>
    #include <ctype.h>
#endif


#ifndef STRICT
#define STRICT
#endif
#include <windows.h>

#ifdef __WIN31__
    #ifndef LPSTR
        typedef char far* LPSTR;
    #endif

    #ifndef DWORD
        typedef unsigned long DWORD;
    #endif

    #ifndef WORD
        typedef unsigned short WORD;
    #endif

    #ifndef BYTE
        typedef unsigned char BYTE;
    #endif

    #ifndef BOOL
        typedef short BOOL;
        #define TRUE 1
        #define FALSE 0
    #endif

#endif

#define DLLexport __declspec(dllexport)

// template class for bit arrays
// the bits are stored in the array where the MSB is at position 0
// and the LSB is at position (nEnd-1)

template <class TYPE> class TBITS
{
  private:
   int	nSize;						// size of the array
   int	nEnd;						// current end of valid bits in array
   TYPE FAR *pBitArray;				// pointer to the bit array;
   LPSTR pszHex;					// pointer to a null terminated string

   TYPE ASC2HEX(char cIn)			// returns the hex code for a valid
	{								// ascii hex digit 0 - F
		TYPE R = cIn & TYPE(0x0f);	// strip off the high nibble
		if(cIn > 0x40)				// if the input char is greater than '@'
			R += 0x09;				// then and 9 to it and
		return R;					// return the results
	}

    // empty and private so that they can not be used
    TBITS(const TBITS& t) {}
    const TBITS& operator=(const TBITS& t) { return *this;}

  public:
	TBITS();
   ~TBITS();

   void Clear(void) {nEnd = 0;} 	// reset the bit array to zero
   void SetSize(int nCount);		// sets the size of the array

   TYPE ShiftRight(void);			// shifts the bit array right one
   TYPE ShiftRight(int nCount); 	// shifts the bit array right nCount times
   void RotateRight(int nCount);	// rotates the bit array right nCount times

   TYPE ShiftLeft(void);			// shifts the bit array left one
   TYPE ShiftLeft(int nCount);		// shifts the bit array left nCount times
   void RotateLeft(int nCount); 	// rotates the bit arraay left nCount times

   void AddBits(TYPE bVal); 		// adds four bits to the array

   void AppendBit(TYPE bVal)		// add an indivual bit to the bit array
	{	SetBit(nEnd++,bVal); }

   void SetBit(int ndx, TYPE bVal)	// set an indivual bit in the bit array
	{
		if(ndx >= nSize)
			SetSize(nSize+1);
		pBitArray[ndx] = bVal;
	}

   TYPE GetBit(int ndx) 			// retrieve an indivual bit from the bit array
	{	return pBitArray[ndx]; }

   int	GetSize(void) { return nEnd; }	// retrieve the size of the bit array

   void SetHex(LPSTR szHex);		// convert an ascii HEX string to a bit array
   void SetHex(DWORD dHex); 		// convert a double word to a bit array
   void SetHex(WORD  wHex); 		// convert a word to a bit array
   void SetHex(BYTE  bHex); 		// convert a byte to a bit array

   LPSTR GetHex(void);				// comvert a bit array to an ascii HEX string
   DWORD GetDword(void);			// convert a bit array to a double word
   WORD  GetWord(void);
   BYTE  GetByte(void);
};

template <class TYPE> TBITS<TYPE>::TBITS()
{
	pszHex = NULL;
	pBitArray = new FAR TYPE[16]; 			// default size = 16 bits
	nSize = 16; 							// current size of array
	nEnd = 0;								// current bit location in array
}

template <class TYPE> TBITS<TYPE>::~TBITS()
{
	if(pBitArray != NULL)
		delete[] pBitArray;

	if(pszHex != NULL)
		delete[] pszHex;
}

template <class TYPE> void TBITS<TYPE>::SetSize(int nCount)
{
	int nNewSize = nSize;									// the new size of the array
	if(nCount > nSize)										// if the requeseted size is greater than the current size
		{
			while(nNewSize < nCount) nNewSize += 8; 		// then increment allocation size in chunks of 8
			TYPE FAR *pTmp = new FAR TYPE[nNewSize]; 		// form a pointer to a new chunk of memory
			if(nEnd)										// copy the old contents to the new array
			   for(int i = 0; i < nEnd; i++)
				pTmp[i] = pBitArray[i];
			delete[] pBitArray;								// delete the old array
			pBitArray = pTmp;								// assign the new memory to the array pointer
		}
	nSize = nNewSize;										// reset the size parameter to the new size
}

template <class TYPE> TYPE TBITS<TYPE>::ShiftLeft(void)
{
	TYPE r = FALSE; 										// default return value
	if(nEnd > 0)											// if the size of the array is greater than zero
	  {
		r = pBitArray[0];									// the return value is the first element of the bit array
		memmove(pBitArray,pBitArray+1,(sizeof(TYPE)*(nEnd-1)) );	// then move each element of the array down one indice
		pBitArray[nEnd-1] = FALSE;							// place a zero in the last element of the array
	  }
	return r;												// return the value of the first element
}

template <class TYPE> TYPE TBITS<TYPE>::ShiftLeft(int nCount)
{
	TYPE r = FALSE; 										// default return value
	if(nCount < nEnd && nCount > 0)
		while(nCount--)
			r = ShiftLeft();
	return r;
}

template <class TYPE> void TBITS<TYPE>::RotateLeft(int nCount)
{
	if(nCount < nEnd && nCount > 0)
		while(nCount--) 									// while nCount is grater than zero
				pBitArray[nEnd-1] = ShiftLeft();			// the last element of the array equals the result of a shift left
}


template <class TYPE> TYPE TBITS<TYPE>::ShiftRight(void)
{
	TYPE r = FALSE; 										// default return value
	if(nEnd > 0)											// if the size of the array is greater than zero
		{													// then
			r = pBitArray[nEnd-1];							// the return value is the last element of the array
			memmove(pBitArray+1,pBitArray,(sizeof(TYPE)*(nEnd-1)) ); // then move each element up one indice
			pBitArray[0] = FALSE;							// place a zero in the bottom element
		}
	return r;
}

template <class TYPE> TYPE TBITS<TYPE>::ShiftRight(int nCount)
{
	TYPE r = FALSE; 										// default return value
	if(nCount < nEnd && nCount > 0)
		while(nCount--)
			r = ShiftRight();
	return r;
}

template <class TYPE> void TBITS<TYPE>::RotateRight(int nCount)
{
	if(nCount < nEnd && nCount > 0)
		while(nCount--) 									// while nCount is grater than zero
				pBitArray[0] = ShiftRight();				// the first element of the array equals the result of a shift left

}

template <class TYPE> void TBITS<TYPE>::AddBits(TYPE bVal)
{
	for(int i = 0; i < 4; bVal <<= 1, i++)
		AppendBit((bVal & 0x08)>>3);
}

template <class TYPE> void TBITS<TYPE>::SetHex(LPSTR szHex)
{
	char c;
	while( c = *szHex++ )
		if( isxdigit (c) )
			AddBits(ASC2HEX(c) );
}

// if adding more than one DWORD, WORD or BYTE to a bit array make sure
// that you add the Least Significant portion first then the Most Significant
// portion because the Most Significant bit is stored in loaction 0

template <class TYPE> void TBITS<TYPE>::SetHex(DWORD dHex)
{
  int nBits = 8 * sizeof(DWORD);
  nEnd += nBits;
  SetSize(nEnd);
  for(int i = 0; i < nBits; i++)
	{
		ShiftRight();
		SetBit(0,TYPE(dHex & 0x0001));
		dHex >>=1;
	}
}

template <class TYPE> void TBITS<TYPE>::SetHex(WORD wHex)
{
  int nBits = 8 * sizeof(WORD);
  nEnd += nBits;
  SetSize(nEnd);
  for(int i = 0; i < nBits; i++)
	{
		ShiftRight();
		SetBit(0,TYPE(wHex & 0x0001));
		wHex >>=1;
	}
}

template <class TYPE> void TBITS<TYPE>::SetHex(BYTE bHex)
{
  int nBits = 8 * sizeof(BYTE);
  nEnd += nBits;
  SetSize(nEnd);
  for(int i = 0; i < nBits; i++)
	{
		ShiftRight();
		SetBit(0,TYPE(bHex & 0x0001));
		bHex >>=1;
	}
}

template <class TYPE> DWORD TBITS<TYPE>::GetDword(void)
{
	DWORD r = 0L;
	int nBits = 8 * sizeof(DWORD);
	for(int i = 0; i < nBits && i < nEnd; i++)
	  {
		r <<= 1;
		r |= GetBit(i);
	  }
	return r;
}

template <class TYPE> WORD TBITS<TYPE>::GetWord(void)
{
	WORD r = 0;
	int nBits = 8 * sizeof(WORD);
	for(int i = 0; i < nBits && i < nEnd; i++)
	  {
		r <<= 1;
		r |= (WORD)GetBit(i);
	  }
	return r;
}

template <class TYPE> BYTE TBITS<TYPE>::GetByte(void)
{
	BYTE r = 0;
	int nBits = 8 * sizeof(BYTE);
	for(int i = 0; i < nBits && i < nEnd; i++)
	  {
		r <<= 1;
		r |= (BYTE)GetBit(i);
	  }
	return r;
}


template <class TYPE> LPSTR TBITS<TYPE>::GetHex(void)
{
	int i,j,k,r;							// loop counters and array indices
	int size = 1 + nSize / 4;				// calc size of string required
	if(pszHex != NULL)						// if allocated delete old string
		delete[] pszHex;
	pszHex = new char[size];				// allocate memory for string

	i = k = 0;								// set indices to zero

	while( i < nEnd )						// while bitArray index is less than
	 {										// the end of the bit array
		r = 0;								// temp result = 0
		for(j = 0; j < 4; j++)				// for a nibble (4 bits )
		  {
			r <<= 1;						// shift result left one
			r |= pBitArray[i++];			// or bit into result
		  }
		if(r > 9)							// convert to ascii hex digit
		  r = (r - 9 ) | 0x40;
		else
		  r = r | 0x30;

		pszHex[k++] = char(r);				// place ascii digit in string
		pszHex[k] = 0;						// null terminate string
	 }

	return pszHex;
}

#endif
