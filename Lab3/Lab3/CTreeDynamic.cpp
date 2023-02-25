#include "CTreeDynamic.h"

CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic();
};

CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
};

void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}
CNodeDynamic* CTreeDynamic::pcGetRoot() {
	return(pc_root);
}
bool CTreeDynamic::bMoveSubtree(CNodeDynamic * pcParentNode, CNodeDynamic * pcNewChildNode) {
	CNodeDynamic *pc_PresentParentOfNewNode = pcNewChildNode->pcGetParent();
	if (pc_PresentParentOfNewNode != NULL)
		for (int i = 0; i < pc_PresentParentOfNewNode->iGetChildrenNumber(); i++)
			if (pc_PresentParentOfNewNode->pcGetChild(i) == pcNewChildNode) pc_PresentParentOfNewNode->vRemoveChild(i);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}
