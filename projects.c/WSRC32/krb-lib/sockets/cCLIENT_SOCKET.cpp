#include "cCLIENT_SOCKET.H"
#include <iostream>
using namespace std;

cCLIENT_SOCKET::cCLIENT_SOCKET(cWINSOCK& ws) 
{
        // get the address of the server           
        ws.getHost("LocalHost",DEFAULT_PORT,sa);
        // open the socket
        connection.Open();
        // connect to the server
        fc = Connect() == 0 ? 1 : 0;
}

cCLIENT_SOCKET::cCLIENT_SOCKET(cWINSOCK& ws, char* hostName)
{
        // get the address of the server           
        ws.getHost(hostName,DEFAULT_PORT,sa);
        // open the socket
        connection.Open();
        // connect to the server
        fc = Connect() == 0 ? 1 : 0;
}

cCLIENT_SOCKET::~cCLIENT_SOCKET()
{
    connection.Close();
    fc = 0;
}

int cCLIENT_SOCKET::Write(char* buf)
{
    int status = 0;
    if( fc )
     {
        cout << " sending data   : " << buf << endl;
        int len = 1 + strlen(buf);
        status = connection.Send(buf,len);
      }
    return status;
}

int cCLIENT_SOCKET::Read(char* buf,int len)
{
    int status = 0;

    if(fc)
     {
        cout << " recieving data : ";
        status = connection.Recv(buf,len);
        if(status > 0)
          {
            cout << buf << endl;
            buf[status] = '\0';
          }
        else    
            fc = 0;
      }

    return status;
}

