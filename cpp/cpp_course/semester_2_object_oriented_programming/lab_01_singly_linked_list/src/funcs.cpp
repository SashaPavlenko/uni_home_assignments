#include "funcs.h"
#include <iostream>

using namespace std;

void del_list(listptr &a) {
	listptr l = a;
	
	while (l != nullptr) {
		a = l->next;
		delete l;
		l = a;
	}
}

void print_list(listptr a) {
	while (a != nullptr) // while (p)
	{
		cout << a->val << " -- ";
		a = a->next;
	}
	cout << endl;
}

listptr get_list() {
	int size;
	cout << "Enter size of list: ";
	cin >> size;

	listptr a = nullptr, p;
	for (int i = 0; i < size; ++i)
	{
		p = new elem_list;
		p->val = i;
		p->next = a;
		a = p;
	}

	return a;
}

int get_len(listptr a) {
	int size{ 0 };

	while (a != nullptr)
	{
		size++;
		a = a->next;
	}

	return size;
}

int count_el(listptr a, int value)
{
	int k{ 0 };

	while (a != nullptr) {
		if (a->val == value) {
			k++;
		}
		a = a->next;
	}

	return k;
}

listptr find_val(listptr a, int value)
{
	//listptr pointer = nullptr;

	//while (a != nullptr && pointer == nullptr)
	while (a != nullptr)
	{
		if (a->val == value) {
			//pointer = a;
			return a;
		}
		a = a->next;
	}

	//return pointer;
	return a;
}

void insert_el(listptr a, int value, int key)
{
	//listptr a_res = a;
	while (a != nullptr && a->val != key)
	{
		a = a->next;
	}

	// Exception: there is no element with the value value in the list.
	// Error code: 1.
	if (a == nullptr) {
		throw 1;
	}

	listptr p = new elem_list;
	p->val = value;

	p->next = a->next;
	a->next = p;

	//a = a_res;
}

void del_first_key(listptr& a, int key) {
	listptr a_res = a, p=a;
	while (a != nullptr && a->val != key) {
		p = a;
		a = a->next;
	}

	if (a != nullptr) {
		/*if (a->next != nullptr && p != a) {
			p->next = a->next;
			delete a;
		}
		else if (a->next == nullptr) {
			delete a;
			p->next = nullptr;
		}
		else if (p == a) {
			a_res = p->next;
			delete p;
		} 
		else {
			delete p;
			a_res = nullptr;
		}*/

		if (p == a) {
			a_res = a->next;
			delete a;
		}
		else {
			p->next = a->next;
			delete a;
		}
	}
	else {
		// Exception: there is no element to delete.
		// Error code: 2.
		throw 2;
	}

	a = a_res;
}

void del_all_val(listptr& a, int value) {
	while (find_val(a, value) != nullptr) {
		del_first_key(a, value);
	}
}

listptr create_list_from_array(int* a, int size) {
	
	/*if (size == 0) {
		new_l = nullptr;
		return new_l;
	}*/

	listptr p = nullptr, l1 = nullptr;
	l1 = nullptr; 
	for (int i = 0; i < size; ++i)
	{
		p = new elem_list;
		p->val = a[size-i-1];
		p->next = l1;
		l1 = p;
	}

	return l1;
}

int list_sum(listptr a) {
	if (a->next == nullptr) {
		return a->val;
	}
	else {
		return a->val + list_sum(a->next);
	}
}

int count_values(listptr a, int value) {
	if (a->next == nullptr) {
		return a->val == value ? 1 : 0;
	}
	else {
		return (a->val == value ? 1 : 0) + count_values(a->next, value);
	}
}

int list_max(listptr a) {
	if (a->next == nullptr) {
		return a->val;
	}
	else {
		int mmax{ list_max(a->next) };
		return a->val > mmax? a->val : mmax;
	}
}

void print_rev(listptr a) {
	if (a != nullptr) {
		print_rev(a->next);
		cout << a->val << " ";
	}
}