// tBitArray.h
// keith r bergerstock
// simplified bit array

#ifndef __T_BIT_ARRAY
#define __T_BIT_ARRAY

#include <cstdint>

typedef uint32_t UINT32;

class tBitArray
{
    typedef unsigned char BITS;

private:
    UINT32 _size;
    BITS* _bit_array;
    // divide idx by 8 to get the indice into the bitarray
    inline UINT32 idx(UINT32 i) { return i >> 3; }
    // use the bottom 3 bits of idx to form the mask 
    inline BITS mask(UINT32 i) { return 1 << (i & 0x7); }

    public:
        tBitArray();
        void init(UINT32 size);
        void empty();
        unsigned int count(UINT32);
 
        ~tBitArray(){ empty(); }

        inline bool get(UINT32 i) { return _bit_array[idx(i)] & mask(i); }
        inline void set(UINT32 i) {_bit_array[idx(i)] |= mask(i); }
        inline void clr(UINT32 i) {_bit_array[idx(i)] &= ~mask(i); }
};

#endif