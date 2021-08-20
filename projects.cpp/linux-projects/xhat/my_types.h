#ifndef __MY_TYPES_H
#define __MY_TYPES_H

typedef char*   		LPSTR;
typedef const char*		LPCSTR;

typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned long       U32;

#ifndef BYTE
typedef unsigned char       BYTE;
#endif
#ifndef WORD
typedef unsigned short      WORD;
#endif
#ifndef DWORD
typedef unsigned long       DWORD;
#endif

union uREG16
{
    U16 d;
    U8  b[2];

    uREG16()  { d = 0; }
    uREG16(U16 _d) { d = _d;}
    uREG16(const uREG16& r) { d = r.d;}  

    const uREG16& operator =(const uREG16& r)
     {
        d = r.d;
        return *this;
     }
};

union uREG32
{
    U32     d;
    BYTE    b[4];

    uREG32() { d = 0; }
    uREG32(U32 _d) { d = _d; }
    uREG32(const uREG32& r) { d = r.d;}  

    const uREG32& operator =(const uREG32& r)
     {
        d = r.d;
        return *this;
     }
};

typedef struct 
{
    U32 lowPart;
    U32 highPart;
} U64_LARGE;

union uREG64
{
    U64_LARGE   w;        
    BYTE        b[8];

    uREG64()  { lowPart = highPart = 0;
    uREG64(U32 h, U32 l) 	{ w.highPart = h; w.lowPart = l; }
    uREG64(U64_LARGE v)  	{ w.highPart = v.highPart; w.lowPart = v.lowPart; }
    uREG64(const uREG64& r) 	{ w.highPart = r.w.highPart; l.lowPart = l.w.lowPart; }    

    const uREG64& operator =(const uREG64& r)
     {
        w.highPart = r.w.highPart;
		w.lowPart = r.w.lowPart;
        return *this;
     }

    const uREG64& operator=(const U64_LARGE& r)
     {
        w.lowPart  = r.lowPart;
        w.highPart = r.highPart;
        return *this;
     }

};

#endif
