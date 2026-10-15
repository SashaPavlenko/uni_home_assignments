#include <iostream>
#include <ctime>
#include "TreeRec.h"
#include <cmath>

using namespace std;

int main() {
	//TreeR *t = new TreeR();// this is a non-empty tree
	/*
	TreeR t;
	srand(time(0));
	t.addNode(5);
	t.addNode(-7);
	t.addNode(3);
	t.addNode(-4);
	t.addNode(6);
	t.addNode(-10);
	t.addNode(7);

	TreeR t1;
	t1 = t;
	t1.addNode(1);
	cout << t;*/

	//cout << endl << t << endl << t1 << endl;
	

	TreeR t;
	//t.fill_width(cin);
	t.create();

	cout << endl <<  t;

	//t.addNode(5);
	//t.addNode(3);
	//t.addNode(7);
	//t.addNode(2);
	//t.addNode(4);
	//t.addNode(6);
	//t.addNode(8);

	//cout << t;
	//cout << endl << (t.count_leaf());

	//t->printRKL();
	//cout << "T " << t << endl;
	//t->printRKL();
	//TreeR *t1 = new TreeR(t);
	//cout << "T1 " << t1 << endl;
	//t1->printRKL(0);
	//delete t1;
	return 0;
}