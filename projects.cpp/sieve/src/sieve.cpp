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
prime_count(0),
bits()
{

};

// fetch the expected numbor of primes to be found for
// the currrent prime limit

// initialize the data 
void Sieve::init(UINT32 _prime_limit) {
	prime_limit = _prime_limit;
	bits.init(prime_limit >> 1);
}

// zero all dat used by the sieve
// preparing the next run
void Sieve::empty() {
	bits.empty();
	prime_limit = 0;
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
	UINT32 nl = P.prime_limit >> 1;
	os.width(6);
	for (UINT32 i = 0; i < nl; i++) {
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