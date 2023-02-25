#pragma once
//#include "CRefCounter.cpp"
class CRefCounter
{
public:
	CRefCounter(); 
	int iAdd(); 
	int iDec(); 
	int iGet(); 
private:
	int i_count;
};

