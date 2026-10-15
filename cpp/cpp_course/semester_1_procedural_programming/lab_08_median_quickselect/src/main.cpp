#include <iostream>
#include "funcs.h"
#include "median.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

    double a[] = { 9, 1, 0, 2, 3, 4, 6, 8, 7, 10, 5 };
    const int n = 11;
    double b[n];

    print_array(a, n);
    cout << "Sum of the elements: " << sum_of_el(a, n) << endl;
    cout << "Maximum element: " << max_arr(a, n) << endl;
    cout << "The array contains no zeros: " << without_zeros(a, n) << endl;
    cout << "Median of the array: " << quickselect_median(a, n, b) << endl;

    return 0;					
}