#include <iostream>
#include "funcs.h" 

using namespace std;

int main() {
	///*
	listptr l1, l2 ; // elem_list* l1,*l2;
	listptr p, t;
	// create two lists
	l1 = get_list();
	//l1 = nullptr; 
	//for (int i = 0; i < 10; ++i)
	//{
	//	p = new elem_list;
	//	p->val = i;
	//	p->next = l1;
	//	l1 = p;
	//}

	l2 = nullptr; t = nullptr;
	t = l2 = new elem_list;
	l2->val = 0;
	l2->next = nullptr;
	for (int i = 1; i < 10; ++i) {
		t->next = new elem_list;
		t = t->next;
		t->val = i;
		t->next = nullptr;
	}
	//printing
	cout << " 1 list-> ";

	print_list(l1);
	//p = l1;
	//while (p != nullptr) // while (p)
	//{
	//	cout << p->val << " -- ";
	//	p = p->next;
	//}
	//cout << endl;
	cout << "The length is " << get_len(l1) << endl;
	cout << "The number of elemets 0 is " << count_el(l1, 0) << endl;
	cout << "The number of elemets 10 is " << count_el(l1, 10) << endl; 
	
	int k = 10;
	listptr check_ptr = find_val(l1, k);
	if (check_ptr == nullptr) {
		cout << "The element with value " << k << " isn't in the list" << endl;
	} else {
		cout << "The element " << check_ptr->val << " is in the list" << endl;
	}

	int elem = { 10 };
	cout << endl << "Inserting element " << elem << "..." << endl;
	// Inserting an element after the first element.
	insert_el(l1, 10, 9);
	// Inserting an element after the last element.
	//insert_el(l1, 10, 0);
	// Exception check: the condition cannot be fulfilled
	//insert_el(l1, 10, 11);
	

	k = 10;
	check_ptr = find_val(l1, k);
	if (check_ptr == nullptr) {
		cout << "The element with value " << k << " isn't in the list" << endl;
	}
	else {
		cout << "The element " << check_ptr->val << " is in the list" << endl;
	}
	print_list(l1);
	
	cout << endl << "Deleting value " << k  << "..." << endl;
	del_first_key(l1, k);
	print_list(l1);
	
	k = 9;
	cout << endl << "Deleting value " << k  << "..." << endl;
	del_first_key(l1, k);
	print_list(l1);
	
	k = 0;
	cout << endl << "Deleting value " << k  << "..." << endl;
	del_first_key(l1, k);
	print_list(l1);

	cout << endl << "Inserting numbers 10..." << endl; 
	insert_el(l1, 10, 8);
	insert_el(l1, 10, 8);
	insert_el(l1, 10, 8);
	insert_el(l1, 10, 8);
	print_list(l1);
	cout << "Deleting numbers 10..." << endl; 
	del_all_val(l1, 10);
	print_list(l1);

	cout << endl;

	cout << " 2 list-> ";
	// another variant of the loop

	for (p = l2; p != nullptr; p = p->next) {
		cout << p->val << " -- ";
	}
	cout << endl;
	cout << "The length is " << get_len(l2) << endl << endl;

	// delete
	del_list(l1);
	//p = l1;
	//while (p != nullptr) // while (p)
	//{
	//	l1 = l1->next;
	//	delete p;
	//	p = l1;
	//}
	
	del_list(l2);
	//p = l2;
	//while (p != nullptr) // while (p)
	//{
	//	l2 = l2->next;
	//	delete p;
	//	p = l2;
	//}

	t = nullptr; //!!!!
	//*/

	int a[] = { 1, 2, 3, 4, 5 }, a_size{ 5 };
	listptr l3 = create_list_from_array(a, a_size);
	print_list(l3);
	print_rev(l3);

	int size{ 5 };
	int* a1 = new int[size] {3, 3, 3, 3, 3};
	listptr l = create_list_from_array(a1, size);
	del_all_val(l, 3);
	
	print_list(l);

	system("pause");
	return 0;
}