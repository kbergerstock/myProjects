//*******************************************************************
//              
//  FILE:       XML_subkey.cpp
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

#include "XML_subkey.h"

string XML_subkey::find_key(const char *k1, const char* k2, const char* k3)
{
    string key(subkey);
    key += k1;
    key += k2;
    key += k3;

    return xml.find_key(key);
} 

string XML_subkey::get_string_value(const char *k1, const char *k2, const char *k3, const char *dv)
{
    string df(dv);
    string r = find_key(k1,k2,k3);

    return (r == "empty") ? df : r;
}

int  XML_subkey::get_int_value(int df, const char *k1, const char *k2, const char *k3)
{
    string s = find_key(k1,k2,k3);

    int r = df;

    if(s != "empty")
        if(s.find('x') != s.npos || s.find('X') != s.npos)
            r = strtoul(s.c_str(),0,16);
        else
            r = strtoul(s.c_str(),0,10);

    return r;
}

double XML_subkey::get_double_value(double df, const char *k1, const char *k2, const char *k3)
{
    string s = find_key(k1,k2,k3);

    double r = df;

    if(s != "empty")
        r = atof(s.c_str() );

    return r;
}

void   XML_subkey::set_value(const char* k1, const char* k2, const char* k3, const char* new_value)
{
    // form the key
    string key(subkey);
    key += k1;
    key += k2;
    key += k3;

    // form the replacement string
    string ne(new_value);

    // replace the current value with the new value
    xml.replace(key,ne);
}

void   XML_subkey::set_value(const char* k1, const char* k2, const char* k3, int new_value)
{
    // form the key
    string key(subkey);
    key += k1;
    key += k2;
    key += k3;

    // replace the current value with the new value
    xml.replace(key,new_value);
}

void   XML_subkey::set_value(const char* k1, const char* k2, const char* k3, double new_value)
{
    // form the key
    string key(subkey);
    key += k1;
    key += k2;
    key += k3;

    // replace the current value with the new value
    xml.replace(key,new_value);
}