/*
    filename.h
    K. R. Bergerstock                   @ 11/24/92

    class to handle full file path names

*/

#include <dir.h>

#ifndef  FNAME_H
#define  FNAME_H

class cFileName                                 // class to control file name
  {                                             // creation that matches
    private:                                    // dos requirements
      char path[MAXPATH];

      char drv[MAXDRIVE];
      char dir[MAXDIR];
      char name[MAXFILE];
      char ext[MAXEXT];

	  int isfchar( char );						

    public:
      cFileName();
      cFileName(char *source);
      cFileName(const cFileName &);

      char* operator() (void) { return GetFullName(); }
      
      void SetSource(char *source );
      void SetName(char *s );
      void SetExt(char *s );
      void SetDir(char *s );
      void SetDrv(char *s );

      char * GetName(void)  { return name; };
      char * GetExt(void)   { return ext;  };
      char * GetDir(void)   { return dir; };
      char * GetDrv(void)   { return drv; };

      char * GetFullName(void);
      char * GetCurrentDir(char *s);
  } ;

#endif



