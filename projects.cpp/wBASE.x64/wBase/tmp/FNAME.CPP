/*
    filename.cpp
    K. R. Bergerstock                   @ 11/24/92

    class to handle full file path names

*/

#include "fname.h"
#include "string.h"

// char *strsub(char *s, char *pat, char *rep);


int cFileName::isfchar( char a)                 // this function verifies
  {                                             // that a specific char
  int valid;                                    // can be used in a file name

    switch (a)
       {
        case ('\n'):
        case (' '):
        case ('?'):
        case ('*'):
        case (';'):
        case (','):
        case ('.'):
        case ('\0'):
          valid = 0;
          break;
        default:
          valid = 1;
          break;
       }

  return valid;
  }


cFileName::cFileName()
{
	*path = '\0';                        /* init all parts to a null string */
	*drv  = '\0';
	*dir  = '\0';
	*name = '\0';
	*ext  = '\0';
}

cFileName::cFileName(char* source)
{
	*path = '\0';                // ensure all file descriptors
	*drv  = '\0';                // are null terminated
	*dir  = '\0';
	*name = '\0';
	*ext  = '\0';

	SetSource(source);           // init all file descriptors
}

cFileName::cFileName(const cFileName& S)
{
	strcpy(path,S.path);
	strcpy(drv,S.drv);
	strcpy(dir,S.dir);
	strcpy(name,S.name);
	strcpy(ext,S.ext);
}


void cFileName::SetSource(char *source )
{
	fnsplit(source,drv,dir,name,ext);
}

void cFileName::SetName(char *s )
{
	char *t = name;
	while( isfchar(*s) ) *t++ = *s++ ;
	*t = '\0';
}

void cFileName::SetExt(char *s )
{
	char *t = ext;
	while( isfchar(*s) ) *t++ = *s++ ;
	*t = '\0';
}

void cFileName::SetDrv(char *s )
{
	char *t = drv;
	while( isfchar(*s) ) *t++ = *s++ ;
	*t = '\0';
}


void cFileName::SetDir(char *s )
{
	char *t = dir;
	while( isfchar(*s) ) *t++ = *s++ ;
	*t = '\0';
}


char * cFileName::GetFullName(void)
{
	fnmerge(path,drv,dir,name,ext);
	return path;
}
char * cFileName::GetCurrentDir(char *s)
{
	getcwd(path,MAXPATH-21);
    strcat(path,"\\");
    strcat(path,s);
    return path;
}
