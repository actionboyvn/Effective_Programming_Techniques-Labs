#include <iostream>
#include "CTable.h"
using namespace std;

void v_mod_tab(CTable *pcTab, int iNewSize) {
	cout << "Mod 1: " << pcTab->bSetNewSize(iNewSize) << endl;
}
void v_mod_tab(CTable cTab, int iNewSize) {
	cout << "Mod 2: " << cTab.bSetNewSize(iNewSize) << endl;
}
void main() {
	CTable cTab("Static", 4);
	v_mod_tab(cTab, 5);
	cout << cTab.iGetTableLength() << endl;
	
	CTable *pcTab;
	pcTab = new CTable("Dynamic", 5);
	delete pcTab;
}