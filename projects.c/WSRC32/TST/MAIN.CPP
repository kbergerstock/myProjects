// test module for the array class

#include <iostream>
#include <string>
using namespace std;

#include "tARRAY.H"

void main(void)
{
	string a(" Average ");

	cout << " test file for the array class " << endl ;


	tARRAY<float> tArray(5,3.4);	// create the array

    cout << tArray << a << tArray.Average() << endl;


    tArray[1] = 4.5;
    tArray[3] = 5.6;

    cout << tArray << a << tArray.Average() << endl;

    double tmp = tArray[1];

    if(tmp == 3.4)
        	cout << " org val " << endl;
	else
    		cout << " new val " << endl;

}
