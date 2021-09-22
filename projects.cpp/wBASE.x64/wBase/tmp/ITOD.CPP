/*
  itod.c
  K. R. Bergerstock

  converts an integer to an ascii string padded with 0's to fill n places
  FIX not safe if n > buf supplied will cause an overwrite
*/

char* itod( long val, char *s, int n)
 {
  char *t = ( s + n);
  *t-- = '\0';

  for ( ; n >0; n--, val/=10)
	{
	 *t-- = char( (val % 10) + '0');
	}
  return (s);
 }
