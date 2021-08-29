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
void sieve_init(UNUMBER _prime_limit) {
	sieve.prime_limit = _prime_limit;
	sieve.nl = _prime_limit >> 1;
	sieve.bits = bit_array_init(sieve.nl);
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

void mark_multiples(UNUMBER factor, UNUMBER f2) {
	UNUMBER ndx;
	// note f*f < prime limit is mathematically 
	// equivelant to f < sqrt(prime Limit)
	// compares the factor to the prime limit
	
		// set all multiplies if the factor to found
		for (ndx = --f2 >> 1; ndx < sieve.nl; ndx += factor) {
			set(sieve.bits, ndx);
		}
}
// execute the sieve algorithm
void sieve2() {
	UNUMBER j, factor, f2;
	set(sieve.bits, 0);
	// process the bit arrray search for pontienal primes
	for ( j = 1; j < sieve.nl; j++) {
		if( get(sieve.bits,j) == false ) {
			// calc the factor = ( j * 2) + 1
			factor = j << 1;
			factor++;
			f2 = factor * factor;
			// note f² < prime limit is mathematically 
			// equivelant to f < √prime Limit
			// compares the factor² to prime limit
			if (f2 < sieve.prime_limit) 
				mark_multiples(factor,f2);
			else
				// leave the search function
				// if seach factor² exceeds the prime_limit
				break;
		}
	}
}

UNUMBER sieve_counted() {
	UNUMBER primes_found = 1;
	for (UNUMBER i = 1; i < sieve.nl; i++) {
		if (get(sieve.bits,i) == 0)
			primes_found++;
	}
	return primes_found;
}

bool sieve_validate()
{
	return sieve.validation_key == sieve_counted();
}

UNUMBER _itor_(UNUMBER i) {
	UNUMBER r = 0;
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
	for (UNUMBER i = 0; i < sieve.nl; i++) {
		UNUMBER n = _itor_(i);
		if (n > 0) {
			fprintf(stdout,"%6lu, ",n);
			col++;
			if (col > 12) {
				col = 0;
				fprintf(stdout,"\n");
			}
		}
	}
}