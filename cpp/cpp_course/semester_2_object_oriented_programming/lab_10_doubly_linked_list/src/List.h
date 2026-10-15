#pragma once
#include <iostream>
#include "funcs.h"

using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int data, Node* next) {
		this->data = data;
		this->next = next;
	}

	~Node() { }

	friend 	ostream & operator<< (ostream & out, const Node & x);
};


class Error: public exception { //you can write your own implementation or inherit from exception
private:
	std::string m_error;
public:
	Error(std::string text = "Undefined error") : m_error{ text } {};
	const char* what() const noexcept { return m_error.c_str(); }
};

class List_iter;

class List {
private:
	Node* first;
	Node* last;
	Error err;
	
	Node* get_prev_last();
	typedef Node* node_ptr;
public:
	// Constructors.
	List();

	// Destructor.
	~List();

	bool isEmpty() const;
	void addFirst(int x);
	void addLast(int val);
	
	// getters and setters.
	int getFirst()const;
	int getLast()const;
	void setIter(const List_iter& it, int elem);

	int delFirst();
	int delLast();
	void delIt(const List_iter& it);
	
	//processing with a predicate
	int kol(bool(*f) (int));
	void for_each(void(*action)(int &));

	//a full implementation may have more functions
	List_iter begin()const; 
	List_iter end()const; 
	List_iter last_elem() const;

	friend ostream & operator << (ostream & out, const List & y);
	friend istream & operator >> (istream & in, List & y);

};


class List_iter {
public:
	class Error {
	public:
		void what() {
			cout << "Iterator error" << endl;
		}
	};
private:
	const List *collection;
	Node *cur;	
public:
	List_iter(const List *s, Node *e) : collection(s), cur(e) {}
	 int& operator *() {
		if (cur)      return cur->data;
		else         throw Error();
	}
	List_iter operator++() { //prefix ++
		if (cur) {
			cur = cur->next;
			return *this;
		}
		else throw Error();
	}
	bool operator == (const List_iter &ri) const {
		return ((collection == ri.collection) && (cur == ri.cur));
	}
	bool operator != (const List_iter &ri) const {
		return !(*this == ri);
	}

};



