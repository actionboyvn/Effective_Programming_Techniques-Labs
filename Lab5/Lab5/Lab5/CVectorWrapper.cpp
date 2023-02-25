#include "CVectorWrapper.h"
#include <iostream>
using namespace std;

CVectorWrapper::CVectorWrapper()
{
}

CVectorWrapper::CVectorWrapper(const CVectorWrapper & pcOther)
{
	for (int i = 0; i < pcOther.my_vector.size(); i++)
		my_vector.push_back(new int(*pcOther.my_vector.at(i)));
}

CVectorWrapper::CVectorWrapper(CVectorWrapper && pcOther)
{
	for (int i = 0; i < pcOther.my_vector.size(); i++) {
		my_vector.push_back(pcOther.my_vector.at(i));
		pcOther.my_vector.at(i) = NULL;
	}
	pcOther.my_vector.clear();
}

CVectorWrapper::~CVectorWrapper()
{
	for (int i = 0; i < my_vector.size(); i++) delete my_vector.at(i);
	my_vector.clear();
}

void CVectorWrapper::vAddNewElement(int *piElement)
{
	if (piElement == NULL) return;
	my_vector.push_back(piElement);
}

void CVectorWrapper::vSetElement(int iOffSet, int iVal)
{
	if (iOffSet >= my_vector.size()) return;
	*my_vector.at(iOffSet) = iVal;
}

void CVectorWrapper::vPrint()
{
	for (int i = 0; i < my_vector.size(); i++) cout << *my_vector.at(i) << " ";
}
