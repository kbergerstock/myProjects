// sieve.cpp
// keith r. bergerstock



#include <stdio.h>
#include <sieve.h>

const Expected  M[] = {
			{10 , 4},
			{100 , 25},
			{1000 , 168},
			{10000 , 1229},
			{100000 , 9592},
			{1000000 , 78498},
			{10000000 , 684579},
			{100000000 , 5761455},
		};

// use static memory to hold the sieve variables
SIEVE sieve;

// initialize the data 
void sieve_init(UI32 _prime_limit) {
	sieve.prime_limit = _prime_limit;
	sieve.nl = _prime_limit / 2;
	sieve.bits = bit_array_init(sieve.bits,sieve.nl);
	sieve.validation_key = 0; 
	for (int i = 0; i < 8; i++){
		if(M[i].key == _prime_limit){
			sieve.validation_key = M[i].val;
			break;
		}
	}
}

// zero all dat used by the sieve
// preparing the next run
void sieve_empty() {
	sieve.bits = bit_array_empty(sieve.bits);
	sieve.prime_limit = 0;
	sieve.nl = 0;
}

// ec\xecute the sieve algorithm
void sieve2() {
	UI32 j, f, f2, ndx;
	set(sieve.bits, 0);
	// process the bit arrray search for pontienal primes
	for ( j = 1; j < sieve.nl; j++) {
		if( get(sieve.bits,j) == false ) {
			// calc the factor = ( j * 2) + 1
			f = j << 1; f++;
			f2 = f * f;
			// note f*f < prime limit is mathematically 
			// equivelant to f < sqrt(prime Limit)
			// compares the factor to the prime linit
			if (f2  < sieve.prime_limit) { 
				// set all multiplies if the factor to found
				for (ndx = (f2--) >> 1 ; ndx < sieve.nl; ndx += f) {
					set(sieve.bits, ndx);
				}
			}
			else
				// leave the search function
				// if seach factor squared exceeds the prime_limit is                                                
				break;
		}
	}
}

UI32 sieve_counted() {
	UI32 primes_found = 1;
	for (UI32 i = 1; i < sieve.nl; i++) {
		if (get(sieve.bits,i) == 0)
			primes_found++;
	}
	return primes_found;
}

bool sieve_validate()
{
	return sieve.validation_key == sieve_counted();
}

UI32 _itor_(UI32 i) {
	UI32 r = 0;
	switch (i) {
	case 0:
		r = 2;
		break;
	default:
		if(get(sieve.bits,i) == false)
			r = 1 + (i * 2);
	}
	return r;
}

void sieve_output()
{
	int col = 0;
	for (UI32 i = 0; i < sieve.nl; i++) {
		UI32 n = _itor_(i);
		if (n > 0) {
			fprintf(stdout,"%6d, ",n);
			col++;
			if (col > 12) {
				col = 0;
				fprintf(stdout,"\n");
			}
		}
	}
}