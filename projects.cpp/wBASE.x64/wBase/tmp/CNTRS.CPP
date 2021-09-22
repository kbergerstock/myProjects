/*
	cntr.cpp
	definition of counter classes
	K. R. Bergerstock
*/


#include "cntrs.h"

#include <stdio.h>

/**********************************************************************/

void COUNTERS::inc(int flag, int data_type)
	{
	  if(data_type < MAXCNTRS)
		if(! flag)
		  _counters[data_type].inc();
	}

void COUNTERS::reset(void)
	{ for ( int i = 0; i < MAXCNTRS; i++) _counters[i].reset(); }

unsigned int COUNTERS::get(int data_type)
	{ return  (data_type < MAXCNTRS) ? _counters[data_type].get() : 0 ; }

void COUNTERS::set(unsigned int c, int data_type)
	{ if( data_type < MAXCNTRS) _counters[data_type].set(c); }


void COUNTERS::Save(void)
 {
   FILE *fp = fopen("CNTR.DAT","wt");                   // open save data file
   if(fp != NULL)										// if successful
	{
	  for(int i = 0; i < MAXCNTRS; i++) 				// for each counter
		fprintf(fp,"%d %d\n",i,get(i) );                // save the tag and the data
	  fclose(fp);										// close the file
	}
 }

void COUNTERS::Load(void)
 {

   FILE *fp = fopen("CNTR.DAT","rt");                   // open save data file
   if(fp != NULL)										// if successful
	{
	  char buf[80]; 									// input buffer
	  int tag,count;									// data locations

	  while(!feof(fp) ) 								// for all data in the file
	   {
		 fgets(buf,80,fp);								// read a line from the file
		 sscanf(buf,"%d %d",&tag,&count);               // convert the line to data
		 set(count,tag);								// set the counter to the value
	   }

	  fclose(fp);										// close the file
	}
  }

/**********************************************************************/

void PART_CNTRS::reset(void)
{
  for( int i = 0; i < MAXPARTCNTRS; i++)
	_pCounters[i].reset();
}

void PART_CNTRS::inc(int flag, int data_type)
 {
   if(data_type < MAXPARTCNTRS)
	  _pCounters[data_type].inc(flag);
 }

unsigned int PART_CNTRS::get_total(int data_type)
   { return (data_type < MAXPARTCNTRS) ? _pCounters[data_type].GetTotal() : 0 ; }

unsigned int PART_CNTRS::get_good(int data_type)
   { return (data_type < MAXPARTCNTRS) ? _pCounters[data_type].GetGood() : 0; }

unsigned int PART_CNTRS::get_rejected(int data_type)
   { return (data_type < MAXPARTCNTRS) ? _pCounters[data_type].GetRejected() : 0; }

double PART_CNTRS::get_yield(int data_type)
   { return (data_type < MAXPARTCNTRS) ? _pCounters[data_type].GetYield() : 0.0 ; }

void PART_CNTRS::set(unsigned int t, unsigned int g, int data_type)
   { if(data_type < MAXPARTCNTRS) _pCounters[data_type].set(t,g); }

void PART_CNTRS::Save(void)
 {
   FILE *fp = fopen("PARTCNTR.DAT","wt");               // open save data file
   if(fp != NULL)										// if successful
	{
	  for(int i = 0; i < MAXPARTCNTRS; i++) 					// for each counter
		fprintf(fp,"%d %d %d \n",i,get_total(i),get_good(i) );  // save the tag and the data
	  fclose(fp);												// close the file
	}
 }

void PART_CNTRS::Load(void)
 {

   FILE *fp = fopen("PARTCNTR.DAT","rt");               // open save data file
   if(fp != NULL)										// if successful
	{
	  char buf[80]; 									// input buffer
	  int tag,t,g;										// data locations

	  while(!feof(fp) ) 								// for all data in the file
	   {
		 fgets(buf,80,fp);								// read a line from the file
		 sscanf(buf,"%d %d %d",&tag,&t,&g);             // convert the line to data
		 set(t,g,tag);									// set the counter to the value
	   }

	  fclose(fp);										// close the file
	}
  }

