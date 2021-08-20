// tarray.h
// template class representing an array
// k. r. bergerstock

#include <iostream>
using namespace std;

#ifndef __tarray_h
#define __tarray_h

static const char* _UNABLE_TO_ALLOCATE_MEMORY = "UNABLE_TO_ALLOCATE_MEMORY";
static const char* _MEMORY_ARRAY_EXCEEDED     = "MEMORY_ARRAY_EXCEEDED";

template <class T> class tARRAY
{
	private:
        int _ref;
    	int _size;
        T*  _arr;

	public:
    	tARRAY();
        tARRAY(unsigned int n );
        tARRAY(const tARRAY<T>* a);
        tARRAY(const tARRAY<T> &a);
        tARRAY(const T* a, int n);
        virtual ~tARRAY();

		T&   operator  *() {return *_arr;}
        operator T*() {return _arr;}
    	int  operator  !() const {return _arr==0;}

        unsigned int Size() const { return _size; }
        void size(int n);  
        void resize(int n);
        void assign(T* a, int n);
        void unasign() { _ref = 1, _size = 0; _arr = 0; }

        virtual T& operator[](int i);
        virtual const T& operator[](int i)const;
        tARRAY<T>& operator=(const tARRAY<T>& a);

        friend ostream & operator<<(ostream &os, const tARRAY<T>& a);

};

template <class T> tARRAY<T>::tARRAY()
{
	_arr = 0;
    _size = 0;
    _ref = 1;
}

template <class T> tARRAY<T>::tARRAY(unsigned int n)
{
    _ref = 1;
	_size = n;
	_arr = new T[_size];
    if(_arr == 0)
    	throw _UNABLE_TO_ALLOCATE_MEMORY;
}

template <class T> tARRAY<T>::tARRAY(const tARRAY* a)
{
    _ref = 1;
	_size = a->_size;
	_arr = new T[_size];
    if(_arr == 0)
    	throw "UNABLE_TO_ALLOCATE_MEMORY";
    for(int i = 0; i < _size; i++ )
    	_arr[i] = a->_arr[i];
}

template <class T> tARRAY<T>::tARRAY(const tARRAY<T>& a)
{
    _ref = 1;
    _size = a._size;
    _arr = new T[_size];
    if(_arr == 0)
    	throw _UNABLE_TO_ALLOCATE_MEMORY;
    for (int i = 0; i < _size; i++)
    	_arr[i] = a._arr[i];
}

template <class T> tARRAY<T>::tARRAY(const T* a, int n)
{
    _ref = 0;
    _size = n;
    _arr = a;
}

template <class T> tARRAY<T>::~tARRAY()
{
    if(_ref)
        delete []_arr;
    _size = 0;
}

template <class T> void tARRAY<T>::assign(T* a, int n)
{
    if(_ref)
        delete[] _arr;

    _ref = 0;
    _arr = a;
    _size = n;
}

template <class T> void tARRAY<T>::size(int n)
{
    if(_ref && n > _size)
     {
        if(_size > 0)
            delete[]_arr;
            
        _size = n;
	    _arr = new T[_size];
	    if(_arr == 0)
	        throw _UNABLE_TO_ALLOCATE_MEMORY;
      }
}

template <class T> void tARRAY<T>::resize(int n)
{
    if(_ref)
     {
	    if(size == 0)
         {
		    _size = n;
		    _arr = new T[_size];
	        if(_arr == 0)
	    	    throw _UNABLE_TO_ALLOCATE_MEMORY;
         }
	    else if(n > _size)
         {
     	    tARRAY<T> t0(n);
            T* t1 =_arr;
            _arr = t0._arr;
            t0._arr = t1;
            for (int i = 0; i < _size; i++)
    	       _arr[i] = t0._arr[i];
            _size = n;
         }
    }
}

template <class T> T& tARRAY<T>::operator[](int i)
{
	if(i < 0 || ( i >= _size && _ref == 0) )
    	throw _MEMORY_ARRAY_EXCEEDED;
	else if(i >= _size)
      resize(i + 1000);
      
	return _arr[i];
}

template <class T> const T& tARRAY<T>::operator[](int i)const
{
	if(i < 0 || i >= _size)
    	throw _MEMORY_ARRAY_EXCEEDED;
	return _arr[i];
}

template <class T> tARRAY<T>& tARRAY<T>::operator=(const tARRAY<T>& a)
{
	if(_ref && this != & a)
     {
	    delete []_arr;
	    _size = a._size;
	    _arr = new T[_size];
	    if(_arr == 0)
    		throw _UNABLE_TO_ALLOCATE_MEMORY;
	    for(int i = 0; i < _size; i++)
	    	_arr[i] = a._arr[i];
     }
	return *this;
}


template <class T> ostream & operator<<(ostream &os, const tARRAY<T>& a)
{
    int i;
    for(i = 0; i < a._size; i++)
     {
        os << a._arr[i] << " " ;
        if( i % 5 == 4)
            os << endl;
     }

    if(i % 5 != 0)
        os << endl;

   return os;
}

#endif
