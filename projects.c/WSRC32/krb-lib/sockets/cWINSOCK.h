// winsock class to encapsulate the winsoc api
#define WIN32_LEAN_AND_MEAN

#include <winsock2.h>

#ifndef __cWINSOCK_H
#define __cWINSOCK_H

enum wsVERSIONS
{
    WS11 = 0x101,
    WS22 = 0x202,
};

#define DEFAULT_PROTO SOCK_STREAM
#define DEFAULT_PORT 5001
#define iMAXBUF 512

class cSOCKETADDRESS;
class cSOCKET;
class cSERVER_FDS;

class cSOCKET_ERR
{
    private:
        char buf[512];
        cSOCKET_ERR();

    public:
        cSOCKET_ERR(const char* );
        cSOCKET_ERR(const char* ,const char*);
        char* get() { return buf; }
};

class cWINSOCK
{
    private:
        int status;
        WSAData wsaData;

    public:
     cWINSOCK(int);
    ~cWINSOCK();
     int getHost(const char* hn, int port , cSOCKETADDRESS&);
     int getServerAddress(int port, cSOCKETADDRESS& sa);

     int getStatus() { return status; }   

     void Throw(char*);

};

class cSOCKETADDRESS
{
    private:
        struct sockaddr_in socket_address;

        friend class cWINSOCK;
        friend class cSOCKET;
        
    public:
        cSOCKETADDRESS() { }
       ~cSOCKETADDRESS()  { }

        operator struct sockaddr_in() { return socket_address; }

        operator struct sockaddr_in*() { return &socket_address; }
};



class cSOCKET
{
    protected:
        // the socket connection
        SOCKET    _connection;
        // server connection place holders
        struct sockaddr_in from;
        int fromlen;

    public:
        cSOCKET() {}
        ~cSOCKET(){}
        
        cSOCKET(SOCKET socket)  { _connection = socket; }
        cSOCKET(cSOCKET& c)
          {
            _connection = c._connection;
          }

        int Open();
        int Close();
        int Reconnect(cSOCKETADDRESS&);
        int Connect(cSOCKETADDRESS&);        

        int Send(char*, int);
        int Recv(char*, int);

        // routine to determine how much data is available to be read
        int isReady();

        // server functions
        int Bind(cSOCKETADDRESS&);
        int Listen();
        int Accept(cSOCKET&);

        // non blocking functions
        int setNonBlocking();
        int setBlocking();

        int Select(cSERVER_FDS&,DWORD ms);

        char *  getFromAddress()    { return inet_ntoa(from.sin_addr); }
        int     getFromPort()       { return htons(from.sin_port); }

        operator SOCKET()           { return _connection; }
        operator = (SOCKET socket)  { _connection = socket; }
};

class cSERVER_FDS 
{
    private:
        fd_set read_fds;
        fd_set write_fds;
        fd_set except_fds;
        
        friend class cSOCKET;           

    public:    

    class cSERVER_FDS()
       {
            Zero();
       }

    void Set(SOCKET socket)
     {
        FD_SET(socket,&read_fds);
        FD_SET(socket,&write_fds);
        FD_SET(socket,&except_fds);
     }

    void Clr(SOCKET socket)
     {
        FD_CLR(socket,&read_fds);
        FD_CLR(socket,&write_fds);
        FD_CLR(socket,&except_fds);
     }

    void Zero()
       {
            FD_ZERO(&read_fds);
            FD_ZERO(&write_fds);
            FD_ZERO(&except_fds);
       }

    int isReadSet(SOCKET socket)
      {
        return FD_ISSET(socket,&read_fds);
      }

    int isWriteSet(SOCKET socket)
      {
        return FD_ISSET(socket,&write_fds);
      }

    int isExceptSet(SOCKET socketi)
      {
        return FD_ISSET(socket,&write_fds);
      }
};

#endif

