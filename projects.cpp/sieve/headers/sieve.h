// prime sieve
// Keith R. Bergerstock
// 64 bit version

#include <iostream>
#include <tBitArray.h>

#ifndef __SIEVE
#define __SIEVE

#define MAP_SIZE 9

class Sieve
{
	private:
		class Map{
		private:
			typedef struct _MAP_ {
				UINT32 key;
				UINT32 expected;
			}ELEMENT;
		public:
			Map() : value(0) {};
			UINT32 find(UINT32);
			UINT32 value;
		};

		UINT32  prime_limit;
		UINT32  prime_count;
		UINT32  itor(UINT32);
		Map     map;
		tBitArray bits;

	public:
		Sieve();
		// create the bit array used for a pass
		void init(UINT32);
		// delete the bit array used for a pass
		void empty();
		// fetch and store the expected number of primes
		inline void set_prime_count(UINT32 prime_limit) { prime_count = map.find(prime_limit); }
		// execute the sieve algorithm
		inline int sieve2() { return bits.sieve(prime_limit); }
		// ensure that the expected matches th found number of primes
		inline bool validate(int k) { return !(k ^ prime_count); }
		// out put the found primes to the display
		friend std::ostream& operator<<(std::ostream& os, Sieve &P);

};

#endif