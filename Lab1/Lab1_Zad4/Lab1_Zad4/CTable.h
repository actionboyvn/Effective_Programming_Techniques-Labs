#pragma once
#include <string>

using namespace std;

class CTable
{
private:
	string s_name;
	int *pi_table;
	int i_tableLen;
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(CTable &pcOther);
	~CTable();
	void vSetName(string sName);
	string sGetName();
	bool bSetNewSize(int iTableLen);
	int iGetTableLength();
	CTable *pcClone();
	
	const string const_s_name = "Default";
	const int const_i_tableLen = 0;
};

