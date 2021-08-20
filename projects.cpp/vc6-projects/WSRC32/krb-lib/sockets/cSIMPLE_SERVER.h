// simple server 
// ie one connection server
// useful for test applications

#include "cSERVER_SOCKET.h"
#include <string>
using namespace std;

#ifndef __cSIMPLE_SERVER_H
#define __cSIMPLE_SERVER_H

class cSIMPLE_SERVER
{
    private:
        cWINSOCK ws;
        cSOCKETADDRESS local;
        cSOCKET listen;
        cTEXT_SERVER_SOCKET server;

        int processCommands(char *);
        int saveData(string,string);

        int run_flag;


    public:
        cSIMPLE_SERVER();
        ~cSIMPLE_SERVER();

        void run();

        int Listen();
        int Accept();
        int Read();
        int Write();

        operator cSOCKET*() { return &server; }
};

#endif
