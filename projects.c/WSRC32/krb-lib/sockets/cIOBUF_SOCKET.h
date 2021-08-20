// cCLIENT_SOCKET.H

#include "cIOBUF.h"
#include "cWINSOCK.h"


#ifndef __cIOBUF_SOCKET_H
#define __cIOBUF_SOCKET_H


class cIOBUF_SOCKET
{
    private:
        cSOCKET connection;
        int     active;

    public:
        cIOBUF_SOCKET()  : active(0) {} 
        ~cIOBUF_SOCKET() { active = 0;}

        int hasData()   { return connection.isReady(); }

        void set(cSOCKET& s)
         {
                           
         }

        int Recv(cIOBUF& b) 
         { 
            if(active) 
             b.Recv(connection); 

            return 0;
         }

         int Send(cIOBUF& b)
          {
            int status = -1;
            if(active && b.get() )
                status = b.Send(connection);
            return status;
          }

        int isActive()      { return active; }

};

#endif
