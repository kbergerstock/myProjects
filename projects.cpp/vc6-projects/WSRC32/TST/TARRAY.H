// tarray.h

#include <stdlib.h>

#ifndef __tarray_h
#define __tarray_h

#include <iostream.h>

template <class T> class tARRAY
{
	private:
    	int size;
        T* arr;
	public:
    	tARRAY();
        explicit tARRAY(unsigned int n, T val = 0.0);
        tARRAY(const T *pn, unsigned int n);
        tARRAY(const tARRAY<T> &a);
        virtual ~tARRAY();

        unsigned int ArSize() const { return size; }
        T Average() const;

        virtual T& operator[](int i);
        virtual const T& operator[](int i)const;
        tARRAY<T>& operator=(const tARRAY<T>& a);

        friend ostream & operator<<(ostream &os, const tARRAY<T>& a);

};

template <class T> tARRAY<T>::tARRAY()
{
	arr = NULL;
    size = 0;
}

template <class T> tARRAY<T>::tARRAY(unsigned int n, T val)
{
	arr = new T[n];
    size = n;
    for(int i = 0; i < size; i++)
    	arr[i] = val;
}

template <class T> tARRAY<T>::tARRAY(const T* pn, unsigned int n)
{
	arr = new T[n];
    size = n;
    for(int i = 0; i < size; i++ )
    	arr[i] = pn[i];
}

template <class T> tARRAY<T>::tARRAY(const tARRAY<T>& a)
{
	size = a.size;
    arr = new T[size];
    for (int i = 0; i < size; i++)
    	arr[i] = a.arr[i];
}

template <class T> tARRAY<T>::~tARRAY()
{
	delete [] arr;
    size = 0;
}

template <class T> T tARRAY<T>::Average() const
{
	T r,sum;
    r = sum = T(0);
    int i;
    int lim = ArSize();
    for(i = 0; i < lim ; i++ )
    	sum += arr[i];

	if(i > 0)
    	r = sum / T(i);
    else
    	cout << " No entries on score array " << endl;

	return r;
}

template <class T> T& tARRAY<T>::operator[](int i)
{
	if(i < 0 || i >= size)
    	{
        	cout << " Error in array limits :"
            	<< i << " is a bad index" << endl;
            exit(1);
        }
	return arr[i];
}

template <class T> const T& tARRAY<T>::operator[](int i)const
{
	if(i < 0 || i >= size)
    	{
        	cout << " Error in array limits :"
            	<< i << " is a bad index" << endl;
            exit(1);
        }
	return arr[i];
}

template <class T> tARRAY<T>& tARRAY<T>::operator=(const tARRAY<T>& a)
{
	if(this != & a)
     {
	    delete [] arr;
	    size = a.size;
	    arr = new T[size];
	    for(int i = 0; i < size; i++)
	    	arr[i] = a.arr[i];
     }
	return *this;
}

template <class T> ostream & operator<<(ostream &os, const tARRAY<T>& a)
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

#endif
