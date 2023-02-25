#include "CNodeDynamic.h"
#include <iostream>
using namespace std;

CNodeDynamic::CNodeDynamic() {
	i_val = 0;
	pc_parent_node = NULL;
}
CNodeDynamic::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++)
		delete v_children.at(i);
	//cout << "usuwam: " << i_val << "\n";
}
void CNodeDynamic::vSetValue(int iNewVal) {
	i_val = iNewVal;
}
int CNodeDynamic::iGetChildrenNumber() {
	return(v_children.size());
}
void CNodeDynamic::vAddNewChild() {
	CNodeDynamic *pc_new_node = new CNodeDynamic();
	pc_new_node->pc_parent_node = this;
	v_children.push_back(pc_new_node);
}
void CNodeDynamic::vAddNewChild(CNodeDynamic * pcNewChildNode){
	pcNewChildNode->pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}
CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset >= v_children.size()) return NULL;
	return v_children.at(iChildOffset);
}
void CNodeDynamic::vRemoveChild(int iChildOffset)
{
	if (iChildOffset >= v_children.size()) return;
	v_children.erase(v_children.begin() + iChildOffset);
}
CNodeDynamic* CNodeDynamic::pcGetParent() {
	return pc_parent_node;
}
void CNodeDynamic::vPrint() {
	cout << " " << i_val;
}
void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i)->vPrintAllBelow();
}

void CNodeDynamic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
}
void CNodeDynamic::vPrune(int iValToPrune){
	if (iValToPrune == i_val && pc_parent_node == NULL) return;
	for (int i = 0; i < v_children.size(); i++) 
		v_children.at(i)->vPrune(iValToPrune);
	if (iValToPrune == i_val) {
		for (int i = 0; i < pc_parent_node->iGetChildrenNumber(); i++)
			if (pc_parent_node->pcGetChild(i) == this)
				pc_parent_node->vRemoveChild(i);
		for (int i = 0; i < v_children.size(); i++) {
			pc_parent_node->vAddNewChild(v_children.at(i));
			//v_children.at(i) = NULL;
		}
		v_children.clear();
		delete this;
	}
}

