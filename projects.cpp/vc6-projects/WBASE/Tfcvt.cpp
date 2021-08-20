#ifndef __WINDOWS_H
#define STRICT
#include "windows.h"
#endif

#include <iostream.h>

#include "tstack.h"

#ifndef __TFCVT_H
#define __TFCVT_H

template <class TYPE> class TFCVT
{
	private:
    	int DecimalPos;
        int NumDigits;
    public:
        TFCVT() { DecimalPos = 3; NumDigits = 3;}
        void SetDecimapPos(int p) { DecimalPos = p;}
        void SetNumDigits(int p)  { NumDigits = p;}
        LPSTR Convert(TYPE val, LPSTR S);
};

template <class TYPE> LPSTR TFCVT<TYPE>::Convert(TYPE val,LPSTR s)
{
  int cnt = NumDigits+DecimalPos;
  LPSTR tmp = s;
  TYPE sgn = val < 0.0 ? -1.0 : 1.0;
  int i,
  char a;
  STACK<char> stack;

  float exp = 1.0;
  float fup = 0.5;
  for(i = 0; i < DecimalPos; i++){ exp *= 10.0; fup /= 10.0; }

  long v = (long)((exp * sgn)*(val + fup));

  for(i = 0; i < cnt || v > 0;i++,v/=10)
   {
   	 a = '0' + char(v % 10);
     stack.push(a);
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

void main(void)
{
	TFCVT<float> fcvt;
    char buf[40];
    cout << fcvt.Convert(3.141596,LPSTR(buf)) << endl;
    cout << fcvt.Convert(1010.05050,LPSTR(buf)) << endl;
    cout << fcvt.Convert(-2.76435,LPSTR(buf)) << endl;
    cout << fcvt.Convert(32.02,LPSTR(buf)) << endl;

}
