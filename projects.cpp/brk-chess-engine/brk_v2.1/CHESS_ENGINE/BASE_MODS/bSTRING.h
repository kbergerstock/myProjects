
#include "stdwin.h"

#ifndef __bSTRING_H
#define __bSTRING_H

class bSTRING
{
    private:
        int     isize;
        char*   string;    

    public:
        bSTRING() : isize(0),string(0) {}
        bSTRING(int);
        bSTRING(char*s) : isize(0),string(0) { copy(s); }
        virtual ~bSTRING();

        operator char*() { return string;}

        bool    operator==(const bSTRING&);
        char&   operator[](int idx);

        void    clear();
        void    resize(int);

        char*   copy(const char*);
        char*   copyn(const char*,int);
        char*   copy(const bSTRING&);

        char*   add(char);

        char    at(int);
        void    at(int,char);

        int     length()        { return lstrlen(string);}
        int     size()          { return isize; }
};

#endif