#include "bSTRING.h"

bSTRING::bSTRING(int size) : isize(0),string(0)
{
    resize(size);
}

bSTRING::~bSTRING()
{
    if(string)
        delete[] string;
}

void bSTRING::resize(int size)
{
    // delete the old contents
    if(string)
        delete[] string;

    isize = size;
    // create the new storage space
    string = new char[isize+1];
    // set the end point to be null terminated
    string[size] = 0;
}


char* bSTRING::copy(const char* s)
{
    int len = lstrlen(s);
    if(len > isize)
        resize(len+1);

    return lstrcpy(string,s);
}

char* bSTRING::copyn(const char* s,int len)
{
    if(len > isize)
        resize(len+1);

    return lstrcpyn(string,s,len);
}

char* bSTRING::copy(const bSTRING& s)
{
    if(s.isize > isize)
        resize(s.isize+1);

    return lstrcpy(string,s.string);
}


char* bSTRING::add(char a)
{
    int idx = lstrlen(string);
    if( idx+2 > isize)
     {        
        isize += 10;
        char *t = string;
        string = new char[isize+1];
        lstrcpy(string,t);
        delete[] t;
     }

    string[idx] = a;
    string[idx+1] = 0;

    return string;
}

char bSTRING::at(int idx)
{
    char r = 0;

    if(idx < isize)
        r = string[idx];

    return r;
}

void bSTRING::at(int idx, char a)
{
    if(idx < isize)
        string[idx] = a;    
}

bool bSTRING::operator==(const bSTRING& s)
{
    int r = lstrcmp(string,s.string);

    return r == 0 ? true : false;
}

char& bSTRING::operator[](int idx)
{
    if(idx >= isize)
     {        
        isize = idx + 10;
        char *t = string;
        string = new char[isize+1];
        lstrcpy(string,t);
        delete[] t;
     }

	return string[idx];
}

void bSTRING::clear()
{
    isize = 0;
    if(string)
        delete[] string;
}