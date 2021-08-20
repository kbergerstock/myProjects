// tbitarray.cpp
// keith r. bergerstock

#include <iostream>
#include <cstring>
#include "tBitArray.h"

tBitArray::tBitArray()
{
    _size = 0;
    _bit_array = nullptr;
}

void tBitArray::init(UINT32 nl) {
    if (_bit_array == nullptr) {
        // divide nl by 8 the number of bits in a bit element
        _size = 1 + (nl >> 3); 
        try {
            _bit_array = new BITS[_size];
            // clear the memory since new does not
            memset(_bit_array, 0, _size);
        }
        catch (...) {
            _size = 0;
            _bit_array = nullptr;
            throw("MEMORY ALLOCATION ERROR");
        }
    }
}

void tBitArray::empty() {
    if (_bit_array != nullptr) {
        delete[] _bit_array;
        _bit_array = nullptr;
        _size = 0;
    }
}
