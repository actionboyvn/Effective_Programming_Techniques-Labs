#pragma once
#include <vector>
using namespace std;
class CVectorWrapper
{
private:
	vector<int*> my_vector;
public:
	CVectorWrapper();
	CVectorWrapper(const CVectorWrapper &pcOther);
	CVectorWrapper(CVectorWrapper &&pcOther);
	~CVectorWrapper();

	void vAddNewElement(int *piElement);
	void vSetElement(int iOffSet, int iVal);
	void vPrint();
};

