// tBitArray.h
// keith r bergerstock
// simplified bit array

#include <stdbool.h>

#ifndef __T_BIT_ARRAY
#define __T_BIT_ARRAY

typedef unsigned long long UNUMBER;
typedef unsigned char BITS;
typedef BITS* bits_ptr;

inline UNUMBER idx(UNUMBER i) { return i >> 3;}
inline BITS mask(UNUMBER i) { return 1 << (i & 0x07);}
inline bool get(bits_ptr bits, UNUMBER i) {return (bits[idx(i)] & mask(i));}
inline void set(bits_ptr bits, UNUMBER i) {bits[idx(i)] |= mask(i);}
inline void clr(bits_ptr bits, UNUMBER i) {bits[idx(i)] &= ~mask(i);}

bits_ptr bit_array_init(UNUMBER);
bits_ptr bit_array_empty(bits_ptr);

#endif
