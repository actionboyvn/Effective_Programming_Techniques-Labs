#include "CTreeDynamic.h"
#include "CTreeStatic.h"

void v_static_tree_test() {
	CTreeStatic c_tree;

	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//c_tree.vPrintTree();
	//c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();

}

void v_dynamic_tree_test() {
	CTreeDynamic *pc_tree = new CTreeDynamic();

	pc_tree->pcGetRoot()->vAddNewChild();
	pc_tree->pcGetRoot()->vAddNewChild();

	pc_tree->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	pc_tree->pcGetRoot()->pcGetChild(1)->vSetValue(2);
	
	pc_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(0)->vAddNewChild();

	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	pc_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(1)->vAddNewChild();

	pc_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	pc_tree->pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//pc_tree->vPrintTree();
	//pc_tree->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();

	delete pc_tree;
}
void v_moving_dynamic_tree_test() {
	CTreeDynamic *pc_tree1 = new CTreeDynamic();
	CTreeDynamic *pc_tree2 = new CTreeDynamic();

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

	CNodeDynamic *pcParentNode = pc_tree1->pcGetRoot()->pcGetChild(2);
	CNodeDynamic *pcNewChildNode = pc_tree2->pcGetRoot()->pcGetChild(0);
	pc_tree1->bMoveSubtree(pcParentNode, pcNewChildNode);
	
	pc_tree1->vPrintTree(); cout << endl;
	pc_tree2->vPrintTree();

	delete pc_tree1;
	delete pc_tree2;
}
void v_moving_static_tree_test() {
	CTreeStatic c_tree1;
	CTreeStatic c_tree2;

	c_tree1.pcGetRoot()->vSetValue(0);

	c_tree1.pcGetRoot()->vAddNewChild();
	c_tree1.pcGetRoot()->vAddNewChild();
	c_tree1.pcGetRoot()->vAddNewChild();

	c_tree1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree1.pcGetRoot()->pcGetChild(2)->vSetValue(3);

	c_tree1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	c_tree1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	c_tree2.pcGetRoot()->vSetValue(50);

	c_tree2.pcGetRoot()->vAddNewChild();
	c_tree2.pcGetRoot()->vAddNewChild();

	c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(55);

	c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);

	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();

	c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	CNodeStatic *pcParentNode = c_tree1.pcGetRoot()->pcGetChild(2);
	CNodeStatic *pcNewChildNode = c_tree2.pcGetRoot()->pcGetChild(0);
	c_tree1.bMoveSubtree(pcParentNode, pcNewChildNode);

	c_tree1.vPrintTree(); cout << endl;
	c_tree2.vPrintTree();

}
void v_tree_prune_test() {
	CTreeDynamic *pc_tree = new CTreeDynamic();
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
	v_moving_static_tree_test();
	//v_moving_dynamic_tree_test();
	//v_tree_prune_test();
	return 0;
}