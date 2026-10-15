#include <iostream>
#include "median.h"

int randint(const int a, const int b) {
    return a + (std::rand() % (b - a + 1));
}

double get_rand_elem(double* a, int size) {
    int index{ randint(0, size - 1) };
    return a[index];
}

int count_in_array(double* l, int size, double num) {

    int sum{ 0 };

    for (int i = 0; i < size; i++)
        if (l[i] == num)
            sum++;

    return sum;
}

void print_array(double* a, int size) {
    for (int i = 0; i < size; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

void copy_array(double* a, double* b, int size) {
    for (int i = 0; i < size; i++)
        b[i] = a[i];
}

double quickselect(double* l, int size, double* b, int k, pivot_fn_f pivot_fn) {
    /*
    Âûáèðàåì k - òûé ýëåìåíò â ñïèñêå l(ñ íóëåâîé áàçîé)
    : param l : Ìàññèâ ÷èñëîâûõ äàííûõ.
    : param size : Ðàçìåð ìàññèâà.
    : parab b : Âñïîìîãàòåëüíûé ìàññèâ äëÿ ðàçáèåíèÿ èñõîäíîãî íà low è high.
    : param k : Èíäåêñ.
    : param pivot_fn : ôóíêöèÿ âûáîðà pivot, ïî óìîë÷àíèþ âûáèðàåò ýëåìåíò ñëó÷àéíî èç ìàññèâà.
    : return : k - òûé ýëåìåíò l.
    */

    if (size == 1) {
        // assert(k==0);
        return l[0];
    }

    copy_array(l, b, size);

    // Chooses a random element from the array l.
    double pivot = pivot_fn(l, size);

    int index{ 0 }, len_pivots{ count_in_array(l, size, pivot) };
    int i{ 0 };

    /* 
    We change the array b as follows:
    
    We go through the array l. We have index, which points to the element after the last element of the array "low".
    
    If we come across an element less than pivot, we increase index by 1. 
    Also, if i and index differ, we swap b[i] and b[index].

    If we come across an element equal to pivot, we swap b[i] with the last element of the array b, 
    not equal to pivot and decrease the size size, cutting off the part of the array elements equal to pivot.  
    We also do not change i, because b[i] is a new element and it has to be checked.

    As a result we get an array b with the following properties:
    [0, index) - all elements less than pivot
    [index, size) - all elements greater than pivot. size - the changed value.
    */
    while (i < size) {
        if (l[i] < pivot) {
            if (i != index) {
                double t = b[index];
                b[index++] = l[i];
                b[i] = t;
            }
            else
                index++;
        }
        else
            if (is_equal(l[i], pivot)) {
                while (b[size - 1] == pivot)
                    size--;
                if (i < size) {
                    double t = b[i];
                    b[i] = b[size - 1];
                    b[size - 1] = t;

                    l[i] = l[size - 1];
                    l[size - 1] = t;

                    i--;
                }
            }
        i++;
    }

    if (k < index - 1)
        return quickselect(b, index, l, k, pivot_fn);
    else
        if (k < index + len_pivots)
            // Íàì ïîâåçëî è ìû óãàäàëè ìåäèàíó
            return pivot;
        else
            return quickselect(b + index, size - index, l + index, k - index - len_pivots, pivot_fn);
}

double quickselect_median(double* l, int size, double* b, pivot_fn_f pivot_fn) {
    // pivot_fn = getRandomNumber(0, size - 1);

    if (size % 2)
        return quickselect(l, size, b, size / 2, pivot_fn);
    else
        return 0.5 * (quickselect(l, size, b, size / 2 - 1, pivot_fn) + quickselect(l, size, b, size / 2, pivot_fn));

}