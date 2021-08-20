// primeSieve.cpp
// Keith r bergerstock

#include <iostream>
#include <string>
#include <sieve.h>
#include <FFmt.h>

#ifdef	 CLOCK_CHRONO
#include <ctime>
#include <ratio>
#include <chrono>
using namespace std::chrono;
#else
#include <time.h>
#endif

void time_sieve(UINT32 prime_limit, double time_limit, bool show_primes){
	Sieve P;
	#ifdef CLOCK_CHRONO
		steady_clock::time_point t0, t1;
		
	#else
		struct timespec t0, t1;
		clockid_t clk_id = CLOCK_MONOTONIC;
	#endif
	
	double et = 0;
	UINT32 passes = 0;
	do {
		#ifdef CLOCK_CHRONO
			t0 = steady_clock::now();
			P.empty();
			P.init(prime_limit);
			P.sieve2();
			t1 = steady_clock::now();
			duration<double> lt = duration<double>(t1 - t0);
			et += lt.count() * 1000.0;
		#else
			clock_gettime(clk_id, &t0);
			p.empty();
			P.init(pime_limit);
			P.sieve2();
			clock_gettime(clk_id, &t1);
			et += (double(t1.tv_sec - t0.tv_sec)* 1000.0) + (double(t1.tv_nsec - t0.tv_nsec) / 1000000.0); 
		#endif
		passes++;
	} while (P.validate() && (et < time_limit));

	 // output the results
	FFmt time(10,4);

	std::cout << std::dec << "passes: " << passes
	 	  << " elapsed time " << time << et << " mS"
		  << " avg/pass " << time << et / passes << " mS"
		  << " limit " << prime_limit
		  << " count " << P.counted()
		  << " valid " << P.validate() << std::endl;

	if(show_primes){
		std::cout << P;
	}
}

int main(int argc, char*argv []) {

	UINT32 prime_limit = 1000000;
	UINT32 time_limit = 5000;
	bool show_flag = false;

	for (int  i = 1; i < argc; i++) {
		std::string arg(argv[i]);
		if (arg.size() >= 3) {
			std::string cmd = arg.substr(0, 3);
			std::string par = arg.substr(3);
			if (cmd == "--t") {
				time_limit = std::stoul(par.c_str());
			}
			if (cmd == "--n") {
				prime_limit = std::stoul(par.c_str());
			}
			if (cmd == "--s") {
				show_flag = true;
			}
		}
	}
	std::cout << argv[0] << std::endl;
	std::cout << "--n" << prime_limit << std::endl;
	std::cout << "--t" << time_limit << std::endl;
	time_sieve(prime_limit,time_limit,show_flag);
	return 0;;
}
