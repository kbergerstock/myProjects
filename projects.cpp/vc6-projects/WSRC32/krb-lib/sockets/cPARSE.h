#include <string>
using namespace std;

#ifndef __CPARSE_H
#define __cPARSE_H

class cPARSE
{
    private:
        void parse(const char*);

    public:
        string command;
        string subcommand;
        string data;

    cPARSE(string msg);
    cPARSE(char *msg);
};

#endif