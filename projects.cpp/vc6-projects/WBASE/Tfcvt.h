#ifndef __WINDOWS_H
#define STRICT
#include "windows.h"
#endif

#include "tstack.h"

#ifndef __TFCVT_H
#define __TFCVT_H

template <class TYPE> class TFCVT
{
	private:
		int DecimalPos;
		int NumDigits;
	public:
		TFCVT() { DecimalPos = 3; NumDigits = 0;}
		void SetDecimalPos(int p) { DecimalPos = p;}
		void SetNumDigits(int p)  { NumDigits = p;}
		LPSTR Convert(TYPE val, LPSTR S);
};

template <class TYPE> LPSTR TFCVT<TYPE>::Convert(TYPE val,LPSTR s)
{
  int cnt = NumDigits+DecimalPos;
  LPSTR tmp = s;
  TYPE sgn = val < 0.0 ? -1.0 : 1.0;
  int i,w;
  STACK<char> stack;

  double exp = 1.0;
  for(i = 0; i < DecimalPos; i++)
		exp *= 10.0;

  long v = (long)((exp * sgn * val) + 0.5);

  for(i = 0; i < cnt || v > 0;i++,v/=10)
   {
	 w = '0' + (v % 10);
	 stack.push(char(w));
	 if(i == (DecimalPos-1))
	  stack.push('.');
   }
 if(sgn < 0)
   stack.push('-');

 for(char a=stack.pop(); a; a=stack.pop() )
	{ *tmp++ = a; *tmp = 0; }

 return s;
}

#endif

