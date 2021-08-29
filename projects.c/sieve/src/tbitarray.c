// tbitarray.cpp
// keith r. bergerstock

#include <malloc.h>
#include "tBitArray.h"

bits_ptr bit_array_init( UNUMBER nl) {
    int size = 1 + (nl >> 3);
    return (bits_ptr)calloc(size,sizeof(BITS));
}

bits_ptr bit_array_empty(bits_ptr bits) {
    if (bits != 0)
        free(bits);
    return 0;
}

