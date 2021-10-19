// primeSieve.cpp
// Keith r bergerstock

#include <iostream>
#include <stdio.h>
#include <thread>
#include <string>
#include <sieve.h>
#include <FFmt.h>

#include <ctime>
#include <ratio>
#include <chrono>
using namespace std::chrono;

void time_sieve(UINT32 prime_limit,  unsigned int time_limit, bool show_primes)
{
	// initialize locals
	auto t = steady_clock::now();

	Sieve P;
	int primes_found = 0;
	UINT32 passes = 0;
	unsigned int et = 0;
	P.set_prime_count(prime_limit);
	// start time
	auto t0 = steady_clock::now();
	// perform the sieve
	do {
		P.empty();
		P.init(prime_limit);
		primes_found = P.sieve2();
		passes++;
		// get the duration till now
		et = duration_cast<milliseconds>(steady_clock::now() - t0).count();
		// exit the loop if sieve fails or elapsed time is complete
	} while (P.validate(primes_found) && et < time_limit);


	 // output the results
	FFmt time(10,4);

	std::cout << std::dec << "passes: " << passes
	 	  << " elapsed time " << time << et << " mS"
		  << " avg/pass " << time << double(et) / double(passes) << " mS"
		  << " limit " << prime_limit
		  << " count " << primes_found
		  << " valid " << P.validate(primes_found) << std::endl;

	if(show_primes){
		std::cout << P;
	}
}

int main(int argc, char*argv []) {

	UINT32 prime_limit = 1000000;
	UINT32 time_limit = 5000;
	bool show_flag = false;
	try {
		for (int i = 1; i < argc; i++) {
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

		time_sieve(prime_limit, time_limit, show_flag);
	}
	catch (char *szErr)
	{
		std::cerr << szErr;
	}
	catch (...)
	{
		std::cerr << "unhandled exception";
	}
	return 0;
}
