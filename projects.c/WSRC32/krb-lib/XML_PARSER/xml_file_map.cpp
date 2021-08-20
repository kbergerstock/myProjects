//*******************************************************************
//              
//  FILE:       xml_file_map.cpp
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

#pragma warning(disable:4786)

// Includes
#include <fstream>
#include <iostream>
#include <iomanip>
#include <strstream>
#include "xml_file_map.h"


void XML_data::write(const string& fn)
{
    fstream xml_out;            

    xml_out.open(fn.c_str(),ios_base::out);

	if(xml_out.is_open() )
	{
        cout << "writing xml file " << fn << endl;

        vector<string>::iterator p;
        for(p = xml_data.begin(); p != xml_data.end(); p++)
            xml_out << *p << endl;

		xml_out.close();
	}
	else
		cout << " err in opening file " << endl;
}


void XML_data::dump_map()
{
    XML_TAG_ITOR p ;
    for( p = key_map.begin(); p != key_map.end(); p++)
     {
        cout << " key : " << setw(50) << p->first << " value :  " << p->second.value << endl;
     }
}

void XML_data::dump_file()
{
    vector<string>::iterator p;
    for(p = xml_data.begin(); p != xml_data.end(); p++)
        cout << *p << endl;
}

string XML_data::find_key(string& key)
{
    string r("empty");

    XML_TAG_ITOR p = key_map.find(key);

    if(p != key_map.end() )
        r = p->second.value;
   
    return r;     
}

string XML_data::find_key(char* ks)
{
    string key(ks);
    return find_key(key);
}

void XML_data::replace(string& key, string& v)
{
    // find the location of the key
    XML_TAG_ITOR p = key_map.find(key);
    // if found
    if(p != key_map.end() )
      {
        // replace the internal storage
        p->second.value = v;
        string ov = xml_data[p->second.line];
        ov.erase(ov.find('<'),ov.size() );
        // form the new tag value line entry
        string ne =  "<" + p->second.tag + ">" + v + "</" + p->second.tag + ">";
        // replace the line
        xml_data[p->second.line] = ov+ne;
      }
}

void XML_data::replace(string& key, int v)
{
    // find the location of the key
    XML_TAG_ITOR p = key_map.find(key);
    // if found
    if(p != key_map.end() )
      {
        char buffer[50];
        string ov = xml_data[p->second.line];
        if(ov.find('x') != ov.npos || ov.find('X') != ov.npos)
            sprintf(buffer,"0x%0x",v);
        else
            sprintf(buffer,"%d",v);            

        replace(key,string(buffer) );
      }
}

void XML_data::replace(string& key, double v)
{
    char buffer[50];
    sprintf(buffer,"%12.5f",v);
    replace(key,string(buffer) );
}

/* ---------------------------------------------------------------------------- */

XML_file_map::XML_file_map(XML_data& _map) : cXML(), key_map(_map)
{
    nest = 0;
}

XML_file_map::~XML_file_map()
{
}

// this handle is called for a start tag
void XML_file_map::start_handler(const char *el, const char **attr)
{
    string key(el);             // key == tag name
    keys.push_back(el);         // save it on the stack to form the total key name
    current_tag = el;           // save a copy of it
    nest++;                     // advance the tree level
}

// this function is called for an end tag
void XML_file_map::end_handler(const char *el)
{
    keys.pop_back();            // end tag found - remove it from the stack
    nest--;                     // decrease tree level
}

// this function is called for 
void XML_file_map::char_handler(const char *txt, int txtlen)
{
    // if a non white space is detected than process the string as if a value is found
    if(!isspace(*txt) )
     {
        // convert char string to string value
        string value(txt,txtlen);
        // form the map key buy summing all the nest level to get here
        // and ignoring the top level tag name
        string key;            
        for(int i = 1; i < nest; i++)
            key += keys[i];
        // add the map key and value to the data object
        key_map.insert(key,current_tag,value);
     }
}

int XML_file_map::parse(string &s, int done)
{
    // add the current line in the xml file to the data structure
    key_map.addLine(s);
    // parse the current xml line
    return cXML::parse(s.c_str(),s.size(),done);
}          

// parse the file
void XML_file_map::parseFile(const string& fn)
{
    fstream xml_in;            
    string inputLine;

    // clear the map ie the xml_data object
    key_map.clear();                    

    // open the file
    xml_in.open(fn.c_str(),ios_base::in);

    // process the lines in the file
	if(xml_in.is_open() )
	{
		do
		{
            getline(xml_in,inputLine);
            int done = xml_in.eof();
            parse(inputLine,done);

		}while(!xml_in.eof() );

		xml_in.close();
	}
	else
		throw ("err in opening file ");
}