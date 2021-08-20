#include "cPARSE.h"

cPARSE::cPARSE(char* msg) 
{
    parse(msg);
}

cPARSE::cPARSE(string msg)
{
    parse(msg.c_str() );
}

void cPARSE::parse(const char* msg)
{
    int len = 10 + strlen(msg);
    char *p = new char[len];
    strcpy(p, msg);
    strcat(p,"\n");

    char* t = strtok(p,",\n");
    if(t)
      {
        command = t;
        t = strtok(NULL,",\n");
      } 
    if(t)
       {
        subcommand = t;
        t = strtok(NULL,",\n");
       } 
    if(t)
        data = t;

    delete[] p;
}