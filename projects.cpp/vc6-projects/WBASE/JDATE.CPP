#ifndef  __WINDOWS_H
#include "windows.h"
#endif

#include "jdate.h"

char *itod(long,char*,int);
const char* _Months = "123456789ONDx";

char* JDATECODE::GetJDC(void) { return datecode_J; }
char* JDATECODE::GetCDC(void) { return datecode_C; }

char* JDATECODE::GetShift(void) { return SHIFT; }

void JDATECODE::Fill(void)
{
   time_t Timer = time(time_t(0));			// get the current time
   tblock = localtime(&Timer);				// convert time to time struct block

   // update the julian date code format DDDY
   int dc = (tblock->tm_yday + 1) * 10; 	// get day part of date code
   dc+= tblock->tm_year %10;				// get year part of date code
   itod(dc,datecode_J,4); 					// convert date code to ascii string

   // update the common date code
   wsprintf(datecode_C,"%c%c%2d",			// format is YMDD
		(tblock->tm_year % 10)+0x30,		// Y = last digit of current year
			_Months[tblock->tm_mon],		// M = month code from array
				tblock->tm_mday);			// DD = two digit day of the months

   // update the shift id string
   if(tblock->tm_hour >= 7 && tblock->tm_hour < 15)
	  SHIFT[0] = TestCodes[0];
   else if(tblock->tm_hour >= 15 && tblock->tm_hour < 23)
	  SHIFT[0] = TestCodes[1];
   else
	  SHIFT[0] = TestCodes[2];
   SHIFT[1] = '\0';
}

char* JDATECODE::GetTimeStr(void)
{
	Fill(); 									// fetch the new system time

	wsprintf(szTimeStr,"%02d/%02d/%04d,%02d:%02d:%02d",
						tblock->tm_mon+1,
						tblock->tm_mday,
						tblock->tm_year+1900,
						tblock->tm_hour,
						tblock->tm_min,
						tblock->tm_sec );
	return szTimeStr;
}

void  JDATECODE::SetIds(LPSTR szINI)
{
  TestCodes[0] = GetPrivateProfileChar("TITLE","SHIFT1",'!',szINI);
  TestCodes[1] = GetPrivateProfileChar("TITLE","SHIFT2",'@',szINI);
  TestCodes[2] = GetPrivateProfileChar("TITLE","SHIFT3",'#',szINI);
  RollCounter  = GetPrivateProfileInt("TITLE","ROLLC",100,szINI);
  Fill();
}

char* JDATECODE::GetRollStr(void)
{
	RollCounter++;

	if(RollCounter > 999)
		RollCounter = 100;

	itod(RollCounter,szRollStr,3);

	return szRollStr;
}


