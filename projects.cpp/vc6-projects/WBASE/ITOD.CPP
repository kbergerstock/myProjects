/*
  itod.c
  K. R. Bergerstock

  converts an integer to an ascii string padded with 0's to fill cnt places
*/

char* itod( long val, char *s, int cnt)
 {
  char *t = ( s + cnt);
  *t-- = '\0';

  for ( ; cnt >0; cnt --, val/=10)
	{
	 *t-- = char( (val % 10) + '0');
	}
  return (s);
 }
