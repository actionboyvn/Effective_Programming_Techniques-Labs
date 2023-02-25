#pragma once
#include "CNodeStatic.h"
#include <iostream>
using namespace std;

class CTreeStatic {
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic *pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);
private:
	CNodeStatic c_root;
};

