// cSERVER.H

#include "cWINSOCK.H"
#include "cSERVER_SOCKET.h"
#include <string>
using namespace std;

#ifndef __cSERVER_H
#define __cSERVER_H

class cSERVER
{
    private:
        cSOCKETADDRESS local;
        cSOCKET listen;
        cSERVER_FDS fds;

        pSOCKETS socket_list;
        int      num_sockets;

        int processCommands(char *);
        int saveData(string,string);

        int Accept();
        int Read(int);
        int Write(int);

        void set_fds();

    public:
        cSERVER(cWINSOCK&);
        ~cSERVER();

        void run();
};
#endif