// cSERVER_SOCKET
#include "cWINSOCK.h"

#ifndef __cSERVER_SOCKET
#define __cSERVER_SOCKET

class cSERVER_SOCKET : public cSOCKET
{
    protected:
        int  active;

    public:
        cSERVER_SOCKET() : active(0){}

        int  Accept(cSOCKET& listen)
          {
            active = 1;
            int status = cSOCKET::Accept(listen);
            return status;
          }        


        int Close()
          {
            active = 0;
            return cSOCKET::Close();
          }

        int isActive() { return active; }

};



typedef cSERVER_SOCKET* pSOCKETS;

#endif