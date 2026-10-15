#include "List.h"
#include "funcs.h"
#include <sstream>
#include <string>

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)

Node* List::get_prev_last()
{
	node_ptr cur = this->first;
	while (cur->next != this->last)
	{
		cur = cur->next;
	}

	return cur;
}

List::List() : first(nullptr), last(nullptr) {	}

List::~List() {
	while (first != nullptr)
	{
		node_ptr cur = this->first;
		this->first = this->first->next;
		delete cur;
	}
	first = last = nullptr;
}

bool List::isEmpty() const
{
	return first == nullptr;
}

void List::addFirst(int x)
{
	node_ptr t = new Node(x, this->first);

	if (this->first == nullptr) {
		this->first = t;
		this->last = t;
	} 
	else {
		this->first = t;
	}
}

void List::addLast(int val)
{
	node_ptr t = new Node(val, nullptr);
	if (this->first == nullptr) {
		this->first = t;
		this->last = t;
	} 
	else {
		this->last->next = t;
		this->last = t;
	}
}

int List::getFirst() const
{
	return this->first->data;
}

int List::getLast() const
{
	return this->last->data;
}

void List::setIter(const List_iter& it, int elem)
{
	if (it == this->begin()) {
		this->addFirst(elem);
	}
	else {

		List_iter cur_next = this->begin();
		++cur_next;
		node_ptr cur = this->first;

		while (cur_next != it) {
			++cur_next;
			cur = cur->next;
		}

		node_ptr nnew = new Node(elem, cur->next);
		cur->next = nnew;
	}
}

int List::delFirst()
{
	if (this->isEmpty()) {
		throw Error("EmptyList");
	}

	int cur_data = this->first->data;
	
	if (this->first == this->last) {
		delete this->first;
		this->first = this->last = nullptr;
	} 
	else {
		node_ptr cur = this->first;
		this->first = this->first->next;
		delete cur;
	}

	return cur_data;
}

int List::delLast()
{
	int cur_data;

	if (this->first == nullptr) {
		throw Error("EmptyList");
	}
	else if (this->first == this->last) {
		cur_data = this->last->data;
		delete this->first;
		this->first = this->last = nullptr;
	}
	else {
		cur_data = this->last->data;
		node_ptr cur = this->last;
		this->last = this->get_prev_last();
		this->last->next = nullptr;
		delete cur;
	}

	return cur_data;
}

void List::delIt(const List_iter& it)
{
	if (it == List_iter(this, nullptr)) {
		throw Error("IncorrectIterator");
	}
	List_iter it_last(this, this->last);
	if (it == this->begin()) {
		this->delFirst();
	} 
	else if (it == it_last) {
		std::cout << "deleting last";
		this->delLast();
	}
	else {
		auto cur_next = this->begin();
		++cur_next;
		auto cur = this->first;
		
		while (cur_next != it) {
			++cur_next;
			cur = cur->next;
		}

		auto t = cur->next;
		cur->next = cur->next->next;
		delete t;
	}

}

int List::kol(bool(*f)(int))
{
	int count{ 0 };
	for (auto it = this->begin(); it != this->end(); ++it) {
		if (f(*it)) {
			count++;
		}
	}

	return count;
}

void List::for_each(void(*action)(int&))
{
	for (List_iter it = this->begin(); it != this->end(); ++it) {
		action(*(it));
	}
}

ostream& operator<<(ostream& out, const List& y)
{
	out << "first --> ";
	for (List_iter it = y.begin(); it != y.end(); ++it) {
		out << *it << " --> ";
		//std::cout << *it << " ";
	}
	out << "last";
	out << endl;
	return out;
}

istream& operator>>(istream& in, List& y)
{
	y.~List();
	
	int size;
	int a;
	in >> size;

	for (int i = 0; i < size; i++)
	{
		in >> a;
		y.addFirst(a);
	}

	return in;
}

List_iter List::begin()const {
	return List_iter(this, first);
}

List_iter List::end()const {
	return List_iter(this, nullptr);
}

List_iter List::last_elem() const
{
	return List_iter(this, this->last);
}
