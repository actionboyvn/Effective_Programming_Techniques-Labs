#include "CTable.h"
#include <string>
#include <iostream>

using namespace std;

CTable::CTable() {
	s_name = const_s_name;
	cout << "bezp: " << s_name << endl;
	i_tableLen = const_i_tableLen;
	pi_table = new int[i_tableLen];
}
CTable::CTable(string sName, int iTableLen) {
	s_name = sName;
	cout << "parametr: " << s_name << endl;
	i_tableLen = iTableLen;
	pi_table = new int[i_tableLen];
}
CTable::CTable(CTable &pcOther) {
	s_name = pcOther.s_name + "_copy";
	i_tableLen = pcOther.i_tableLen;
	pi_table = new int[i_tableLen];
	for (int i = 0; i < i_tableLen; i++)
		pi_table[i] = pcOther.pi_table[i];
	cout << "kopiuj: " << s_name << endl;
}
CTable::~CTable() {
	delete[] pi_table;
	cout << "usuwam: " << s_name << endl;
}
void CTable::vSetName(string sName) {
	s_name = sName;
}
string CTable::sGetName() {
	return s_name;
}
bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen < 0) return false;
	int *pi_new_table = new int[iTableLen];
	for (int i = 0; (i < i_tableLen) && (i < iTableLen); i++)
		pi_new_table[i] = pi_table[i];
	delete[] pi_table;
	pi_table = pi_new_table;
	i_tableLen = iTableLen;
	return true;
}
int CTable::iGetTableLength() {
	return i_tableLen;
}
CTable* CTable::pcClone()
{
	CTable *cTable_clone = new CTable(s_name, i_tableLen);
	return cTable_clone;
}
