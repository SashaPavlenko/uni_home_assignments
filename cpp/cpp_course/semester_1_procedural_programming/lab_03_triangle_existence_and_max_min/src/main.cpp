// lab_3.cpp : This file contains the "main" function. Program execution begins and ends there.
// 

#include <iostream>
#include "funcs.h"
#include "head2.h"

using namespace std;

int z = 2;
int count = 1;

int main()
{
    double a, b, c;

    cout << "enter side of triangle: ";
    cin >> a >> b >> c;

    if (exist(a, b, c)) {
        cout << "perimeter: " << P(a, b, c) << endl;
    } else {
        cout << "triangle with these sides doesn't exist";
    }

    point p1;
    
    cout << "\nenter point";
    cin >> p1.x >> p1.y;

    point points[28];

    return 0;
}