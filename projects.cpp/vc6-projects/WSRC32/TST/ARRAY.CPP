#include "array.h"
#include <stdlib.h>

ArrayDb::ArrayDb()
{
	arr = NULL;
    size = 0;
}

ArrayDb::ArrayDb(unsigned int n, double val)
{
	arr = new double[n];
    size = n;
    for(int i = 0; i < size; i++)
    	arr[i] = val;
}

ArrayDb::ArrayDb(const double *pn, unsigned int n)
{
	arr = new double[n];
    size = n;
    for(int i = 0; i < size; i++ )
    	arr[i] = pn[i];
}

ArrayDb::ArrayDb(const ArrayDb & a)
{
	size = a.size;
    arr = new double[size];
    for (int i = 0; i < size; i++)
    	arr[i] = a.arr[i];
}

ArrayDb::~ArrayDb()
{
	delete [] arr;
    size = 0;
}

double ArrayDb::Average() const
{
	double r,sum;
    r = sum = 0.0;
    int i;
    int lim = ArSize();
    for(i = 0; i < lim ; i++ )
    	sum += arr[i];

	if(i > 0)
    	r = sum / double(i);
    else
    	cout << " No entries on score array " << endl;

	return r;
}

double & ArrayDb::operator[](int i)
{
	if(i < 0 || i >= size)
    	{
        	cout << " Error in array limits :"
            	<< i << " is a bad index" << endl;
            exit(1);
        }
	return arr[i];
}

const double & ArrayDb::operator[](int i)const
{
	if(i < 0 || i >= size)
    	{
        	cout << " Error in array limits :"
            	<< i << " is a bad index" << endl;
            exit(1);
        }
	return arr[i];
}

ArrayDb & ArrayDb::operator=(const ArrayDb & a)
{
	if(this != & a)
     {
	    delete arr;
	    size = a.size;
	    arr = new double[size];
	    for(int i = 0; i < size; i++)
	    	arr[i] = a.arr[i];
     }
	return *this;
}

ostream & operator<<(ostream &os, const ArrayDb & a)
{
	int i;
    for(i = 0; i < a.size; i++)
     {
     	os << a.arr[i] << " " ;
        if( i % 5 == 4)
        	os << endl;
     }

	if(i % 5 != 0)
		os << endl;

   return os;
}

