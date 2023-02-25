#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

///////// CNodeDynamic Template Class //////////
template<typename T>
class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(T tNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic<T> *pcNewChildNode);
	CNodeDynamic *pcGetChild(int iChildOffset);
	void vRemoveChild(int iChildOffset);
	CNodeDynamic *pcGetParent();
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	void vPrune(T tValToPrune);
	string sGetKnownType();
	
private:
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T> *pc_parent_node;
	T t_val;
};

template<typename T>
CNodeDynamic<T>::CNodeDynamic() {
	t_val = T();
	pc_parent_node = NULL;
}

template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++)
		delete v_children.at(i);
	//cout << "usuwam: " << t_val << "\n";
}

template<typename T>
void CNodeDynamic<T>::vSetValue(T tNewVal) {
	t_val = tNewVal;
}

template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
	return(v_children.size());
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
	if (sGetKnownType().compare("INT") == 0 && v_children.size() >= t_val) return;

	CNodeDynamic<T> *pc_new_node = new CNodeDynamic<T>();
	pc_new_node->pc_parent_node = this;
	v_children.push_back(pc_new_node);
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> * pcNewChildNode) {
	if (sGetKnownType().compare("INT") == 0 && v_children.size() >= t_val) return;

	pcNewChildNode->pc_parent_node = this;
	v_children.push_back(pcNewChildNode);
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if (iChildOffset >= v_children.size()) return NULL;
	return v_children.at(iChildOffset);
}

template<typename T>
void CNodeDynamic<T>::vRemoveChild(int iChildOffset)
{
	if (iChildOffset >= v_children.size()) return;
	v_children.erase(v_children.begin() + iChildOffset);
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetParent() {
	return pc_parent_node;
}

template<typename T>
void CNodeDynamic<T>::vPrint() {
	cout << " " << t_val;
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i)->vPrintAllBelow();
}

template<typename T>
void CNodeDynamic<T>::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) pc_parent_node->vPrintUp();
}

template<typename T>
void CNodeDynamic<T>::vPrune(T tValToPrune) {
	if (tValToPrune == t_val && pc_parent_node == NULL) return;
	for (int i = 0; i < v_children.size(); i++)
		v_children.at(i)->vPrune(tValToPrune);
	if (tValToPrune == t_val) {
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

template<typename T>
string CNodeDynamic<T>::sGetKnownType() {
	string s_type = "Unknown";
	return s_type;
}
 
template<>
string CNodeDynamic<int>::sGetKnownType() {
	string s_type = "INT";
	return s_type;
}


///////// CTreeDynamic Template Class ///////////
template<typename T>
class CTreeDynamic {
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T> *pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
	
private:
	CNodeDynamic<T> *pc_root;
};

template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
	pc_root = new CNodeDynamic<T>();
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
	delete pc_root;
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}

template<typename T>
CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot() {
	return(pc_root);
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> * pcParentNode, CNodeDynamic<T> * pcNewChildNode) {
	CNodeDynamic<T> *pc_PresentParentOfNewNode = pcNewChildNode->pcGetParent();
	if (pc_PresentParentOfNewNode != NULL)
		for (int i = 0; i < pc_PresentParentOfNewNode->iGetChildrenNumber(); i++)
			if (pc_PresentParentOfNewNode->pcGetChild(i) == pcNewChildNode) pc_PresentParentOfNewNode->vRemoveChild(i);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}



