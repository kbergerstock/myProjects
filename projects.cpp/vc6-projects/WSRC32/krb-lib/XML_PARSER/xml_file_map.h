//*******************************************************************
//              
//  FILE:       xml_file_map.h
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    xml_map
//              
//  COMPONENT:  -
//              
//  DATE:       14.01.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************

#pragma warning (disable : 4786)
// Includes

#include "cXML.h"               // xml base class

#include <string>
#include <vector>
#include <map>
using namespace std;

#ifndef __XML_FILE_MAP_H
#define __XML_FILE_MAP_H

class XML_data
{
    private:
        struct XML_TAG
         {
            int     line;       // reference to data line that value is stored at
            string  tag;        // tag descriptor of value
            string  value;      // the value of the tag 
         };

        // key to values implemented as a mapping
        typedef map<string,XML_TAG>  XML_TAG_MAP;    
        typedef XML_TAG_MAP::value_type XML_TAG_VALUE;
        typedef XML_TAG_MAP::iterator   XML_TAG_ITOR;

        // the storage space for the mapping of keys to values 
        XML_TAG_MAP    key_map;
        // the storage space of the raw data in the file
        vector<string>  xml_data; 
        // the curent line || total lines of the file
        int line_number;

    public:
        XML_data() : line_number(-1) {};
        ~XML_data() {};

        // insert a key value into mapping
        void insert(string& key, string& current_tag, string & value)  
         { 
            XML_TAG data;
            data.line  = line_number;
            data.tag   = current_tag;
            data.value = value; 
            key_map.insert(XML_TAG_VALUE(key,data) ); 
         }              

        void addLine(string& line)
         {
            line_number++;
            xml_data.push_back(line);
         }

        // clear the map and the data
        void clear() 
         {  
            line_number = -1;
            key_map.clear(); 
            xml_data.clear();
         }                

        // fetch the value for a key    
        string find_key(char*);
        string find_key(string&);
        // replace the value for a key
        void replace(string& key, string& v);
        void replace(string& key, int v);
        void replace(string& key, double v);

        void dump_map();
        void dump_file();

        void write(const string& fn);
};


class XML_file_map : public cXML
{
    protected:
   
        int nest;
        string  current_tag;    
        vector<string> keys;

        // the mapping of keys to values    
        XML_data&    key_map; 
    
        // handler functions
        // void default_handler(const char *s, int len);
    
        void start_handler(const char *el, const char **attr);

        void end_handler(const char *el);

        void char_handler(const char *txt, int txtlen);

        // void proc_handler(const char *target, const char *pidata);

    public:
        XML_file_map(XML_data&);
        ~XML_file_map();

        int  parse(string &s, int done);
        void parseFile(const string& fn);
};

#endif