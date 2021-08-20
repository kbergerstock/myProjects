//*******************************************************************
//              
//  FILE:       aPIPE_BUF.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    pipeTest
//              
//  COMPONENT:  - aPIPE_BUF
//              
//  DATE:       16.03.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

// Includes

#ifndef __tPIPE_BUF_H
#define __tPIPE_BUF_H

const int IPCBUFSIZE = 1024;

template <class T> class tPIPE_BUF
{
    protected:
        T _ipc[IPCBUFSIZE];

    public:
        tPIPE_BUF() { _ipc[0] = 0; _ipc[1] = 0;}                    // default constructor

        tPIPE_BUF(const tPIPE_BUF<T>& );                            // copy constructor

        ~tPIPE_BUF() {}                                             // destructor                    

        T&   operator  *() { return *_ipc;}                         // reference operator

        operator T*() { return _ipc;}                               // name operator

        T& operator[](int);                                         // index access

        const T& operator[](int)const;                              // const index access

        tPIPE_BUF<T>& operator=(const tPIPE_BUF<T>& );              // operator assignment
};

template <class T> tPIPE_BUF<T>::tPIPE_BUF(const tPIPE_BUF<T>& p)
{
    for(int i = 0; i < IPCBUFSIZE; i++) _ipc[i] = p._ipc[i];
}


template <class T> T& tPIPE_BUF<T>::operator[](int i)
{
    if(i < 0 || i >= IPCBUFSIZE)
        throw "IPC ARRAY VIOLATION";
    return _ipc[i];
}

template <class T> const T& tPIPE_BUF<T>::operator[](int i)const
{
    if(i < 0 || i >= IPCBUFSIZE)
        throw "IPC ARRAY VIOLATION";
    return _ipc[i];
}

template <class T>  tPIPE_BUF<T>& tPIPE_BUF<T>::operator=(const tPIPE_BUF<T>& p)
{
    for(int i = 0; i < IPCBUFSIZE; i++) _ipc[i] = p._ipc[i];
    return *this;
}

typedef tPIPE_BUF<char> aPIPE_BUF;

#endif