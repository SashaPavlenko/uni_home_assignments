#include "tree.h"

void Tree::delTree(node_ptr t) {
	int c;
	if (t != nullptr) {
		delTree(t->lt);
		delTree(t->rt);
		delete t;
		t = nullptr;
	}
}

void Tree::add(node_ptr& t, int a) {
	if (t == nullptr) t = new TNode(a);
	else if (t->data > a) add(t->lt, a);
	else add(t->rt, a);
}

void Tree::printLKR(node_ptr t, ostream& os) const {
	if (t) {
		printLKR(t->lt, os);
		os << t->data << " ";
		printLKR(t->rt, os);

	}
}
void Tree::copy(node_ptr t, node_ptr &newT)  const //KLR
{
	if (t != nullptr)
	{
		newT = new TNode(t->data, 0, 0);
		copy(t->lt, newT->lt);
		copy(t->rt, newT->rt);
	}
	else newT = nullptr;
}
