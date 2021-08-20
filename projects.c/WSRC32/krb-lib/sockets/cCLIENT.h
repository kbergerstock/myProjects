// client class
#include <iostream>
using namespace std;

#include "cCLIENT_SOCKET.h"

#ifndef __cSIMPLE_CLIENT
#define __cSIMPLE_CLIENT

class cSIMPLE_CLIENT 
{

    private:
        // connect to the socket services
        cWINSOCK ws;
        // client socket
        cCLIENT_SOCKET client;

    public:
        cSIMPLE_CLIENT() : ws(WS22), client(ws)
         {
            if(ws.getStatus() == 0)
                cout << " connection to dll successful " << endl;
         }

        cSIMPLE_CLIENT(char *hostName) : ws(WS22), client(ws,hostName)
         {
            if(ws.getStatus() == 0)
                cout << " connection to dll successful " << endl;
         }

        int Connect()           { return client.Connect(); }
        int Reconnect()         { return client.Reconnect(); }
        int Close()             { return client.Close(); }
                    
        int Write(char* s)      { return client.Write(s); }
        int Read(char* s,int n) { return client.Read(s,n); }
    
};
#endif