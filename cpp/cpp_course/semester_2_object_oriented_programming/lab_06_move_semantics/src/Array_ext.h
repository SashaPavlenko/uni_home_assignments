#include <iostream>

#pragma once
class Array {
private:
    int n;
    int* values;
    void swap(Array& other);
public:
    Array() : n(0), values(nullptr) {};    //default constructor
    Array(int _n, int x = 0) {
        this->n = _n;

        if (_n > 0) {
            this->values = new int[_n];
            for (int i = 0; i < _n; ++i) {
                this->values[i] = x;
            }
        }
        else {
            this->values = nullptr;
        }

    };         //constructor with parameters

    // Wrapping an ordinary array into an Array class array.
    Array(int a[], int size) {
        this->n = size;
        this->values = new int[size];
        for (int i = 0; i < size; ++i) {
            this->values[i] = a[i];
        }
    }

    Array(const Array& other) {
        this->n = other.n;
        this->values = new int[other.n];

        for (int i = 0; i < other.n; ++i) {
            this->values[i] = other.values[i];
        }

        std::cout << "Used copy" << std::endl;
    };        //copy constructor

    Array(Array&& other)noexcept;

    ~Array();

    // friend functions
    friend std::ostream& operator << (std::ostream& out, const Array& arr);
    friend std::istream& operator >> (std::istream& in, Array& arr);

    // Operator overloads
    Array operator + (const Array& arr);

    Array& operator = (Array&& arr)noexcept;
    Array& operator = (const Array& arr);

};
