#pragma once
#include <iostream>

template<typename T>
class MyTree
{
private: 
	
	struct Node;
	typedef Node* node_ptr;

	//template<typename T>
	struct Node
	{
		T data;
		Node* lt;
		Node* rt;
		Node() : lt(nullptr), rt(nullptr) {}
		Node(const T& data, Node* lt = nullptr, Node* rt = nullptr) :
			data(data), lt(lt), rt(rt) {}
	};

	node_ptr root;
	void copy(node_ptr t, node_ptr& newT)  const {
		if (t != nullptr)
		{
			newT = new Node(t->data, nullptr, nullptr);
			copy(t->lt, newT->lt);
			copy(t->rt, newT->rt);
		}
		else newT = nullptr;
	};
	void delTree(node_ptr& t) {
		if (t != nullptr) {
			delTree(t->lt);
			delTree(t->rt);
			delete t;
			t = nullptr;
		}
	};

	void add(node_ptr& t, T a) {
		if (t == nullptr) t = new Node(a);
		else if (t->data > a) add(t->lt, a);
		else if (t->data < a) {
			add(t->rt, a);
		}
	};

	void print_tree(const node_ptr& root, std::ostream& os = std::cout, const size_t spaces = 0) const {
		if (root != nullptr) {
			print_tree(root->rt, os, spaces + 1);
			for (int i = 0; i < spaces; ++i)
				os << '\t';
			os << root->data << std::endl;
			print_tree(root->lt, os, spaces + 1);
		}
	};

	void del_all_leafs(node_ptr& t) {
		if (t != nullptr) {
			if (t->lt == nullptr && t->rt == nullptr) {
				delete t;
				t = nullptr;
			} 
			else {
				del_all_leafs(t->lt);
				del_all_leafs(t->rt);
			}
		}
	};
public:
	MyTree() : root{ nullptr } {};
	MyTree(T a) : root{new Node(a)} {};
	MyTree(const MyTree<T>& t){
		copy(t.root, this->root);
	};
	~MyTree() {
		delTree(this->root);
	};

	void addNode(T a) {
		add(root, a);
	}

	void del_leafs() {
		del_all_leafs(this->root);
	};

	MyTree<T>* copy_tree() {
		if (root == nullptr) {
			return nullptr;
		}
		
		MyTree<T>* new_tree = new MyTree<T>(root->data);
		new_tree->rt = copy_tree(root->rt);
		new_tree->lt = copy_tree(root->lt);
		return new_tree;
	};

	friend std::ostream& operator<<(std::ostream& os, const MyTree<T>& t) { 
		t.print_tree(t.root, os);  
		return os; 
	}

};

