#include "CTab.h"
#include <iostream>
using namespace std;
CTab::CTab(const CTab &cOther)
{
	v_copy(cOther);
	cout << "Copy ";
}
CTab::CTab(CTab &&cOther)
{
	vMoveSemantic(cOther);
	cout << "MOVE ";
}
CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	cout << "Destr ";
}
bool CTab::bSetSize(int iNewSize)
{
	if (iNewSize < 0) return false;
	int *pi_tab_new = new int[iNewSize];
	for (int i = 0; (i < iNewSize) && (i < i_size); i++)
		pi_tab_new[i] = pi_tab[i];
	delete[] pi_tab;
	pi_tab = pi_tab_new;
	i_size = iNewSize;
	return true;
}
CTab CTab::operator=(const CTab &cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	cout << "op= ";
	return(*this);
}
CTab& CTab::operator=(CTab && cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	vMoveSemantic(cOther);
	cout << "op= ";
	return (*this);
}
void CTab::v_copy(const CTab &cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}
void CTab::vMoveSemantic(CTab &cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
}


