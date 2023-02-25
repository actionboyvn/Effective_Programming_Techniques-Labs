#pragma once
#include "CNodeDynamic.h"
#include <iostream>
using namespace std;

class CTreeDynamic {
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic *pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
private:
	CNodeDynamic *pc_root;
};

