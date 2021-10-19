// tbitarray.cpp
// keith r. bergerstock

#include <iostream>
#include <cstring>
#include "tBitArray.h"

tBitArray::tBitArray()
{
    _size = 0;
	_nl = 0;
    _bit_array = nullptr;
}

void tBitArray::init(UINT32 nl) {
	_nl = nl;
    if (_bit_array == nullptr) {
        // divide nl by 8 the number of bits in a bit element
        _size = 1 + (_nl >> 3); 
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
		_nl = 0;
    }
}

unsigned int tBitArray::count(UINT32 ndx = 0)
{
	unsigned int count = (ndx == 0 ? 1 : 0);
    if(_bit_array)
        for (unsigned int i = ++ndx; i < _nl; i++)
            if (!get(i))
                count++;
    return count;
}

int tBitArray::sieve( UINT32 prime_limit)
{
	UINT32 j, f, f2, ndx;
	// account for the prime number 2
	UINT32 primes_found = 1;
	// start point is prime number 3  '1 +(1 * 2) = 3'
	j = 1;
	if (_bit_array)
	{
		// process the bit array searching for potential  primes
		do
		{
			// search until we find a 0 bit 
			if (!get(j))
			{
				// next prime found , calc the factor
				primes_found++;
				f = j << 1; f++; 	// factor f = (1 + ( j * 2))
				f2 = f * f;  	    // factor sqared		
				// note f*f < prime limit is mathematically 
				// equivelant to f < sqrt(prime Limit)
				if (f2 < prime_limit)
				{
					// set all multiplies of the factor to not prime
					// starting at the square of the factor
					ndx = --f2 >> 1;
					do {
						set(ndx);
						ndx += f;

					} while (ndx < _nl);
				}
				else
				{
					// if search factor squared exceeds the prime_limit
					// count the rest of the primes
					primes_found += count(j);
					// leave the search function
					break;
				}
			}
		} while (++j);
	}
	else
	{
		throw("empty bit array");
	}
	return primes_found;
}
