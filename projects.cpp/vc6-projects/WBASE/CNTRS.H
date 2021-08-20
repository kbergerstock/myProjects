/*
	cntrs.h
	definition of counter classes
	K. R. Bergerstock
*/

#ifndef __CNTRS_H
#define  __CNTRS_H

#define  MAXCNTRS 50

#define  MAXPARTCNTRS 20

#include "cntr.h"

class COUNTERS
 {
   private:
	 counter _counters[MAXCNTRS];

   public:
	void inc(int flag,int data_type);
	void reset(void);
	void set(unsigned int c, int data_type);
	unsigned int get(int data_type);
	void  Save(void);
	void  Load(void);
 };


class PART_CNTRS
 {
   private:
	 PART_COUNTER _pCounters[MAXPARTCNTRS];

   public:
	  void reset(void);
	  void set(unsigned int t, unsigned int g, int data_type);
	  void inc(int flag,int data_type);
	  unsigned int get_total(int data_type);
	  unsigned int get_good(int data_type);
	  unsigned int get_rejected(int data_type);
	  double get_yield(int data_type);
	  void	Save(void);
	  void	Load(void);
 };

extern COUNTERS    counters;			 // fault counters
extern PART_CNTRS pCounters;			 // passed part counters

#endif
