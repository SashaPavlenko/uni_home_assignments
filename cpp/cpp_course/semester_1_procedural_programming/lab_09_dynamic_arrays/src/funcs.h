#pragma once

// Reads the array elements, allocating dynamic memory. The array size is also requested in the function.
void read(int*& a, std::size_t& n);

// Creates a dynamic array of size n and returns a pointer to it.
int* random_array(std::size_t n);

// Prints the array elements in one line.
void print_array(int* a, int size);

// Inserts a value into the middle of a dynamic array. Allocates memory for an array of the new size. 
// If the number of elements in the array is odd, inserts the element after the central one.
void insert_to_the_center(int*& a, size_t& size, int element);

// Deletes the element with index = index from the array a.
void del_index(int*& a, size_t& size, int index);

// Function that removes duplicates from the array. Frees unused memory.
void del_duplicates(int*& a, size_t& size);

// Function that checks whether the array is sorted in ascending order.
bool is_sorted(int*& a, int& size);

// Function that finds a number by binary search. If the number is not in the array, returns the index -1.
int bin_find(int*& a, int& size, int T);

// Performs quicksort of the array A using Hoare's method
void qSort(int* A, int low, int high);
