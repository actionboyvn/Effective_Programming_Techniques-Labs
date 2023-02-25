#pragma once
#include <string>

using namespace std;

class CTable
{
private:
	void vMoveSemantic(CTable &pcOther);
	void v_copy(const CTable &pcOther);
	string s_name;
	int *pi_table;
	int i_tableLen;
public:
	CTable();
	CTable(string sName, int iTableLen);
	CTable(const CTable &pcOther);
	CTable(CTable &&pcOther);
	~CTable();
	void vSetName(string sName);
	string sGetName();
	bool bSetNewSize(int iTableLen);
	int iGetTableLength();
	CTable *pcClone();

	CTable& operator = (const CTable &pcOther);
	CTable& operator = (CTable &&pcOther);
	CTable operator + (const CTable &pcOther);
	CTable operator / (int iPace);
	
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();
	const string const_s_name = "Default";
	const int const_i_tableLen = 0;
};


