// simple server 
// ie one connection server
// useful for test applications

#include "cWINSOCK.h"
#include "cIOBUF.h"

#ifndef __cIOBUF_SERVER_H
#define __cIOBUF_SERVER_H

class cIOBUF_SERVER
{
    private:
        cWINSOCK ws;
        cSOCKETADDRESS local;
        cSOCKET listen;
        cSOCKET server;
        int port;

        int Listen();
        int Accept();

        int active;

    public:
        cIOBUF_SERVER();
        cIOBUF_SERVER(int port);
        virtual ~cIOBUF_SERVER();
    
        void start();
        void run(cIOBUF& input, cIOBUF& output);

        void close_connection() { active = 0; server.Close(); }

        int isActive()          { return active; }   
        
        operator cSOCKET*()     { return &server; }
};

#endif
