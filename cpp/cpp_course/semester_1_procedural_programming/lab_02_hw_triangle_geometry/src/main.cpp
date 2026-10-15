// lab_2_HW.cpp : This file contains the "main" function. Program execution begins and ends there.
//

#include <iostream>
#include "funs.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    //cout << tRight == tAcute;

    point x, y, z;

    cout << "Enter the coordinates of the triangle points.\n";
    cout << "\nX coordinate of the first point: ";
    cin >> x.x;
    cout << "Y coordinate of the first point: ";
    cin >> x.y;

    cout << "\nX coordinate of the second point: ";
    cin >> y.x;
    cout << "Y coordinate of the second point: ";
    cin >> y.y;

    cout << "\nX coordinate of the third point: ";
    cin >> z.x;
    cout << "Y coordinate of the third point: ";
    cin >> z.y;
    cout << endl;

    double a, b, c;
    get_sides_tri(x, y, z, a, b, c);

    cout << "Area of the triangle: " << square(x, y, z) << endl << endl;

    switch (check_triangle_type(x, y, z))
    {
    case tObtuse:
        cout << "Type of the triangle: obtuse.";
        break;
    case tAcute:
        cout << "Type of the triangle: acute.";
        break;
    case tRight:
        cout << "Type of the triangle: right.";
    break;
    default:
        break;
    }

    return 0;
}