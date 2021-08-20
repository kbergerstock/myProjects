// cCLIENT_SOCKET.H

#include "cWINSOCK.h"

#ifndef __cCLIENT_SOCKET_H
#define __cCLIENT_SOCKET_H

class cCLIENT_SOCKET;



class cCLIENT_SOCKET
{
    private:
        cSOCKETADDRESS sa;
        cSOCKET connection;
        int fc;

    public:
        cCLIENT_SOCKET(cWINSOCK&);
        cCLIENT_SOCKET(cWINSOCK&,char*);
        ~cCLIENT_SOCKET();

        int Connect()   { return connection.Connect(sa); }
        int Reconnect() { return connection.Reconnect(sa); }
        int Close()     { return connection.Close(); }
        int hasData()   { return connection.isReady(); }

        // text read - writes
        int Write(char *);
        int Read(char*,int);

        operator cSOCKET*() { return &connection; }

};

#endif
