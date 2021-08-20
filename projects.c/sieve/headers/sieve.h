
// prime sieve
// Keith R. Bergerstock
// 64 bit version

#ifndef __SIEVE
#define __SIEVE

#include <tBitArray.h>

typedef struct{UI32 key;UI32 val;} Expected;

typedef struct {
		UI32 prime_limit;
		bits_ptr bits;
		UI32 validation_key;
		UI32 nl;
} SIEVE;

		void sieve_init(UI32);
		void sieve_empty();
		void sieve2();
		UI32 sieve_counted();
		bool sieve_validate();
		void sieve_output();

#endif
