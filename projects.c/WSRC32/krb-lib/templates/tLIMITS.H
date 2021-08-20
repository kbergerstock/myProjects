#ifndef __WINDOWS_H
    #ifndef STRICT
        #define STRICT
    #endif

    #define WIN32_LEAN_AND_MEAN
    
    #include <windows.h>
    #include <mmsystem.h>
#endif

#ifdef __BORLANDC__
#include <stdlib.h>
#endif

#ifdef _MSC_VER
#include <cstdlib>
#endif


#ifndef __tLIMITS_H
#define __tLIMITS_H

template <class T> class tLIMITS
{
	private:
    	T low;
        T high;

        void* ATOS()
        {
            if( sizeof(T) == 8)
                return atof;
            else
                return atoi;
        }

    public:
        tLIMITS() { low = high = 0; }
    	void Init(LPCSTR szSection, LPCSTR szENTRY, LPCSTR szINI);
        bool Compare(T);

        T getHigh() { return high; }
        T getLow()  { return low; }

        void init(T _high , T _low)
            {
                high = _high;
                low  = _low;
            }
};


template <class T> void tLIMITS<T>::Init(LPCSTR szSection,const LPCSTR szEntry,LPCSTR szINI)
{
	char szBuf[100];
    int l = strlen(szEntry) + 10;
    char *szKey = new char[l];
    // form a pointer to the proper conversion routine
    // assumes 8 == double
    // anything else == int
    T (*atos)(const char*);
    atos = reinterpret_cast<T(*)(const char*)>(ATOS());

    strcpy(szKey,szEntry);
    strcat(szKey,"_HIGH");
    GetPrivateProfileString(szSection,szKey,"0",szBuf,99,szINI);
    high = atos(szBuf);

    strcpy(szKey,szEntry);
    strcat(szKey,"_LOW");
    GetPrivateProfileString(szSection,szKey,"0",szBuf,99,szINI);
    low = atos(szBuf);

    delete [] szKey;
}

template <class T> bool tLIMITS<T>::Compare( T v)
{
	bool r = false;
    if(v >= low && v <= high)
    	r = true;
    return r;
}

#endif