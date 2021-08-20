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
			UINT32 find(UINT32);
		};

		UINT32  prime_limit;
		UINT32  nl;
		UINT32  itor(UINT32);
		Map     map;
		tBitArray bits;

	public:
		Sieve();

		void init(UINT32);
		void empty();
		void sieve2();
		UINT32 counted();
		bool validate(); 
		
		friend std::ostream& operator<<(std::ostream& os, Sieve &P);

};

#endif