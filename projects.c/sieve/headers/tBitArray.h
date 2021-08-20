// tBitArray.h
// keith r bergerstock
// simplified bit array

#include <stdbool.h>

#ifndef __T_BIT_ARRAY
#define __T_BIT_ARRAY

typedef unsigned int UI32;
typedef unsigned char BITS;
typedef BITS* bits_ptr;

#define SIZE_OF_BITS 8
inline UI32 idx(UI32 i) { return i / SIZE_OF_BITS; }
inline BITS mask(UI32 i) { return 1 << (i % SIZE_OF_BITS);}
inline bool get(bits_ptr bits, UI32 i) {return (bits[idx(i)] & mask(i));}
inline void set(bits_ptr bits, UI32 i) {bits[idx(i)] |= mask(i);}
inline void clr(bits_ptr bits, UI32 i) {bits[idx(i)] &= ~mask(i);}

bits_ptr bit_array_init(bits_ptr, UI32);
bits_ptr bit_array_empty(bits_ptr);

#endif
