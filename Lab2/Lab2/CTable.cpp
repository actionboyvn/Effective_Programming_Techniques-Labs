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

void CTable::vSetValueAt(int iOffset, int iNewVal) {
	pi_table[iOffset] = iNewVal;
}
void CTable::vPrint() {
	for (int i = 0; i < i_tableLen; i++)
		cout << pi_table[i] << " ";
	cout << endl;
}
CTable& CTable::operator = (const CTable &pcOther) {
	//pi_table = pcOther.pi_table;
	//i_tableLen = pcOther.i_tableLen;	
	
	i_tableLen = pcOther.i_tableLen;
	int *pi_new_table = new int[i_tableLen];
	for (int i = 0; i < i_tableLen; i++) pi_new_table[i] = pcOther.pi_table[i];
	delete[] pi_table;
	pi_table = pi_new_table;
	
	return (*this);
}
CTable CTable::operator + (const CTable &pcOther) {
	CTable c_res("(" + s_name + " + " + pcOther.s_name + ")", 0);
	c_res.bSetNewSize(i_tableLen + pcOther.i_tableLen);
	for (int i = 0; i < i_tableLen; i++)
		c_res.pi_table[i] = pi_table[i];
	for (int i = i_tableLen; i < i_tableLen + pcOther.i_tableLen; i++)
		c_res.pi_table[i] = pcOther.pi_table[i - i_tableLen];
	return c_res;
}
CTable& CTable::operator / (int iPace) {
	int i_new_tableLen = (i_tableLen / iPace + (i_tableLen % iPace != 0));

	int *pi_new_table = new int[i_new_tableLen];
	for (int i = 0; i < i_new_tableLen; i++)
		pi_new_table[i] = pi_table[i * iPace];
	delete[] pi_table;
	pi_table = pi_new_table;
	i_tableLen = i_new_tableLen;
	return (*this);
}

