// gppf.cpp
#ifndef __WINDOWS_H
#define STRICT
#include <windows.h>
#endif

#ifndef __MATH_H
#include <math.h>
#endif

double GetPrivateProfileFloat(char* section, char* key, char* ini)
{
	char tmp[25];
    GetPrivateProfileString(LPSTR(section) ,LPSTR(key),"0.0",LPSTR(tmp),25,LPSTR(ini));
    return atof(tmp);
}
