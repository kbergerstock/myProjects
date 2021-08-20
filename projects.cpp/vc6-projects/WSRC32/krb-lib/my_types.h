#ifndef __MY_TYPES_H
#define __MY_TYPES_H

typedef char*   pChar;
typedef char*   LPSTR;

typedef unsigned char       U8;
typedef unsigned short      U16;
typedef unsigned long       U32;
typedef unsigned __int64    U64;

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef unsigned long       DWORD;

union REG16
{
    U16 d;
    U8  b[2];

    REG16()  { d = 0; }
    REG16(U16 _d) { d = _d;}
    REG16(const REG16& r) { d = r.d;}  

    const REG16& operator =(const REG16& r)
     {
        d = r.d;
        return *this;
     }
};

union REG32
{
    U32     d;
    BYTE    b[4];

    REG32() { d = 0; }
    REG32(U32 _d) { d = _d; }
    REG32(const REG32& r) { d = r.d;}  

    const REG32& operator =(const REG32& r)
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

union REG64
{
    U64         d;
    U64_LARGE   w;        
    BYTE        b[8];

    REG64()  { d = 0; }
    REG64(U64 _d) { d = _d; }
    REG64(U32 h, U32 l) { w.highPart = h; w.lowPart = l; }
    REG64(U64_LARGE v)  { w.highPart = v.highPart; w.lowPart = v.lowPart; }
    REG64(const REG64& r) { d = r.d;}    

    const REG64& operator =(const REG64& r)
     {
        d = r.d;
        return *this;
     }

    const REG64& operator=(const U64_LARGE& r)
     {
        w.lowPart  = r.lowPart;
        w.highPart = r.highPart;
        return *this;
     }

};

#endif