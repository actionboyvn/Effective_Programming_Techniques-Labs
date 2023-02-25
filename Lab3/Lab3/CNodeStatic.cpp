#include "CNodeStatic.h"
#include <iostream>
using namespace std;

CNodeStatic::CNodeStatic() {
	i_val = 0;
	pc_parent_node = NULL;
}
CNodeStatic::~CNodeStatic(){
	//cout << "usuwam: " << i_val << "\n";
}
void CNodeStatic::vSetValue(int iNewVal) {
	i_val = iNewVal;
}
int CNodeStatic::iGetChildrenNumber() {
	return(v_children.size());
}
void CNodeStatic::vAddNewChild(CNodeStatic *pcNewChildNode){
	CNodeStatic c_new_child_node;
	c_new_child_node.i_val = pcNewChildNode->i_val;
	c_new_child_node.v_children = pcNewChildNode->v_children;
	c_new_child_node.vUpdateParent(this);
	v_children.push_back(c_new_child_node);
}
void CNodeStatic::vAddNewChild(){
	CNodeStatic c_new_node;
	c_new_node.pc_parent_node = this;
	v_children.push_back(c_new_node);
}
CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset){
	if (iChildOffset >= v_children.size()) return NULL;
	return &v_children.at(iChildOffset);
}
void CNodeStatic::vRemoveChild(int iChildOffset){
	if (iChildOffset >= v_children.size()) return;
	v_children.erase(v_children.begin() + iChildOffset);
}
CNodeStatic* CNodeStatic::pcGetParent(){
	return pc_parent_node;
}
void CNodeStatic::vUpdateParent(CNodeStatic * pcNewParent){
	pc_parent_node = pcNewParent;
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i).vUpdateParent(this);
}
void CNodeStatic::vPrint() {
	cout << " " << i_val;
}
void CNodeStatic::vPrintAllBelow(){
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i).vPrintAllBelow();
}

void CNodeStatic::vPrintUp(){
	vPrint();
	if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
}

