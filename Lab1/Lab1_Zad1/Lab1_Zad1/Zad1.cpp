#include <iostream>
using namespace std;
void v_alloc_table_add_5(int iSize) {
	if (iSize < 1) cout << "Size of an array should be > 0";
	else {
		int *i_table;
		i_table = new int[iSize];
		for (int i = 0; i < iSize; i++)
			i_table[i] = i + 5;
		for (int i = 0; i < iSize; i++)
			cout << i_table[i] << ' ';
		delete[] i_table;
	}
}
void main() {
	v_alloc_table_add_5(10);
}