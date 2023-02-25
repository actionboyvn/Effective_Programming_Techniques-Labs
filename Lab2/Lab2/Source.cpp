#include "CTable.h"
#include <iostream>

using namespace std;

void main() { 
	CTable c_tab_0("tab0", 0), c_tab_1("tab1", 0), c_tab_2("tab2", 0), c_tab_3("tab3", 0);
	
	c_tab_0.bSetNewSize(4);
	c_tab_1.bSetNewSize(4);
	c_tab_0.vSetValueAt(0, 1);
	c_tab_0.vSetValueAt(1, 2);
	c_tab_0.vSetValueAt(2, 3);
	c_tab_0.vSetValueAt(3, 4);
	c_tab_1.vSetValueAt(0, 51);
	c_tab_1.vSetValueAt(1, 52);
	c_tab_1.vSetValueAt(2, 53);
	c_tab_1.vSetValueAt(3, 54);
	//c_tab_0 = c_tab_1;
	c_tab_1.vSetValueAt(2, 123);
	c_tab_0.vPrint();
	c_tab_1.vPrint();

	c_tab_2 = c_tab_0 + c_tab_1;

	c_tab_2.vPrint();
	c_tab_2 / 3;
	c_tab_2.vPrint();


	
	
	
	
	
	

}