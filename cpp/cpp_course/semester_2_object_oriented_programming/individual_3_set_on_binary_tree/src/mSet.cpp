//#include "mSet.h"
//#include <iostream>
//
//void mSet::swap(mSet s)
//{
//	std::swap(this->length, s.length);
//	std::swap(this->t, s.t);
//}
//
//mSet::mSet()
//{
//	this->t = TreeR();
//	this->length = 0;
//}
//
//mSet::mSet(int a[], int size)
//{
//	TreeR tr;
//
//	for (int i = 0; i < size; ++i) {
//		tr.addNode(a[i]);
//	}
//	length = tr.count_roots();
//	this->t = tr;
//}
//
//mSet::mSet(int a)
//{
//	TreeR tr;
//
//	tr.addNode(a);
//	length = tr.count_roots();
//	this->t = tr;
//}
//
//mSet::mSet(const mSet& s)
//{
//	this->t = s.t;
//	this->length = s.length;
//}
//
//mSet::~mSet() { }
//
//set_iter mSet::begin() const
//{
//	return set_iter(this, this->t);
//}
//
//set_iter mSet::end() const
//{
//	return set_iter(this, TreeR());
//}
//
//mSet& mSet::operator=(const mSet& s)
//{
//	mSet s_copy = s;
//	this->swap(s);
//
//	return *this;
//}
//
//bool mSet::is_there(int a) const
//{
//	return this->t.find(a);
//}
//
//int mSet::capacity()
//{
//	return this->length;
//}
//
//bool mSet::operator==(const mSet& s)
//{
//	bool flag{ this->length == s.length };
//	for (auto i = this->begin(); i != this->end() && flag; ++i) {
//		flag = s.is_there(*i);
//	}
//
//	return flag;
//}
//
//bool mSet::pop(int a)
//{
//	bool flag = this->is_there(a);
//	if (flag) {
//		this->t.pop(a);
//		length--;
//	}
//
//	return flag;
//}
//
//const mSet mSet::operator+(const mSet& s)
//{
//	mSet set_copy = *this;
//	
//	for (auto i : s) {
//		if (!this->is_there(i)) {
//			set_copy.t.addNode(i);
//			set_copy.length++;
//		}
//	}
//
//	return set_copy;
//}
//
//const mSet mSet::operator*(const mSet& s)
//{
//	mSet set_copy;
//
//	for (auto i : s) {
//		if (this->is_there(i)) {
//			set_copy.t.addNode(i);
//			set_copy.length++;
//		}
//	}
//
//	return set_copy;
//}
//
//mSet& mSet::operator+=(const mSet& s)
//{
//	mSet set_copy = *this;
//
//	for (auto i : s) {
//		if (!this->is_there(i)) {
//			set_copy.t.addNode(i);
//			set_copy.length++;
//		}
//	}
//
//	*this = set_copy;
//	return *this;
//}
//
//mSet& mSet::operator+=(int s)
//{
//	this->t.addNode(s);
//	this->length++;
//	return *this;
//}
//
//mSet& mSet::operator-=(const mSet& s)
//{
//	mSet set_copy = *this;
//
//	for (auto i : s) {
//		if (set_copy.is_there(i)) {
//			set_copy.pop(i);
//		}
//	}
//
//	*this = set_copy;
//	return *this;
//}
//
//std::ostream& operator<<(std::ostream& out, const mSet& y)
//{
//	for (auto i : y) {
//		std::cout << i << " ";
//	}
//	std::cout << std::endl;
//
//	return out;
//}
//
//std::istream& operator>>(std::istream& in, mSet& y)
//{
//	int rData;
//	while (!in.eof()) {
//		in >> rData;
//		y += rData;
//	}
//
//	return in;
//}
