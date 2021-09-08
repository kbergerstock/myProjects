// tarray.h
// template class representing an array
// k. r. bergerstock

#include <iostream>
using namespace std;

#ifndef __tarray_h
#define __tarray_h

static const char* _UNABLE_TO_ALLOCATE_MEMORY = "UNABLE_TO_ALLOCATE_MEMORY";
static const char* _MEMORY_ARRAY_EXCEEDED     = "MEMORY_ARRAY_EXCEEDED";

typedef uint64_t IDX;

template <class T> class tARRAY
{
	private:
        int _ref;
    	IDX _size;
        T*  _arr;

        T* alloc(IDX n);

	public:
    	tARRAY():_arr(nullptr),_size(0),_ref(1){};
        tARRAY(IDX n );
        tARRAY(const tARRAY<T>* a);
        tARRAY(const tARRAY<T> &a);
        tARRAY(const T* a, IDX n);
        virtual ~tARRAY();

        IDX Size() const { return _size; }
        void setSize(IDX n);  
        void resize(IDX n);

        virtual T& operator[](IDX i);
        virtual T& operator[](int i);
        virtual const T& operator[](IDX i)const;
        virtual const T& operator[](int i)const;
        tARRAY<T>& operator=(const tARRAY<T>& a);

        friend ostream & operator<<(ostream &os, const tARRAY<T>& a);
};

template <class T> T* tARRAY<T>::alloc(IDX n)
{
    T* tmp = nullptr;
    try
    {
        tmp = new T[n];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        throw _UNABLE_TO_ALLOCATE_MEMORY;
    }
    return tmp;
}

template <class T> tARRAY<T>::tARRAY(IDX n):_arr(nullptr),_size(n),_ref(1)
{
    _arr = alloc(_size);
}

template <class T> tARRAY<T>::tARRAY(const tARRAY* a)
{
    _ref = 1;
    _size = a->_size;
    _arr = alloc(_size);
    for(IDX i = 0; i < _size; i++ )
        _arr[i] = a->_arr[i];

}

template <class T> tARRAY<T>::tARRAY(const tARRAY<T>& a)
{
    _ref = 1;
    _size = a._size;
    _arr = alloc(_size); 
    for (int i = 0; i < _size; i++)
        _arr[i] = a._arr[i];   
}

template <class T> tARRAY<T>::tARRAY(const T* a, IDX n)
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
    _arr = nullptr;
    _ref  = 0;
}

template <class T> void tARRAY<T>::setSize(IDX n)
{
    if ( _ref )
    {
        if( _size == 0)
        {
            _size = n;
	        _arr = alloc(n);
        }
        else if (n > _size)
            resize(n);
    }
}

template <class T> void tARRAY<T>::resize(IDX n)
{
    if(_ref)
     {
        if(_size == 0)
        {
        _size = n;
        _arr = alloc(n);
        }
        else if( n > _size)
        {
            T* tmp = _arr;
            _arr = alloc(n);
            for(IDX i = 0 ; i < _size; i++)
                _arr[i] = tmp[i];
            _size = n;
            delete[] tmp;   
        }
    }
}

template <class T> T& tARRAY<T>::operator[](IDX idx)
{
	if( idx >= _size && _ref == 0)
    	throw _MEMORY_ARRAY_EXCEEDED;
	else if(idx >= _size)
        resize(idx + 1000);
      
	return _arr[idx];
}

template <class T> const T& tARRAY<T>::operator[](IDX idx)const
{
	if( idx >= _size)
    	throw _MEMORY_ARRAY_EXCEEDED;
	return _arr[idx];
}

template <class T> T& tARRAY<T>::operator[](int idx)
{
	if( idx >= _size && _ref == 0) 
    	throw _MEMORY_ARRAY_EXCEEDED;
	else if(idx >= _size)
        resize(idx + 1000);
      
	return _arr[idx];
}

template <class T> const T& tARRAY<T>::operator[](int idx)const
{
	if( idx >= _size)
    	throw _MEMORY_ARRAY_EXCEEDED;
	return _arr[idx];
}

template <class T> ostream & operator<<(ostream &os, const tARRAY<T>& a)
{
    IDX l = a.Size();
    for(IDX i = 0; i < l; i++)
     {
        os << a[i] << " " ;
        if( i % 5 == 4)
            os << endl;
     }

    if(i % 5 != 0)
        os << endl;

   return os;
}

typedef tARRAY<short>   i16ARRAY;
typedef tARRAY<double>  f64ARRAY;

#endif
