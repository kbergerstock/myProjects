// primeSieve.cpp
// Keith r bergerstock


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#ifdef PERFORMANCE_CLOCK
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#include <profileapi.h>
#else
	#include <time.h>
#endif

#include <sieve.h>

void time_sieve(UI32 prime_limit, UI32 time_limit, bool show_primes){
	#ifdef PERFORMANCE_CLOCK
		LARGE_INTEGER freq;
		LARGE_INTEGER t0, t1;
		QueryPerformanceFrequency(&freq);
	#else
		struct timespec t0,t1;
		clockid_t clk_id = CLOCK_REALTIME;
	#endif
	double lt = 0;
	UI32 passes = 0;

	do {
		sieve_empty();
		sieve_init(prime_limit);
		#ifdef PERFORMANCE_CLOCK
			QueryPerformanceCounter(&t0);
			sieve2();
			QueryPerformanceCounter(&t1);
			lt += (t1.QuadPart - t0.QuadPart)* 1000.0 /freq.QuadPart;
		#else
			clock_gettime(clk_id, &t0);
			sieve2();
			clock_gettime(clk_id, &t1);
			lt += ((double)(t1.tv_sec - t0.tv_sec)* 1000.0) + ((double)(t1.tv_nsec - t0.tv_nsec) / 1000000.0);
		#endif
		passes++;
	 } while (sieve_validate() && (lt < time_limit) );

	 // output the results
	fprintf(stdout,"passes %6d elapsed time %10.4f mS  avg/pass %8.4f mS limit %d counted %d validated %d\n"
		,passes,lt,lt/passes,prime_limit,sieve_counted(),sieve_validate() );


	if(show_primes){
		sieve_output();
	}
}

int main(int argc, char* argv []) {

	UI32 prime_limit = 1000000;
	UI32 time_limit = 5000;
	bool show_flag = false;

	for (int  i = 1; i < argc; i++) {
		char *s =  argv[i];
		if (strlen(s) >= 3) {
			if (s[0] == '-' && s[1] == '-' && s[2] == 't') {
				time_limit = atol(&s[3]);
			}
			if (s[0] == '-' && s[1] == '-' && s[2] == 'n') {
				prime_limit = atol(&s[3]);
			}
			if (s[0] == '-' && s[1] == '-' && s[2] == 's') {
				show_flag = true;
			}
		}
	}
	printf("--n%d\n",prime_limit);
	printf("--t%d\n",time_limit);
	time_sieve(prime_limit,time_limit,show_flag);
	return 0;
}
