#pragma once
// Function that returns a random value in the range [a, b].
int randint(const int a, const int b);

// Function that returns a random element of the array.
double get_rand_elem(double* a, int size);

// Counts the elements equal to num in the array l.
int count_in_array(double* l, int size, double num);

// Function that prints an array.
void print_array(double* a, int size);

// Copies the elements of the array a into the array b.
void copy_array(double* a, double* b, int size);

// Default function type in quickselect_median.
typedef double(*pivot_fn_f)(double*, int);

// Function that computes the median of an array.
double quickselect_median(double* l, int size, double* b, pivot_fn_f pivot_fn = get_rand_elem);

// Helper function that computes the median: in one case if the array has an even number of elements, 
// and in the second case - if it is odd.
double quickselect(double* l, int size, double* b, int k, pivot_fn_f pivot_fn);

inline bool is_equal(double a, double b, double EXP = 1e-9) {
	return abs(a - b) < EXP;
}
