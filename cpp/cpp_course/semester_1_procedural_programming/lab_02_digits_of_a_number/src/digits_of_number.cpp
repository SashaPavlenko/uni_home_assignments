#include <iostream>
#include <cmath>

using namespace std;

/*

Task 1

An integer is given; determine the number and the sum of digits in the decimal notation of this number. 
Output the number itself and the number obtained from it by crossing out the first and the last digits. 
Implement the actions of determining the number of digits in the decimal notation of a number, computing the sum of 
digits of a number, transforming a number by crossing out its first and last digits as functions.

*/

// Count numbers of number.
int count_numbers(int x);

// Count sum of numbers of number.
int sum_of_num(int x);

// Reformat number.
int new_num(int x);

/*

Task 2

Write a function that raises an integer to an integer power. Two integers N and K are given. Check
that the number N equals the sum of the K-th powers of its digits.

*/

int my_pow(int n, int k);
// Raise a number.

bool check_con(int N, int k);
// Check the condition.

/*

Task 3

For the following functions, write an implementation and come up with examples of use for specific tasks:
1. function that determines the maximum/minimum of two/three numbers (use an inline implementation)
2. function that computes sin x using the Taylor series expansion
3. function that computes the factorial of a number
4. function that swaps two numbers in order to sort them

*/

//---------------------------------------------
// Item 1.
//---------------------------------------------

inline int my_max(int a, int b);
// Return max number from a and b.

inline int my_max(int a, int b, int c);
// Return max number from a, b and c.

inline int my_min(int a, int b);
// Return min number from a and b.

inline int my_min(int a, int b, int c);
// Return min number from a, b and c.

//---------------------------------------------
// Item 2.
//---------------------------------------------

double T_sin(double x, double EPS = 1e-6);
// Spread sin to Taylor series.

//---------------------------------------------
// Item 3.
//---------------------------------------------
int fac(int n);
// Count factorial n.

//---------------------------------------------
// Item 4.
//---------------------------------------------
void sort_couple(int& a, int& b);
// Sort a and b in order.

//---------------------------------------------
// main
//---------------------------------------------


int main()
{
    setlocale(LC_ALL, "rus");
	
    // 1.
    int n;

    cout << "Task 1.\n" << "Enter a number: ";
    cin >> n;

    cout << "Number and sum of digits in the decimal notation of this number: " << count_numbers(n) << " and " << sum_of_num(n) << ".\n";
    cout << "Original number: " << n << "; Generated number: " << new_num(n) << ".\n";

    // 2.
    int N, K;
    
    cout << "\nTask 2.\nEnter the number N: ";
    cin >> N;
    cout << "Enter the power K: ";
    cin >> K;

    cout << N << " to the power of " << K << " is " << my_pow(N, K);
    cout << "\nCondition: " << check_con(N, K);

    // 3.
    int a, b, c;

    cout << "\n\nTask 3.\nEnter 3 numbers: ";
    cin >> a >> b >> c;
    cout << "Maximum of two numbers (" << a << " and " << b << "): " << my_max(a, b);
    cout << "\nMaximum of three numbers (" << a << ", " << b << ", " << c << "): " << my_max(a, b);
    
    cout << "\nMinimum of two numbers (" << a << " and " << b << "): " << my_min(a, b);
    cout << "\nMinimum of three numbers (" << a << ", " << b << ", " << c << "): " << my_min(a, b);


    double angle;
    
    cout << "\n\nEnter the angle in radians: ";
    cin >> angle;
    cout << "sin(" << angle << ") = " << T_sin(angle);
    cout << "\nCheck: sin(" << angle << ") = " << sin(angle);

    int num;
    cout << "\n\nEnter a number to compute its factorial: ";
    cin >> num;
    cout << num << "! = " << fac(num);

    int x, y;

    cout << "\n\nEnter 2 numbers: ";
    cin >> x >> y;

    sort_couple(x, y);

    cout << "Ordered pair: " << x << " and " << y;
	return 0;
}

// Task 1.
int count_numbers(int x)
{
    /*
    Count numbers of number.

    */

    x = abs(x);
    int count = 0;

    do
    {
        count++;
        x /= 10;
    } while (x != 0);

    return count;
}

int sum_of_num(int x)
{
    /*
    Count sum of numbers of number.

    */

    int sum = 0;
    x = abs(x);

    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int new_num(int x)
{
    /*
    Reformat number.

    */

    int sign_num;
    if (x > 0)
        sign_num = 1;
    else
        if (x < 0)
            sign_num = -1;
        else
            sign_num = 0;

    x = abs(x);

    int i = 1, new_x = 0, num = x;
    while (num / 10 != 0)
    {
        new_x = new_x + (num % 10) * i;
        i *= 10;
        num /= 10;
    }

    new_x = (new_x / 10) * sign_num;

    return new_x;
}

// Task 2.
int my_pow(int n, int k)
{
    /*
    Raise a number.

    */

    int new_n = 1;

    for (int i = 0; i < k; i++)
        new_n *= n;

    return new_n;
}

bool check_con(int N, int k)
{
    /*
    Check the condition.

    */

    int copy_N = N, sum = 0;

    while (copy_N != 0)
    {
        sum += my_pow(copy_N, k);
        copy_N /= 10;
    }

    return sum == N;
}

// Task 3. 
inline int my_max(int a, int b)
{
	/*
	Return max number from a and b.

	*/

	int max_num = a;

	if (a < b)
		max_num = b;

	return max_num;
}

inline int my_max(int a, int b, int c)
{
	/*
	Return max number from a, b and c.

	*/

	int max_num = a;

	if (a < b)
		max_num = b;
	if (max_num < c)
		max_num = c;

	return max_num;
}

inline int my_min(int a, int b)
{
	/*
	Return min number from a and b.

	*/

	int min_num = a;

	if (a > b)
		min_num = b;

	return min_num;
}

inline int my_min(int a, int b, int c)
{
	/*
	Return min number from a, b and c.

	*/

	int min_num = a;

	if (a > b)
		min_num = b;
	if (min_num > c)
		min_num = c;

	return min_num;
}

double T_sin(double x, double EPS)
{
	/*
	Spread sin to Taylor series.

	*/

	double sum = 0, a = x;
	double i = 0;

	while (abs(a) > EPS)
	{
		sum += a;
		i++;

		a *= -1 * x * x / (2 * i) / (2 * i + 1);
	}

	return sum;
}

int fac(int n)
{
	/*
	Count factorial n.

	*/
	int prod = 1;

	for (int i = 1; i <= n; i++)
		prod *= i;

	return prod;
}

void sort_couple(int& a, int& b)
{
	/*
	Sort a and b in order.

	*/

	if (a > b)
	{
		int c = a;
		a = b;
		b = c;
	}
}