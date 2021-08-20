// tbitarray.cpp
// keith r. bergerstock

#include<malloc.h>
#include "tBitArray.h"

bits_ptr bit_array_init( bits_ptr bits,UI32 nl) {
    int size = 1 + (nl / SIZE_OF_BITS);
    return (bits_ptr)calloc(size,sizeof(BITS));
}

bits_ptr bit_array_empty(bits_ptr bits) {
    free(bits);
    return 0;
}

