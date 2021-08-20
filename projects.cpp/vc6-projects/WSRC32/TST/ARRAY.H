// arraydb.h

#ifndef __array_h
#define __array_h

#include <iostream.h>

class ArrayDb
{
	protected:
    	int size;
        double *arr;
	public:
    	ArrayDb();
        explicit ArrayDb(unsigned int n, double val = 0.0);
        ArrayDb(const double *pn, unsigned int n);
        ArrayDb(const ArrayDb &a);
        virtual ~ArrayDb();
        unsigned int ArSize() const { return size; }
        double Average() const;

        virtual double & operator[](int i);
        virtual const double & operator[](int i)const;
        ArrayDb & operator=(const ArrayDb & a);
        friend ostream & operator<<(ostream &os, const ArrayDb & a);
};

#endif
