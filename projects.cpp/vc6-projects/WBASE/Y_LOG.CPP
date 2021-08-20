#include "y_log.h"

YIELD_LOG::YIELD_LOG():LOG()
{

}

void YIELD_LOG::Init(LPSTR Name)
{
	numflds = 5;
	static NEWFIELD yield_flds[] =				 // static to ensure persistance
	{
		{"DATE",TYPE_CHAR,10},
		{"TIME",TYPE_CHAR,8},
		{"TOTAL",TYPE_NUM,6,0},
		{"GOOD",TYPE_NUM,6,0},
        {"YIELD",TYPE_NUM,6,2}
	};

	flds = yield_flds;

	File = new DB3FILE(Name,READWRT,yield_flds,numflds);
	File->CLOSE();
}

YIELD_LOG::~YIELD_LOG()
{
	if(File != NULL)
		delete File;
}

void YIELD_LOG::Append(YIELD_DATA& data)
{
	if(File != NULL)
    {
	lstrcpy(LPSTR(data.szDATE),GetSysDate());
	lstrcpy(LPSTR(data.szTIME),GetSysTime());

	File->OPEN();
	File->ReplaceField(flds[0].name,data.szDATE);
	File->ReplaceField(flds[1].name,data.szTIME);
	File->ReplaceField(flds[2].name,data.total);
	File->ReplaceField(flds[3].name,data.good);
    File->ReplaceField(flds[4].name,data.yield);
	File->WriteRecord(NEW_RECORD);
	File->CLOSE();
    }
}

YIELD_DATA YIELD_LOG::Read(unsigned long r)
{
	YIELD_DATA data;
	if(File != NULL)
    {
	File->ReadRecord(r);
	lstrcpy(LPSTR(data.szDATE),LPSTR(File->Get(flds[0].name)));
	lstrcpy(LPSTR(data.szTIME),LPSTR(File->Get(flds[1].name)));
	data.total = long(File->GetFloatField(LPSTR(flds[2].name)));
	data.good = long(File->GetFloatField(LPSTR(flds[3].name)));
    data.yield = File->GetFloatField(LPSTR(flds[4].name));
    }
	return data;
}

