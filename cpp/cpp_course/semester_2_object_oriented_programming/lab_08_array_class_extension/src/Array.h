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
    };        //copy constructor

    ~Array() {
        delete[] this->values;
    }; // destructor

    // methods
    //---*---
    int length() const;
    // Search for a given element.
    int find(int val);
    // Increasing the size of the array.
    void upsize(int size_plus = -1);
    // Decreasing the size of the array (from the end).
    void downsize(int size_minus = -1);
    // Inserting an element at a given position.
    void insert(int index, int elem);
    // Adding an element to the end of the array.
    void rinsert(int elem);
    // Removing the element with a given index.
    void pop(int index);

    // friend functions
    friend std::ostream& operator << (std::ostream& out, const Array& arr);
    friend std::istream& operator >> (std::istream& in, Array& arr);

    // Operator overloads
    Array operator + (const Array& arr);
    Array operator += (const Array& arr);
    Array operator + (const int x);
    bool operator == (const Array& arr);
    Array& operator = (Array arr);
    int& operator [] (int i);
    int operator [] (int i) const;

};
