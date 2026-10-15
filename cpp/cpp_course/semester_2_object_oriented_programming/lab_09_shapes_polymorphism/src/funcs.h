#include <string>
#include <tuple>
#include "Shape.h"
#include "Circled.h"

#pragma once
std::string readFile(const std::string& fileName);

bool lessArea(const Shape* f1, const Shape* f2);
bool lessPerimetre(const Shape* f1, const Shape* f2);
bool lessOuterR(const Shape* f1, const Shape* f2);
bool lessInnerR(const Shape* f1, const Shape* f2);

typedef bool (*my_compare) (const Shape*, const Shape*);

typedef int (*tt)(int, int);
std::tuple<Shape**, int> get_shapes(std::string filename);

Shape* find_max(Shape** shapes, int size);

void sort_shapes(Shape** shapes, int size, my_compare);