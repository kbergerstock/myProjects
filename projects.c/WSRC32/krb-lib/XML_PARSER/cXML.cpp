//*******************************************************************
//              
//  FILE:       cXML.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    cXML
//              
//  COMPONENT:  - class wrapper for expat
//              
//  DATE:       10.12.2003
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************


// Includes
#include "cXML.h"

/* --- xml handlers ---------------------------------- */

void default_handler(void *class_data, const char *s, int len) 
{
  cXML* p = static_cast<cXML*>(class_data);
  if(p)
    p->default_handler(s,len);
}  

void start_handler(void *class_data, const char *el, const char **attr) 
{
  cXML* p = static_cast<cXML*>(class_data);
  if(p)
    p->start_handler(el,attr);
}  

void end_handler(void *class_data, const char *el) 
{
  cXML* p = static_cast<cXML*>(class_data);
  if(p)
    p->end_handler(el);
} 

void char_handler(void *class_data, const char *txt, int txtlen)
{
  cXML* p = static_cast<cXML*>(class_data);
  if(p)
    p->char_handler(txt,txtlen);
}

void proc_handler(void *class_data, const char *target, const char *pidata)
{
  cXML* p = static_cast<cXML*>(class_data);
  if(p)
    p->proc_handler(target,pidata);
} 

/* --------------------------------------------------- */


cXML::cXML()
{
    // create the parser
    p = XML_ParserCreate(0);
    if (! p)
        throw ("Couldn't allocate memory for parser\n");

    // set the user data to point to class        
    XML_SetUserData(p, this);

    // set up the handler functions
    XML_SetElementHandler(p, ::start_handler, ::end_handler);
    XML_SetCharacterDataHandler(p, ::char_handler);
    XML_SetProcessingInstructionHandler(p, ::proc_handler);
}


cXML::~cXML()
{
    XML_ParserFree(p);
}

void cXML::setDefaultHandler()
{
    XML_SetDefaultHandler(p, ::default_handler);
}

/*
 Call from within a handler to print the currently recognized
 document fragment. Temporarily set the default handler and then
 invoke it via the the XML_DefaultCurrent call.
*/
void  cXML::printcurrent() 
{
  XML_SetDefaultHandler(p, ::default_handler);
  XML_DefaultCurrent(p);
  XML_SetDefaultHandler(p, (XML_DefaultHandler) 0);
}  