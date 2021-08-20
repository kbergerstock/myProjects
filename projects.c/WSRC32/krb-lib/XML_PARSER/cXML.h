//*******************************************************************
//              
//  FILE:       cXML.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    cXML
//              
//  COMPONENT:  - class wrapper for expat
//              
//  DATE:       10.12.2003
//              
//  COMMENTS:   - to be uses as a base class for xml handlers
//              
//              
//*******************************************************************

// Includes
#include "xmlparse.h"

#ifndef __cXML_H
#define __cXML_H

class cXML
{
    private:
    cXML(const cXML&) {};
            
    protected:

    XML_Parser p;

    /*
        Call from within a handler to print the currently recognized
        document fragment. Temporarily set the default handler and then
        invoke it via the the XML_DefaultCurrent call.
    */
    void printcurrent(); 
    void setDefaultHandler();

    // handler functions
    virtual void default_handler(const char *s, int len){};
    virtual void start_handler(const char *el, const char **attr){};
    virtual void end_handler(const char *el){}; 
    virtual void char_handler(const char *txt, int txtlen){};
    virtual void proc_handler(const char *target, const char *pidata){};

    // friend functions   
    friend void default_handler(void *, const char *s, int len);
    friend void start_handler(void *, const char *el, const char **attr); 
    friend void end_handler(void *, const char *el);
    friend void char_handler(void *, const char *txt, int txtlen);
    friend void proc_handler(void *, const char *target, const char *pidata);
         
    public:

    cXML();

    virtual ~cXML();

    int     getCurrentLineNumber()      { return XML_GetCurrentLineNumber(p); }
    const char*	getXMLerrorString()     { return XML_ErrorString(XML_GetErrorCode(p)); } 

    

    int  parse( const char *s, int len, int isFinal)
     {
        return  XML_Parse(p, s, len, isFinal);
     }

};
#endif