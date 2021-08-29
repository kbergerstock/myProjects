
// prime sieve
// Keith R. Bergerstock
// 64 bit version

#ifndef __SIEVE
#define __SIEVE

#include <tBitArray.h>

typedef struct{UNUMBER key;UNUMBER val;} Expected;

typedef struct {
		UNUMBER prime_limit;
		bits_ptr bits;
		UNUMBER validation_key;
		UNUMBER nl;
} SIEVE;

		void sieve_init(UNUMBER);
		void sieve_empty();
		void sieve2();
		UNUMBER sieve_counted();
		bool sieve_validate();
		void sieve_output();

#endif
