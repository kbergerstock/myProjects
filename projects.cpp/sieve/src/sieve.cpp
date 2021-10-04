// sieve.cpp
// keith r. bergerstock

#include <iostream>
#include <map>
#include <sieve.h>


// fetch the expected numbor of primes to be found for
// the currrent prime limit
UINT32 Sieve::Map::find(UINT32 prime_limit) {
	if (value == 0)
	{
		const ELEMENT _map_[MAP_SIZE] = {
								{10 , 4},
								{100 , 25},
								{1000 , 168},
								{10000 , 1229},
								{100000 , 9592},
								{1000000 , 78498},
								{10000000 , 684579},
								{100000000 , 5761455},
								{0,0}
		};
		for (int i = 0; i < MAP_SIZE; i++) {
			if (_map_[i].key == prime_limit) {
				value = _map_[i].expected;
				break;
			}
		}
	}
	return value;
}

Sieve::Sieve() : map(),
prime_limit(0),
nl(0),
bits()
{

};

// fetch the expected numbor of primes to be found for
// the currrent prime limit

// initialize the data 
void Sieve::init(UINT32 _prime_limit) {
	prime_limit = _prime_limit;
	nl = prime_limit >> 1;
	bits.init(nl);
}

// zero all dat used by the sieve
// preparing the next run
void Sieve::empty() {
	bits.empty();
	prime_limit = 0;
	nl = 0;
}

// execute the sieve algorithm
int Sieve::sieve2() {
	UINT32 j, f, f2, ndx;
	UINT32 primes_found = 1;
	bits.set(0);
	// process the bit array searching for potential  primes
	for (j = 1; j < nl; j++) {
		// search untile we find 0 bit 
		if (!bits.get(j)) {
			// next prime found , calc the factor
			primes_found++;
			f = j << 1;		   	// factor f = (1 + ( j * 2))
			f++;
			f2 = f * f;			// factor sqared		
			// note f*f < prime limit is mathematically 
			// equivelant to f < sqrt(prime Limit)
			// the two formulas are used by wikiopedia  
			if (f2 < prime_limit) {
				// set all multiplies of the factor to not prime
				// starting at the square of the factor
				for (ndx = --f2 >> 1; ndx < nl; ndx += f ){
					bits.set(ndx);
				}
			}
			else
			{
				// if search factor squared exceeds the prime_limit
				// count the rest of the primes
				for (ndx = ++j; ndx < nl; ndx++)
					if (!bits.get(ndx))
						primes_found++;
				// leave the search function
				break;
			}
		}
	}
	return primes_found;
}

//UINT32 Sieve::counted() {
//	UINT32 primes_found = 1;
//	for (UINT32 i = 1; i < nl; i++) {
//		if (bits.get(i) == false)
//			primes_found++;
//	}
//	return primes_found;
//}

bool Sieve::validate(int k)
{
	int m = map.find(prime_limit);
	//int k = counted();
	return m == k;
}

UINT32 Sieve::itor(UINT32 i) {
	UINT32 f = 0;
	switch (i) {
	case 0:
		f = 2;
		break;
	default:
		if (bits.get(i) == 0)
			f = 1 + (i << 1);
	}
	return f;
}

std::ostream& operator<<(std::ostream& os, Sieve &P)
{
	int col = 0;
	os.width(6);
	for (UINT32 i = 0; i < P.nl; i++) {
		UINT32 n = P.itor(i);
		if (n > 0) {
			os.width(6);
			os << n << ",";
			col++;
			if (col > 12) {
				col = 0;
				os << std::endl;
			}
		}
	}
	return os;
}