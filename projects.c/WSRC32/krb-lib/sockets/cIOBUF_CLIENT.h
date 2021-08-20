// cCLIENT_SOCKET.H

#include "cIOBUF.h"
#include "cWINSOCK.h"


#ifndef __cIOBUF_CLIENT_H
#define __cIOBUF_CLIENT_H


class cIOBUF_CLIENT
{
    private:
        cSOCKETADDRESS sa;
        cSOCKET connection;
        int fc;

    public:
        cIOBUF_CLIENT()  { fc = 0; } 
        ~cIOBUF_CLIENT() { if(fc) Close(); }

        int Open(cWINSOCK& ws, const char*);
        int Open(cWINSOCK& ws, const char*, int);
        int Close();
        int Sever();

        int Connect()   { return connection.Connect(sa); }
        int Reconnect() { return connection.Reconnect(sa); }
        int hasData()   { return connection.isReady(); }

        int Recv(cIOBUF& b); 
        int Send(cIOBUF& b);
 

        operator cSOCKET*() { return &connection; }

        int isActive()      { return fc; }

};

#endif
