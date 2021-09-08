// test module for the array class

#include <iostream>
#include <string>
using namespace std;

#include "tARRAY.H"

int main(void)
{
	string a(" Average ");

	cout << " test file for the array class " << endl ;


	tARRAY<float> tArray(25);	    // create the array
    for (int i = 0; i < 25; i++)    // fill the array;
        tArray[i] = float(3.4);
    tARRAY<float> tCopy(tArray);    // copy the array

    tArray[1] = 4.5;
    tArray[3] = 5.6;

    double tmp = tArray[1];
    double tmp1 = tCopy[1];

    cout <<" tArray[1] " << tmp <<" , tCopy[1] " << tmp1 << endl;

    if(tmp == 3.4)
        	cout << " org val " << endl;
	else
    		cout << " new val " << endl;
   return 0;
}
