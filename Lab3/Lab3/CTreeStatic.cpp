#include "CTreeStatic.h"

CTreeStatic::CTreeStatic(){	
};

CTreeStatic::~CTreeStatic(){
};

void CTreeStatic::vPrintTree(){
	c_root.vPrintAllBelow();
}
CNodeStatic* CTreeStatic::pcGetRoot() {
	return(&c_root); 
}
bool CTreeStatic::bMoveSubtree(CNodeStatic * pcParentNode, CNodeStatic * pcNewChildNode) {
	pcParentNode->vAddNewChild(pcNewChildNode);
	CNodeStatic *pc_PresentParentOfNewNode = pcNewChildNode->pcGetParent();
	if (pc_PresentParentOfNewNode != NULL)
		for (int i = 0; i < pc_PresentParentOfNewNode->iGetChildrenNumber(); i++)
			if (pc_PresentParentOfNewNode->pcGetChild(i) == pcNewChildNode) pc_PresentParentOfNewNode->vRemoveChild(i);
	return true;
}
