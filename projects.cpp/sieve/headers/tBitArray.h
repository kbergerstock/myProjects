// tBitArray.h
// keith r bergerstock
// simplified bit array

#ifndef __T_BIT_ARRAY
#define __T_BIT_ARRAY

#include <cstdint>

typedef uint32_t UINT32;

class tBitArray
{
    typedef uint8_t BITS;

private:
    UINT32 _nl;                 // prime_limit / 2
    UINT32 _size;               // size of _bit_array ie (_nl/8)
    BITS*  _bit_array;          // storage space for sieve results
    // divide idx by 8 to get the indice into the bitarray
    inline UINT32 idx(UINT32 i) { return i >> 3; }
    // use the bottom 3 bits of idx to form the mask 
    inline BITS mask(UINT32 i) { return 1 << (i & 0x07); }

    public:
        tBitArray();
        void init(UINT32 size);
        void empty();
        unsigned int count(UINT32);
        int sieve(UINT32 prime_limit);
 
        ~tBitArray(){ empty(); }

        inline bool get(UINT32 i) { return _bit_array[idx(i)] & mask(i); }
        inline void set(UINT32 i) {_bit_array[idx(i)] |= mask(i); }
        inline void clr(UINT32 i) {_bit_array[idx(i)] &= ~mask(i); }
};

#endif