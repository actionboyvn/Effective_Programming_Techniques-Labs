#pragma once
#include <vector>
#include <iostream>
using namespace std;

class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic *pcNewChildNode);
	CNodeDynamic *pcGetChild(int iChildOffset);
	void vRemoveChild(int iChildOffset);
	CNodeDynamic *pcGetParent();
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	void vPrune(int iValToPrune);
private:
	vector<CNodeDynamic*> v_children;
	CNodeDynamic *pc_parent_node;
	int i_val;
};

