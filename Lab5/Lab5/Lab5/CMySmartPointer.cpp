#include "CMySmartPointer.h"

template<typename T>
CMySmartPointer<T>::CMySmartPointer(T *pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}

template<typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer &pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template<typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	vDeleteSmartPointer();
}

template<typename T>
T& CMySmartPointer<T>::operator*()
{
	return(*pc_pointer);
}

template<typename T>
T* CMySmartPointer<T>::operator->()
{
	return(pc_pointer);
}

template<typename T>
CMySmartPointer<T> & CMySmartPointer<T>::operator=(const CMySmartPointer & pcOther)
{
	vDeleteSmartPointer();
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
	return (*this);
}

template<typename T>
void CMySmartPointer<T>::vDeleteSmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}
}

