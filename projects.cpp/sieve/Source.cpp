// timing routine for primeSieve
// k.r.bergerstock

#include <cstdlib>
#include <thread>

void timer(char& time_out,unsigned long time_limit)
{
	// lock time out
	time_out = 0;
	// unlock time_out
	_sleep(time_limit);
	// lock time out
	time_out = 1;
	// unlock time_out
}

void start_timer(char& time_out,double time_limit)
{
	unsigned long tl = time_limit;
	std::thread(timer, time_out tl);
}