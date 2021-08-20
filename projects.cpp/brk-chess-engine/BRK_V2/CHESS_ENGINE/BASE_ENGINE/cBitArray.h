//*******************************************************************
//              
//  FILE:       cBitArray.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    BASE_ENGINE
//              
//  COMPONENT:  cBitArray
//              
//  DATE:       25.11.2003
//              
//  COMMENTS:   - a binary represnetation of a chess board element
//              
//              
//*******************************************************************


// Includes


#include "board_constants.h"

#ifndef __cBitArray_h
#define __cBitArray_h

typedef unsigned __int64 U64;
typedef unsigned char    U8;

class cBitArray
{
    protected:

        union BITBOARD
        {
            U64  ua;
            U8   ba[8];
        };

        BITBOARD bb;

    public:
    // constructors
    cBitArray()                 { bb.ua = 0; }
    cBitArray(__int64 v)        { bb.ua = v; }
    cBitArray(cBitArray& v)     { bb.ua = v.bb.ua; }

    cBitArray(SQUARE_NAMES sq )
     {
        bb.ua = 0;
        setPiece(sq);
     }


    // logical operators

    cBitArray operator~ ()
     {
        cBitArray t(~bb.ua);
        return t; 
     }

    cBitArray operator &(cBitArray& a)
     {
        cBitArray t(*this);
        t.bb.ua &= a.bb.ua;
        return t;
     }

    cBitArray operator | (cBitArray& a)
     {
        cBitArray t(*this);
        t.bb.ua |= a.bb.ua;
        return t;
     }     
       
    cBitArray operator ^ (cBitArray& a)
     {
        cBitArray t(*this);
        t.bb.ua ^= a.bb.ua;
        return t;
     }

    cBitArray operator >> (int a)
     {
        cBitArray t(*this);
        t.bb.ua >>= a;
        return t;
     }

    cBitArray operator << (int a)
     {
        cBitArray t(*this);
        t.bb.ua <<= a;
        return t;
     }

    cBitArray rotate(int a)
     {
        cBitArray t(*this);

        if( a > 0 )
          t >>= a;
        else
          t <<= a;  
    
        return t;
     }

    cBitArray& operator = (const cBitArray& a)
     {
        bb.ua = a.bb.ua;
        return *this;
     }

    cBitArray& operator &= (const cBitArray& a)
     {
 
        bb.ua &= a.bb.ua;
        return *this;
     }

    cBitArray& operator|=(const cBitArray& a)
     {
        bb.ua |= a.bb.ua;
        return *this;
     }

    cBitArray& operator^=(const cBitArray& a)
     {
        bb.ua ^= a.bb.ua;
        return *this;
     }

    cBitArray& operator >>= (int a)
     {
        bb.ua >>= a;
        return *this;
     }

    cBitArray& operator <<= (int a)
     {
        bb.ua <<= a;
        return *this;
     }

    bool operator==(const cBitArray& a)
     {
        return bb.ua == a.bb.ua;
     }

    bool operator==(const U64& a)
     {
        return bb.ua == a; 
     }

    bool operator!=(const cBitArray& a)
     {
        return bb.ua != a.bb.ua;
     }


    void set(RANK_NAMES r, U8 rv)
     {
        U64 mask = rv;
        mask <<= (8*r);
        bb.ua |= mask;
     }

    void setPiece(SQUARE_NAMES sq)
     {
        U64 mask = 1;
        mask  <<= sq;
        bb.ua |= mask;
     }

    cBitArray getPiece(SQUARE_NAMES sq)
     {
        cBitArray t(bb.ua);
        U64 mask = 1 ;
        mask <<= sq;
        t.bb.ua &= mask;
        return t;
     }

    void setPiece(RANK_NAMES rank, FILE_NAMES file)
     {
        int sq = rank * MAX_RANK + file;
        U64 mask = 1;
        mask  <<= sq;
        bb.ua |= mask;
     }

    // returns a mask of a piece in a given square
    cBitArray getPiece(RANK_NAMES rank, FILE_NAMES file)
     {
        cBitArray t(bb.ua);
        int sq = rank * MAX_RANK + file;
        U64 mask = 1 ;
        mask <<= sq;
        t.bb.ua &= mask;
        return t;
     }

    bool isEmpty(RANK_NAMES rank, FILE_NAMES file)
     {
        return (getPiece(rank,file) == 0x00);
     }

    void clear()
     {
        bb.ua = 0;
     }
    
};

extern cBitArray valid_board;
void fillValidBoard(void);

#endif
