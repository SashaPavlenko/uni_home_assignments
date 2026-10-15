//#include <iostream>
//#include "TreeRec.h"
//#include <string>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <cmath>
//#include <vector>
//
//
//void TreeR::delTree(node_ptr t) {
//	if (t != nullptr) {
//		delTree(t->lt);
//		delTree(t->rt);
//		delete t;
//	}
//	t = nullptr;
//}
//
//void TreeR::swap(TreeR& obj)
//{
//	std::swap(this->root, obj.root);
//	//std::swap(this->data, obj.data);
//}
//
//void TreeR::add(node_ptr& t, int a)
//{
//	if (t == nullptr) {
//		t = new TNode(a);
//	}
//	else if (t->data > a) {
//		this->add(t->lt, a);
//	}
//	else if (t->data < a) {
//		this->add(t->rt, a);
//	}
//}
//
//void TreeR::printLKR(node_ptr t, std::ostream& os) const
//{
//	if (t != nullptr) {
//		printLKR(t->lt, os);
//		os << t->data << " ";
//		printLKR(t->rt, os);
//	}
//}
//
//void TreeR::copy(node_ptr t, node_ptr& newT) const
//{
//	if (t != nullptr) {
//		newT = new TNode(t->data);
//		copy(t->lt, newT->lt);
//		copy(t->rt, newT->rt);
//	}
//	else {
//		newT = nullptr;
//	}
//}
//
//TreeR::TreeR() : root{ nullptr } {}
//
//TreeR::TreeR(const TreeR& t)
//{
//	this->copy(t.root, this->root);
//}
//
//TreeR::~TreeR() {
//	this->delTree(this->root);
//}
//
//int TreeR::getData() const
//{
//	return this->root->data;
//}
//
//bool TreeR::is_full_tree()
//{
//	return this->full_root(this->root);
//}
//
//void TreeR::addNode(int a)
//{
//	this->add(this->root, a);
//}
//
//bool TreeR::is_Empty() const
//{
//	return this->root == nullptr;
//}
//
//int TreeR::count_roots()
//{
//	return count_num_roots(this->root);
//}
//
//int TreeR::count_leaf()
//{
//	return this->count_num_leaf(this->root);
//}
//
//int TreeR::count_deep()
//{
//	return count_roots_deep(this->root);
//}
//
//void TreeR::fill_width(std::istream& is)
//{
//	int rData;
//	while (is.peek() != '\n') {
//		is >> rData;
//		this->add_width(this->root, rData);
//	}
//
//}
//
//void TreeR::create(std::istream& is)
//{
//	int rData;
//	std::vector<int> v;
//
//	while (is.peek() != '\n') {
//		is >> rData;
//		v.push_back(rData);
//	}
//
//	int n{ static_cast<int>(v.size()) };
//	std::stringstream t;
//	for (auto i : v) {
//		t << i << " ";
//	}
//	
//	this->~TreeR();
//	create_balanced_tree(n, this->root, t);
//
//}
//
//bool TreeR::find(int a) const
//{
//	return this->find(this->root, a);
//}
//
//bool TreeR::pop(int a)
//{
//	bool flag{ this->find(a) };
//	if (flag == true) {
//		this->del_node(this->root, a);
//	}
//
//	return flag;
//}
//
//std::vector<int> TreeR::get_vec()
//{
//	std::vector<int> vec;
//	get_all_elems(this->root, vec);
//
//	return vec;
//}
//
//void TreeR::create_balanced_tree(int n, node_ptr& t, std::stringstream& is)
//{
//	node_ptr p;
//	int d, rData;
//	if (n > 0) {
//		is >> rData;
//		t = new TNode(rData);
//		d = n / 2;
//		create_balanced_tree(d, t->lt, is);
//		create_balanced_tree(n - 1 - d, t->rt, is);
//	}
//	else {
//		t = nullptr;
//	}
//}
//
//TreeR::node_ptr& TreeR::find(node_ptr t, int a) const
//{
//	if (t == nullptr) {
//		node_ptr tt = nullptr;
//		return tt;
//	}
//	else if (a == t->data) {
//		return t;
//	}
//	else if (a < t->data) {
//		return this->find(t->lt, a);
//	}
//	else {
//		return this->find(t->rt, a);
//	}
//}
//
//void TreeR::del_node(node_ptr& t, int a)
//{
//	if (t != nullptr) {
//		if (a == t->data) {
//			deleteNode(t, a);
//		}
//		else if (a < t->data) {
//			del_node(t->lt, a);
//		}
//		else {
//			del_node(t->rt, a);
//		}
//	}
//}
//
//void TreeR::deleteNode(node_ptr& t, int a)
//{
//	node_ptr delNode;
//	int repl;
//	if ((t-> lt == nullptr) && (t->rt == nullptr)) {// 1
//		delete t;
//		t = nullptr;
//	}
//	else if (t->lt == nullptr) {// 2
//		delNode = t;
//		t = t->rt;
//		delete delNode;
//	}
//	else if (t->rt == nullptr) {// 3
//		delNode = t;
//		t = t->lt;
//		delete delNode;
//	}
//	else if (t->lt != nullptr && t->rt != nullptr) {// 4
//		delLeftLeaf(t->rt, repl);
//		t->data = repl;
//	}
//}
//void TreeR::delLeftLeaf(node_ptr& t, int& repl)
//{
//	if (!t->lt) // the leftmost node has no left descendants
//	{
//		repl = t->data;
//		node_ptr delNode = t;
//		t = t->rt;
//		delete delNode;
//	}
//	else
//		delLeftLeaf(t->lt, repl);
//}
//
//void TreeR::get_all_elems(node_ptr& t, std::vector<int>& vec)
//{
//	if (t != nullptr) {
//		get_all_elems(t->lt, vec);
//		vec.push_back(t->data);
//		get_all_elems(t->rt, vec);
//	}
//}
//
//
//TreeR& TreeR::operator=(TreeR t)
//{
//	this->swap(t);
//	return *this;
//}
//
//bool TreeR::operator==(const TreeR& t) const
//{
//	return equal(this->root, t.root);
//}
//
//
//bool TreeR::equal(const node_ptr t1, const node_ptr t2) const
//{
//	if (t1 == nullptr && t2 == nullptr) {
//		return true;
//	}
//	else if (t1 == nullptr || t2 == nullptr) {
//		return false;
//	}
//	else {
//		return t1->data == t2->data && equal(t1->lt, t2->lt) && equal(t1->rt, t2->rt);
//	}
//}
//
//void TreeR::add_width(node_ptr& t, int a)
//{
//	if (t == nullptr) {
//		t = new TNode(a);
//	}
//	else {
//		if (count_roots_deep(t->lt) == count_roots_deep(t->rt)) {
//			if (full_root(t->rt)) {
//				add_width(t->lt, a);
//			}
//			else {
//				add_width(t->rt, a);
//			}
//		}
//		else{
//			if (!full_root(t->lt)) {
//				add_width(t->lt, a);
//			}
//			else {
//				add_width(t->rt, a);
//			}
//		}
//	}
//}
//
//bool TreeR::full_root(node_ptr& t)
//{
//	if (t == nullptr) {
//		return true;
//	}
//	else {
//		return (std::pow(2, count_roots_deep(t)-1) == count_num_leaf(t));
//	}
//}
//
//
//std::ostream & operator<<(std::ostream & os, const TreeR& t) {
//	 t.printTree(t.root, os, 0);
//	 return os;
//}
//
// int TreeR::count_num_roots(const node_ptr t)
// {
//	 if (t == nullptr) {
//		return 0;
//	}
//	else {
//		 //t->lt;
//		 return 1 + count_num_roots(t->lt) + count_num_roots(t->rt);
//	}
// }
//
// int TreeR::count_num_leaf(const node_ptr t)
// {
//	 if (t == nullptr) {
//		 return 0;
//	 }
//	 else if (t->lt == nullptr && t->rt == nullptr) {
//		 return 1;
//	 }
//	 else {
//		 return count_num_leaf(t->lt) + count_num_leaf(t->rt);
//	 }
// }
//
// int TreeR::count_roots_deep(const node_ptr t)
// {
//	 if (t == nullptr) {
//		 return 0;
//	 }
//	 else {
//		 return 1 + std::max(count_roots_deep(t->lt), count_roots_deep(t->rt));
//	 }
// }
//
// void TreeR::printTree(const node_ptr t, std::ostream& os, int skip) const
// {
//	if (t != nullptr) {
//		printTree(t->rt, os, skip + 1);
//		for (int i = 0; i < skip; ++i) {
//			os << "      ";
//		}
//		os << t->data << "\n";
//		printTree(t->lt, os, skip + 1);
//	}
// }