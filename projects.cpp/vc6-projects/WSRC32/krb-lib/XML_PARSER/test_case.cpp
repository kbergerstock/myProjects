//*******************************************************************
//              
//  FILE:       test_case.cpp
//              
//  AUTHOR:     Keith R. Bergerstock
//              
//  PROJECT:    xml_map
//              
//  COMPONENT:  -
//              
//  DATE:       07.01.2004
//              
//  COMMENTS:   -
//              
//              
//*******************************************************************




#pragma warning(disable:4786)

// Includes

#include <iostream>
#include <string>
#include "XML_cfg.h"

void p1(XML_mapping& keys, char* szKey, const string& fn)
{
    XML_cfg xml(keys);
    xml.parseFile(szKey,fn);
    keys.dump();

    cout << " new cfg read" << endl;

}

void main(void)
{  
    const string fn("c:\\tpm-rx\\tpm-rx-specs.xml");

    XML_mapping cfg;

    p1(cfg,"HONDA04",fn);
    
    cout << " token key search" << endl;
    cout << " null : " << cfg.find_key("empty","","") << endl;
    cout << " active current low : " << cfg.get_double_value("CURRENT","active","low") << endl;
    cout << " log file : " << cfg.get_string_value("LOGS","TXT","") << endl;
    cout << " vsat high : " << cfg.get_double_value("LED","vsat","high") << endl;

    cout << " ecu id_1  : " << hex << cfg.get_int_value("ECU_DATA","ID_1","") << endl;
    cout << " ecu id_1  : " << hex << cfg.get_int_value("ECU_DATA","ID_2","") << endl;
    cout << " ecu id_1  : " << hex << cfg.get_int_value("ECU_DATA","ID_3","") << endl;
    
    
    p1(cfg,"HYUNDAI_HI_04",fn);
    
    cout << " part number " << cfg.get_string_value("ECU_DATA","part_number","") << endl;
    cout << " base freq   " << cfg.get_double_value("SIG_GEN","base_freq","") << endl;
    cout << " led leakage " << cfg.get_double_value("LED","leakage","high") << endl;

    cout << " ADC IGN LOW : " << dec << cfg.get_int_value("ADC_VAL","ign_l1","low") << endl;
    cout << " ADC IGN HIGH: " << dec << cfg.get_int_value("ADC_VAL","ign_l1","high") << endl;
}
