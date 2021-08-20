#include "cWINSOCK.h"


cSOCKET_ERR::cSOCKET_ERR(const char* msg)
{
    wsprintf(buf,"%s : %d",msg, WSAGetLastError() );
}

cSOCKET_ERR::cSOCKET_ERR(const char* msg, const char *s)
{
    wsprintf(buf,"%s : [%s] : %d",msg,s, WSAGetLastError() );
}


cWINSOCK::cWINSOCK(int version)
{
    status = WSAStartup(version,&wsaData); 
    if(status == SOCKET_ERROR)
     {
        WSACleanup();
        throw(cSOCKET_ERR("WSAstartup error "));
     }
}

cWINSOCK::~cWINSOCK()
{
    WSACleanup();
}

int cWINSOCK::getHost(const char* ha, int port, cSOCKETADDRESS& sa)
{
    struct hostent *hp;
    if(isalpha(ha[0]) )           // requested address is a name
     {
        hp = gethostbyname(ha);  
     }
    else
     {
        unsigned int addr = inet_addr(ha);
        hp = gethostbyaddr((char*)&addr,4,AF_INET);
     }
    if(hp == NULL)
     {
        throw(cSOCKET_ERR("Cannot Resolve Address ",ha) );
     }
     // copy the resolved information into the sockaddr_in atructure
     memset(&sa.socket_address,0,sizeof(struct sockaddr_in) );
     memcpy(&(sa.socket_address.sin_addr),hp->h_addr,hp->h_length);
     sa.socket_address.sin_family = hp->h_addrtype;
     sa.socket_address.sin_port = htons(port);

    return status;
}

int cWINSOCK::getServerAddress(int port, cSOCKETADDRESS& sa)
{
    sa.socket_address.sin_family = AF_INET;
    sa.socket_address.sin_addr.s_addr = INADDR_ANY;
    sa.socket_address.sin_port = htons(port);
    return status;
}

/* -------------------------- cSOCKET ---------------------------------------*/

int cSOCKET::Open()
{
    _connection = socket(AF_INET,DEFAULT_PROTO,0);
        if( _connection < 1)
            throw(cSOCKET_ERR("error opening socket") );
    return _connection < 0 ? -1 : 0;
}

int cSOCKET::Close()
{
    int status = 0;
    if(_connection >= 0)
      status = closesocket(_connection);
    _connection = -1;
    return status;
}

 int cSOCKET::Connect(cSOCKETADDRESS& sa)
 {
    int status = connect(_connection,(struct sockaddr*)&sa.socket_address,sizeof(sa.socket_address) );
    if(status == SOCKET_ERROR)
     {
        throw(cSOCKET_ERR("connection error") );
     }  

    return status;
 }

 int cSOCKET::Reconnect(cSOCKETADDRESS&sa)
 {
    int status = Open();
    if(status == 0)
        status = Connect(sa);
    return status;
 }

int cSOCKET::Send(char* buf, int len)
{
    int status = send(_connection,buf,len,0);

    return status;
}

int cSOCKET::Recv(char* buf , int len)
{
    int status = recv(_connection,buf,len,0);
    if(status == SOCKET_ERROR)
        Close();
    return status;
}

int cSOCKET::Accept(cSOCKET& listen)
{
    fromlen = sizeof(from);
    _connection = accept(listen._connection,(struct sockaddr*)&from,&fromlen);
    if(_connection == INVALID_SOCKET)
        throw(cSOCKET_ERR("accept() error") );
    return 0;
}

// server socket functions
int cSOCKET::Bind(cSOCKETADDRESS& sa)
{
    int status = bind(_connection,(struct sockaddr*)&sa.socket_address,sizeof(sa.socket_address) );
    if(status == SOCKET_ERROR)
        throw(cSOCKET_ERR("bind() failed with error"));
    return status;
}

int cSOCKET::Listen()
{
    int status = listen(_connection,5);
    if(status == SOCKET_ERROR)
        throw(cSOCKET_ERR("listen() failed with error"));
    return status;
}

// non blocking functions
int cSOCKET::setNonBlocking()
{
    unsigned long ioctl_opt = 1;              // non zero option == non blocking mode
    // set the socket option
    int status = ioctlsocket(_connection,FIONBIO,&ioctl_opt);
    if(status == SOCKET_ERROR)
        throw(cSOCKET_ERR("ioctlsocket() failed with error " ) );

    return status;    
    
}

// non blocking functions
int cSOCKET::isReady()
{
    unsigned long ioctl_opt = 0;              
    // set the socket option
    int status = ioctlsocket(_connection,FIONREAD,&ioctl_opt);
    if(status == SOCKET_ERROR)
        throw(cSOCKET_ERR("ioctlsocket() failed with error " ) );

    return ioctl_opt;    
}


// non blocking functions
int cSOCKET::setBlocking()
{
    unsigned long ioctl_opt = 0;              // zero option == blocking mode
    // set the socket option
    int status = ioctlsocket(_connection,FIONBIO,&ioctl_opt);
    if(status == SOCKET_ERROR)
        throw(cSOCKET_ERR("ioctlsocket() failed with error " ) );

    return status;    
    
}

int cSOCKET::Select(cSERVER_FDS& fds, DWORD ms)
{

    TIMEVAL tvp;
    timerclear(&tvp);

    int status = select(0,&fds.read_fds,&fds.write_fds,&fds.except_fds,&tvp);
    if(status == SOCKET_ERROR)
        throw(cSOCKET_ERR("select() failed with error " ) );

    return status;
}

