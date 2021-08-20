#include "cIOBUF_CLIENT.H"
#include "ods.h"
#include <iostream>
using namespace std;

int cIOBUF_CLIENT::Open(cWINSOCK& ws, const char* hostName)
{
        // get the address of the server           
        ws.getHost(hostName,DEFAULT_PORT,sa);
        // open the socket
        connection.Open();
        // connect to the server
        fc = Connect() == 0 ? 1 : 0;

        return fc;
}

int cIOBUF_CLIENT::Open(cWINSOCK& ws, const char* hostName, int port)
{
        // get the address of the server           
        ws.getHost(hostName,port,sa);
        // open the socket
        connection.Open();
        // connect to the server
        fc = Connect() == 0 ? 1 : 0;

        return fc;
}

int cIOBUF_CLIENT::Close()
{
    cIOBUF cmd;
    cmd[0] = IO_END;
    cmd.Send(connection);
    connection.Close();
    outputDebugString("Connection Closed\n");
    fc = 0;
    return fc;
}


int cIOBUF_CLIENT::Sever()
{
    connection.Close();
    outputDebugString("Connection Closed\n");
    fc = 0;
    return fc;
}

int cIOBUF_CLIENT::Recv(cIOBUF& b) 
{ 
    if(fc) 
     b.Recv(connection); 
    #if 1
        cout << "packet recieved" << endl;
    #endif    
    return 0;
}

 int cIOBUF_CLIENT::Send(cIOBUF& b)
{
    int status = -1;
    if(fc && b.get() )
        status = b.Send(connection);
    #if 1
        cout << "packet sent" << endl;
    #endif
    return status;
}