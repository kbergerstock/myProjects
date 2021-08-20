// class bit array
// a bit represnetation of a chess board

#ifndef __cBitArray_h
#define __cBitArray_h

typedef unsigned char  bROW;
typedef unsigned char  bCOL;

#ifdef __BIT32__
    typedef unsigned long  lROW;
#else
    typedef unsigned __int64  uROW; 
#endif

/*
    typical representaiton of a board
          abcdefgh          
    1     xxxxxxxx  0   
    2     xxxxxxxx  1
    3     xxxxxxxx  2
    4     xxxxxxxx  3
    5     xxxxxxxx  4
    6     xxxxxxxx  5
    7     xxxxxxxx  6
    8     xxxxxxxx  7
          01234567  

*/

enum SQUARE_NAMES
{
    A1,B1,C1,D1,E1,F1,G1,H1,
    A2,B2,C2,D2,E2,F2,G2,H2,
    A3,B3,C3,D3,E3,F3,G3,H3,
    A4,B4,C4,D4,E4,F4,G4,H4,
    A5,B5,C5,D5,E5,F5,G5,H5,
    A6,B6,C6,D6,E6,F6,G6,H6,
    A7,B7,C7,D7,E7,F7,G7,H7,
    A8,B8,C8,D8,E8,F8,G8,H8,
    NO_SQUARE
};

#ifdef __BIT32__
union BITBOARD
{
    bROW  ba[8];
    lROW  la[2];
};
#else

union BITBOARD
{
    bROW ba[8];
    uROW ua;
};
#endif

// idea turn into an inline class for speed improvements

class cBitArray
{
    protected:
        BITBOARD bb;
    public:

    // logical operators
    uROW operator &(cBitArray& a)
      {
            return bb.ua  & a.bb.ua;
      }  
   
    uROW operator |(cBitArray& a)
      {
            return bb.ua | a.bb.ua;
      }
  
    uROW operator ^(cBitArray& a)
      {
            return bb.ua ^ a.bb.ua;
      }

    // logical operators
    void and(cBitArray &a)
        {
            #ifdef __BIT32__
	             bb.la[0] &= a.bb.la[0];
	             bb.la[1] &= a.bb.la[1];
            #else
                 bb.ua &= a.bb.ua; 
            #endif //__BIT32__

        }
    void or(cBitArray &a)
        {
            #ifdef __BIT32__
	             bb.la[0] |= a.bb.la[0];
	             bb.la[1] |= a.bb.la[1];
            #else
                  bb.ua |= a.bb.ua;
            #endif //__BIT32__

        }
    void xor(cBitArray &a)
        {
            #ifdef __BIT32__
                bb.la[0] ^= a.bb.la[0];
                bb.la[1] ^= a.bb.la[1];
            #else
                bb.ua ^= a.bb.ua;
            #endif
        }

    void not(cBitArray &a)
        {
            #ifdef __BIT32__
                bb.la[0] = ~a.bb.la[0];
                bb.la[1] = ~a.bb.la[1];
            #else
                bb.ua = ~a.bb.ua;    
            #endif
        }

    cBitArray& operator=(const cBitArray& a)
        {
            #ifdef __BIT32__
                bb.la[0] = a.bb.la[0];
                bb.la[1] = a.bb.la[1];
            #else
                bb.ua = a.bb.ua;
            #endif

            return *this;
        }

    cBitArray& operator&=(const cBitArray& a)
        {
            #ifdef __BIT32__
                bb.la[0] &= a.bb.la[0];
                bb.la[1] &= a.bb.la[1];
            #else
                bb.ua &= a.bb.ua;
            #endif
            return *this;
        }
    cBitArray& operator|=(const cBitArray& a)
        {
            #ifdef __BIT32__
                bb.la[0] |= a.bb.la[0];
                bb.la[1] |= a.bb.la[1];
            #else
                bb.ua |= a.bb.ua;
            #endif
            return *this;
        }

    cBitArray& operator^=(const cBitArray& a)
        {
            #ifdef __BIT32__
                bb.la[0] ^= a.bb.la[0];
                bb.la[1] ^= a.bb.la[1];
            #else
                bb.ua ^= a.bb.ua;
            #endif
            return *this;
        }

    cBitArray& operator~()
     {
        #ifdef __BIT32__
            ~bb.la[0] ;
            ~bb.la[1];
        #else
            bb.ua = ~bb.ua;
        #endif    
        return *this;
     }  

    bool operator==(const cBitArray& a)
     {
        #ifdef __BIT32__
            return  (bb.la[0] == a.bb.la[0]) && ( bb.la[1] == a.bb.la[1]);
        #else
            return bb.ua == a.bb.ua;
        #endif
     }

    void copy(const cBitArray& a)
        {
            #ifdef __BIT32__
                bb.la[0] = a.bb.la[0];
                bb.la[1] = a.bb.la[1];
            #else
                bb.ua = a.bb.ua;
            #endif
        }

    // set a given rank/file to a bit value
    void rset(int n ,bROW r)
        {
            bb.ba[n] = r;
        }

    void set(int rank, bROW r)
        {
             bb.ba[rank-1] = r;
        }

    void setPiece(SQUARE_NAMES sq)
       {
            #ifdef __BIT32__
          
            #else
                uROW mask = 1;
                mask  <<= sq;
                bb.ua |= mask;
            #endif
       }
    void setPiece(int rank,int file)
      {
            bROW mask = (1 << (file-1));
            bb.ba[rank-1] |= mask;
      }

    // returns a mask of a piece in a given rank
    bROW getPiece(int rank, int file)
        {
            bROW mask = (1 << (file-1));
            return bb.ba[rank-1] & mask;
        }

    int isEmpty(int rank,int file)
       {
            return (getPiece(rank,file) == 0x00);
       }

    // returns contents of given rank
    bROW operator[](int rank) { return bb.ba[rank-1]; }

    int  active()
        {
            
            #ifdef __BIT32__
                bROW r = 0x00;
                for(int i = 0; i < 8; i++)
                    r |= _ba[i];
                return r ? 1 : 0;    
            #else
                return bb.ua ? 1 : 0;
            #endif
        }

    void clear()
        {
            #ifdef __BIT32__
                bb.la[0] = 0;
                bb.la[1] = 0;
            #else
                bb.ua = 0;
            #endif
        }

    // constructors
    cBitArray()                     // null constructor
        {
            #ifdef __BIT32__
                bb.la[0] = 0;
                bb.la[1] = 0;
            #else
                bb.ua = 0;
            #endif
        }

    cBitArray(const cBitArray& a)   // copy constructor
        {
            #ifdef __BIT32__
                bb.la[0] = a.bb.la[0];
                bb.la[1] = a.bb.la[1];
            #else
                bb.ua = a.bb.ua;
            #endif
        }
    cBitArray(bROW _rows[8]);       // constuctor from a row array 

    cBitArray(uROW b)
     {
        bb.ua = b;
     }
    
};

extern cBitArray valid_board;
void fillValidBoard(void);

#endif
