#include "cIOBUF_SERVER.H"
#include "ods.h"

#define ESC 27

cIOBUF_SERVER::cIOBUF_SERVER() : ws(WS22), active(0)
{
    if(ws.getStatus() == 0)
        outputDebugString(" connection to dll successful " );
   
    port = DEFAULT_PORT;
    // get the address of the server           
    ws.getServerAddress(port,local);
    // open the socket
    listen.Open();
    // now bind to local address
    listen.Bind(local);
}

cIOBUF_SERVER::cIOBUF_SERVER(int _port) : ws(WS22), active(0)
{
    if(ws.getStatus() == 0)
        outputDebugString(" connection to dll successful " );
   
    port = _port;
    // get the address of the server           
    ws.getServerAddress(port,local);
    // open the socket
    listen.Open();
    // now bind to local address
    listen.Bind(local);
}

cIOBUF_SERVER::~cIOBUF_SERVER()
{
    outputDebugString("terminating server\n");

    if(active)
     {
        cIOBUF iobuf;
        iobuf[0] = IO_END;
        iobuf.Send(server);
      }

    active = 0;

    server.Close();

    listen.Close();
}

int cIOBUF_SERVER::Listen()
{
    // set the connection to listening
    return listen.Listen();
}

int cIOBUF_SERVER::Accept()
{   
    server.Accept(listen);
    active = 1;
    char buf[128];
    wsprintf(buf,"Accepted connection from %s,%d\n",server.getFromAddress() ,server.getFromPort() );
    outputDebugString(buf);
    return 0;
}

void cIOBUF_SERVER::start()
{
    // set the connection to listening
    Listen();
    
    char buf[128];
    wsprintf(buf,"listening on port %d\n",port);
    outputDebugString(buf);

    // accept connection
    cIOBUF_SERVER::Accept();
}

void cIOBUF_SERVER::run(cIOBUF& input, cIOBUF& output )
{
    int status = 0;

    if(server.isReady() )
     {
        status = input.Recv(server);

        if(status <= 0)
            {
                outputDebugString("client closed connection");
                active = 0;         
            }
        #ifdef __DEBUG_ON__
        else
            {
                outputDebugString("Recieved data from client\n");
            }
        #endif
      }

    if( status == 0 && output.get() )
     {
        #ifdef __DEBUG_ON__
        outputDebugString("sending data to the client\n");
        #endif
        output.Send(server);
     }
}



