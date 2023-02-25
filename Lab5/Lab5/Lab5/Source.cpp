#include "CMySmartPointer.h"
#include "CMySmartPointer.cpp"
#include "CTab.h"
#include "CTable.h"
#include "CVectorWrapper.h"
#include <iostream>
using namespace std;
void v_smartPointer_test() {
	CMySmartPointer<int> c_int(new int(5));
	CMySmartPointer<int> c_int_other(new int (7));
	c_int = c_int_other;
	cout << *c_int;
}
CTab cCreateTab()
{ 
	CTab c_result;
	c_result.bSetSize(5);
	return(move(c_result));
}
void v_ms_test()
{ 
	//CTab c_tab = cCreateTab();
	CTab c_tab;
	CTab c_other;
	//c_tab = c_other;
	c_tab = move(c_other);
}
void v_cTable_test() {
	CTable c_tab_0("tab0", 0), c_tab_1("tab1", 0), c_tab_2("tab2", 0);

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
	
	//c_tab_0.vPrint();

	c_tab_2 = c_tab_0 + c_tab_1;

	//c_tab_2 = c_tab_2 / 3;

	c_tab_2.vPrint();
}
void v_vectorWrapper_test() {
	CVectorWrapper c_vector;
	c_vector.vAddNewElement(new int(3));
	c_vector.vAddNewElement(new int(4));
	c_vector.vAddNewElement(new int(5));

	CVectorWrapper c_vector_copy(c_vector);
	c_vector.vSetElement(0, 99);
	c_vector.vPrint(); cout << endl;
	c_vector_copy.vPrint(); cout << endl;
	
	cout << endl;

	CVectorWrapper c_vector_move(move(c_vector));
	c_vector.vPrint(); cout << endl;
	c_vector_move.vPrint(); cout << endl;
	
}
int main() {
	//v_smartPointer_test();
	//v_ms_test();
	v_cTable_test();
	//v_vectorWrapper_test();
	return 0;
}