#include "cWINSOCK.h"

#ifndef __cIOBUF_H
#define __cIOBUF_H

enum
{
    // commands
    IO_END = 1000,              // end a connection    
    IO_START,                   // start test
    IO_STOP,                    // stop / abort test
    IO_ACK,
    IO_NAK,
    IO_PING,                    // ping a connection
    IO_CONNECTED,                   
    IO_CHANGE_OVER,             // part / test sequence  change over occured
    IO_PRINT,                   // print command - format data into laser file
    IO_LINK,                    // link update
        
    // responses
    IO_COMPLETE = 2000,         // test complete
    IO_STEP_COMPLETE,           // test step complete / updated
    IO_PRINT_COMPLETE,          // print file has been written


    // user defined
    IO_USER = 3000,
};

enum
{
    IOBUF_SIZE = 128,
    IO_DATA_SIZE = 5006,
};


template <class TYPE> class tIOBUF
{
    private:
        int     size;
        int     len;
        int     sendFlag;
        int     rcvFlag;
        TYPE*   buf;

    public:
        tIOBUF();
       ~tIOBUF();
        tIOBUF(tIOBUF&);
        void resize(int);
        int  Send(cSOCKET&);
        int  Recv(cSOCKET&);

        void clear()    { rcvFlag = 0; sendFlag = 0; }
        int  process()  { return rcvFlag; }

        void set() { sendFlag = 1; }
        int  get() { return sendFlag; }

		TYPE&   operator  *() { return *buf;}
        operator TYPE*() { return buf;}

        TYPE& operator[](int i)
            {
                i = (i < 0 || i > size) ? 0 : i;
                return buf[i];
            }
        const TYPE& operator[](int i)const
            {
                i = (i < 0 || i > size) ? 0 : i;
                return buf[i];
            }

        void copy(tIOBUF& );

};

template <class TYPE> tIOBUF<TYPE>::tIOBUF()
{
    size = IOBUF_SIZE;
    len = 0;
    sendFlag = 0;
    rcvFlag = 0;
    buf = new TYPE[size+1];
}

template <class TYPE> tIOBUF<TYPE>::~tIOBUF()
{
    delete[] buf;
}

template <class TYPE> void tIOBUF<TYPE>::resize(int _size)
{
    size = _size;
    delete[] buf;
    buf = new TYPE[size+1];
}

template <class TYPE> tIOBUF<TYPE>::tIOBUF(tIOBUF& b)
{
    if(size != b.size)
      resize(b.size);

    for(int i = 0; i < size; i++)
        buf[i] = b.buf[i];

    len = b.len;
    sendFlag = b.sendFlag;
    rcvFlag =  b.rcvFlag;
}

template <class TYPE> void tIOBUF<TYPE>::copy(tIOBUF& b)
{
    if(size != b.size)
      resize(b.size);

    for(int i = 0; i < size; i++)
        buf[i] = b.buf[i];

    len = b.len;
    sendFlag = b.sendFlag;
    rcvFlag =  b.rcvFlag;
}

template <class TYPE> tIOBUF<TYPE>::Send(cSOCKET& socket)
{
    int l = sizeof(TYPE) * size;
    char *d = (char*)(buf);
    sendFlag = 0;
    rcvFlag = 0;
    return socket.Send(d,l);
}

template <class TYPE> tIOBUF<TYPE>::Recv(cSOCKET& socket)
{
    int l = sizeof(TYPE) * size;
    char *d = (char*)(buf);
    len = socket.Recv(d,l);
    sendFlag = 0;
    rcvFlag  = 1;
    return len;
}

typedef tIOBUF<int> cIOBUF;
#endif
