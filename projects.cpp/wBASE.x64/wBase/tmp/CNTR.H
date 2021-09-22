/*
	cntr.h
	definition of counter classes
	K. R. Bergerstock
*/

#ifndef  __CNTR_H
#define  __CNTR_H

class counter
 {
   protected:
	unsigned int _counter;

   public:
	counter():_counter(0) {}
	inline void reset(void)			{ _counter = 0; }
	inline void inc(void)			{ _counter++; }
	inline void set(unsigned int c) { _counter = c; }
	inline unsigned int get(void)	{ return _counter; }
 };

class PART_COUNTER
 {
   private:
	 counter TOTAL;
	 counter GOOD;

   public:
	 void reset(void);
	 void inc(int flag);
	 void set(unsigned t, unsigned g);
	 unsigned int GetTotal(void);
	 unsigned int GetGood(void);
	 unsigned int GetRejected(void);
     double GetPercentRejected(void);
	 double GetYield(void);
 };

#endif
