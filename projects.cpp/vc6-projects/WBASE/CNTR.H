/*
	cntr.h
	definition of counter classes
	K. R. Bergerstock
*/

#ifndef  __CNTR_H
#define  __CNTR_H

#define  __INLINE__

class counter
 {
   protected:
	unsigned int _counter;

   public:
#ifdef __INLINE__
	counter()				 { _counter = 0; }
	void reset(void)		 { _counter = 0; }
	void inc(void)			 { _counter++; }
	void set(unsigned int c) { _counter = c; }
	unsigned int get(void)	 { return _counter; }
#else
	counter();
	void reset(void);
	void inc(void);
	void set(unsigned int c);
	unsigned int get(void);
#endif
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
