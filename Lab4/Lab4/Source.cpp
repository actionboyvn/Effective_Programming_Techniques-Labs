#include "CTreeDynamic.h"

void v_dynamic_tree_test() {
	
	CTreeDynamic<int> *pc_tree = new CTreeDynamic<int>();
	
	pc_tree->pcGetRoot()->vSetValue(100);

	
	pc_tree->pcGetRoot()->vAddNewChild();
	pc_tree->pcGetRoot()->vAddNewChild();
	
	pc_tree->pcGetRoot()->pcGetChild(0)->vSetValue(2);
	pc_tree->pcGetRoot()->pcGetChild(1)->vSetValue(2);
	
	pc_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	
	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	
	pc_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	
	pc_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	pc_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	
	pc_tree->vPrintTree(); 
	//pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	//cout << pc_tree->sGetKnownType();
	
	delete pc_tree;
	
}
void v_moving_dynamic_tree_test() {
	CTreeDynamic<int> *pc_tree1 = new CTreeDynamic<int>();
	CTreeDynamic<int> *pc_tree2 = new CTreeDynamic<int>();

	pc_tree1->pcGetRoot()->vSetValue(0);

	pc_tree1->pcGetRoot()->vAddNewChild();
	pc_tree1->pcGetRoot()->vAddNewChild();
	pc_tree1->pcGetRoot()->vAddNewChild();
	
	pc_tree1->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	pc_tree1->pcGetRoot()->pcGetChild(1)->vSetValue(2);
	pc_tree1->pcGetRoot()->pcGetChild(2)->vSetValue(3);

	pc_tree1->pcGetRoot()->pcGetChild(2)->vAddNewChild();
	pc_tree1->pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	pc_tree2->pcGetRoot()->vSetValue(50);

	pc_tree2->pcGetRoot()->vAddNewChild();
	pc_tree2->pcGetRoot()->vAddNewChild();

	pc_tree2->pcGetRoot()->pcGetChild(0)->vSetValue(54);
	pc_tree2->pcGetRoot()->pcGetChild(1)->vSetValue(55);

	pc_tree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	pc_tree2->pcGetRoot()->pcGetChild(0)->vAddNewChild();

	pc_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	pc_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

	pc_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();

	pc_tree2->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	CNodeDynamic<int> *pcParentNode = pc_tree1->pcGetRoot()->pcGetChild(2);
	CNodeDynamic<int> *pcNewChildNode = pc_tree2->pcGetRoot()->pcGetChild(0);
	pc_tree1->bMoveSubtree(pcParentNode, pcNewChildNode);
	
	pc_tree1->vPrintTree(); cout << endl;
	pc_tree2->vPrintTree();

	delete pc_tree1;
	delete pc_tree2;
}

void v_tree_prune_test() {
	CTreeDynamic<int> *pc_tree = new CTreeDynamic<int>();
	pc_tree->pcGetRoot()->vSetValue(1);

	pc_tree->pcGetRoot()->vAddNewChild();
	pc_tree->pcGetRoot()->vAddNewChild();

	pc_tree->pcGetRoot()->pcGetChild(0)->vSetValue(2);
	pc_tree->pcGetRoot()->pcGetChild(1)->vSetValue(3);

	pc_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();

	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(48);
	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(3);

	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->pcGetChild(0)->vSetValue(5);

	pc_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();

	pc_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(6);
	pc_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(7);

	pc_tree->vPrintTree(); cout << endl;
	pc_tree->pcGetRoot()->vPrune(3);
	pc_tree->vPrintTree(); cout << endl;

	delete pc_tree;
}

int main() {
	v_dynamic_tree_test();
	//v_moving_dynamic_tree_test();
	//v_tree_prune_test();
	return 0;
}