#pragma once

struct elem_list {
	int val;
	char buf[1024]=""; //this is a dummy field, used only to control memory leaks
	elem_list* next;
};

typedef elem_list* listptr;

// Deletes the list.
void del_list(listptr& a);

// Prints the list from the first to the last element.
void print_list(listptr a);

// Creates a list whose length is set from the console.
listptr get_list();

// Finds the length of the list.
int get_len(listptr a);

// Counts the list elements with a given value.
int count_el(listptr a, int value);

// Determines the position of the first element with a given value.
listptr find_val(listptr a, int value);

// Inserts a new element into the list after the first element with a given value. 
// If the insertion is impossible, the function throws an exception with error code 1.
void insert_el(listptr a, int value, int key);

// Deletes the first element with a given value from the list.
void del_first_key(listptr& a, int key);

// Deletes all elements with a given value.
void del_all_val(listptr& a, int value);

// Creates a list of a given length from the array elements.
listptr create_list_from_array(int* a, int size);

// Finds the sum of the values of the list elements.
int list_sum(listptr a);

// Counts the list elements with a given value.
int count_values(listptr a, int value);

// Determines the maximum value in the list.
int list_max(listptr a);

// Prints the list in reverse order.
void print_rev(listptr a);
