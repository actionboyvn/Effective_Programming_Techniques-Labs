#pragma once
#include "CRefCounter.h"
//#include "CMySmartPointer.cpp"
template<typename T>
class CMySmartPointer
{
public:
	CMySmartPointer(T *pcPointer);
	CMySmartPointer(const CMySmartPointer &pcOther);
	~CMySmartPointer();
	T& operator*();
	T* operator->();
	CMySmartPointer& operator = (const CMySmartPointer &pcOther);
private:
	void vDeleteSmartPointer();
	CRefCounter *pc_counter;
	T *pc_pointer;
};

