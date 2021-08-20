/*
	cntr.cpp
	definition of counter classes
	K. R. Bergerstock
*/


#include "cntr.h"

/**********************************************************************/
#ifdef __INLINE__
#else
	counter::counter()			{ _counter = 0; }
	void counter::reset(void)	{ _counter = 0; }
	void counter::inc(void) 	{ _counter++; }

	void counter::set(unsigned int c) { _counter = c; }
	unsigned int counter::get(void)   { return _counter; }
#endif

/**********************************************************************/

void PART_COUNTER::reset(void)
{
	TOTAL.reset();
	GOOD.reset();
}

void PART_COUNTER::inc(int flag)
 {
   TOTAL.inc(); 				// increment total counter
   if(flag) 					// if flag is true (GOOD PART) then inc good counter
	 GOOD.inc();
 }

unsigned int PART_COUNTER::GetTotal(void)
   { return TOTAL.get(); }

unsigned int PART_COUNTER::GetGood(void)
   { return GOOD.get(); }

unsigned int PART_COUNTER::GetRejected(void)
   { return (TOTAL.get() - GOOD.get() ); }

double PART_COUNTER::GetYield(void)
  {
	 if (TOTAL.get() > 1)
	   return ( 100.0 * double(GOOD.get())	/ double(TOTAL.get()) );
	 else
	   return 1.0;
   }

double PART_COUNTER::GetPercentRejected(void)
  {
	if(TOTAL.get() > 10 && GetRejected() > 0)
    	return (100.0 * double(GetRejected()) / double(TOTAL.get() ) );
	else
    	return 0.0;
  }

void PART_COUNTER::set(unsigned t, unsigned g)
  { TOTAL.set(t); GOOD.set(g); }
