#include <iostream>
using namespace std;

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
	if (iSizeX < 1 || iSizeY < 1) {
		cout << "Sizes of an array should be positive integer numbers";
		return false;
	}
	if (*piTable != nullptr) return false;
	*piTable = new int*[iSizeX];
	for (int i = 0; i < iSizeX; i++)
		(*piTable)[i] = new int[iSizeY];
	return true;
}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
	if (iSizeX < 1 || iSizeY < 1) {
		cout << "Sizes of an array should be positive integer numbers";
		return false;
	}
	if (*piTable == nullptr) return false;
	for (int i = 0; i < iSizeX; i++)
		delete[](*piTable)[i];
	delete[](*piTable);
	return true;
}
bool b_alloc_2_dim(int iSizeX, int iSizeY, int ***piTableToAlloc) {
	if (iSizeX < 1 || iSizeY < 1) {
		if (DEBUG) cout << "Sizes of an array should be positive integer numbers";
		return false;
	}
	if (*piTableToAlloc != nullptr) return false;
	*piTableToAlloc = new int*[iSizeY];
	for (int i = 0; i < iSizeY; i++)
		*(*piTableToAlloc + i) = new int[iSizeX];
	for (int i = 0; i < iSizeY; i++)
		for (int j = 0; j < iSizeX; j++)
			*(*(*piTableToAlloc + i) + j) = i * iSizeX + j;
	for (int i = 0; i < iSizeY; i++) {
		for (int j = 0; j < iSizeX; j++)
			cout << *(*(*piTableToAlloc + i) + j) << ' ';
		cout << endl;
	}
	return true;
}
void main() {
	//int **pi_table = nullptr;
	//cout << "Allocation: " << b_alloc_table_2_dim(&pi_table, 5, 3) << endl;
	//cout << "Deallocation: " << b_dealloc_table_2_dim(&pi_table, 5, 3);

	int **pi_table_to_alloc = nullptr;
	cout << "Allocation: " << b_alloc_2_dim(12, 5, &pi_table_to_alloc);
}