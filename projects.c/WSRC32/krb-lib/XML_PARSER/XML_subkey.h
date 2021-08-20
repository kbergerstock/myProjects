//*******************************************************************
//              
//  FILE:       XML_subkey.h
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

#include "XML_file_map.h"

#ifndef __XML_subkey_h
#define __XML_subkey_h

class XML_subkey
{
    private:
        XML_data& xml;

        string subkey;

    public:
        XML_subkey(XML_data& d, string& s) : xml(d), subkey(s) {}
        XML_subkey(XML_data& d, const char* s)   : xml(d), subkey(s) {} 
        ~ XML_subkey() {}

        string find_key(const char *k1, const char *k2, const char *k3);

        void   set_value(const char* k1, const char* new_value) { set_value(k1,"","",new_value); }             
        void   set_value(const char* k1, const char* k2, const char* new_value) { set_value(k1,k2,"",new_value); }
        void   set_value(const char* k1, const char* k2, const char* k3, const char* new_value);

        void   set_value(const char* k1, int v)   { set_value(k1,"","",v); }
        void   set_value(const char* k1, const char* k2, int v) { set_value(k1,k2,"",v); }
        void   set_value(const char* k1, const char* k2, const char* k3, int);

        void   set_value(const char* k1, double v)   { set_value(k1,"","",v); }
        void   set_value(const char* k1, const char* k2, double v) { set_value(k1,k2,"",v); }
        void   set_value(const char* k1, const char* k2, const char* k3, double);

        int    get_int_value(const char* k1 ) { return get_int_value(0,k1,"",""); }
        int    get_int_value(const char* k1, const char* k2) { return get_int_value(0,k1,k2,""); }
        int    get_int_value(const char* k1, const char* k2, const char* k3) { return get_int_value(0,k1,k2,k3); }

        int    get_int_value(int df,const char* k1 ) { return get_int_value(df,k1,"",""); }
        int    get_int_value(int df,const char* k1, const char* k2) { return get_int_value(df,k1,k2,""); }
        int    get_int_value(int df,const char* k1, const char* k2, const char* k3); 

        double get_double_value(const char* k1) { return get_double_value(0.0,k1,"",""); }
        double get_double_value(const char* k1, const char* k2) { return get_double_value(0.0,k1,k2,""); }
        double get_double_value(const char* k1, const char* k2, const char* k3) { return get_double_value(0.0,k1,k2,k3); }   
           
        double get_double_value(double df,const char* k1) { return get_double_value(df,k1,"",""); }
        double get_double_value(double df,const char* k1, const char* k2) { return get_double_value(df,k1,k2,""); }
        double get_double_value(double df,const char* k1, const char* k2, const char* k3);   

        string get_string_value(const char* k1) { return find_key(k1,"",""); }
        string get_string_value(const char* k1, const char* k2) { return find_key(k1,k2,""); }
        string get_string_value(const char* k1, const char* k2, const char* k3) { return find_key(k1,k2,k3); }

        string get_string_value(const char* k1, const char* k2, const char *k3, const char* dv);

};
#endif
