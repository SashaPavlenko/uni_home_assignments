# C++ course (Southern Federal University)

Labs, individual assignments and tests from a two-semester C++ course. Each folder contains the sources (`src/`) and, where the task asked for them, unit tests (`tests/`). Project files and build output are not included; comments and output strings are translated from Russian.

**Technologies:** C++, STL (`std::string`, `map`, `tuple`, `fstream`), dynamic memory and pointers, exceptions, templates, operator overloading, inheritance and virtual functions, move semantics, Visual Studio with Microsoft CppUnitTest, CRT debug heap for leak detection.

**What I did:** procedural programming in the first semester (numbers, arrays, matrices, strings, text and binary files) and object-oriented programming in the second (own list, array, tree and big-number classes, class hierarchies, a set on a tree).

## [Semester 1 - procedural programming](semester_1_procedural_programming)

- [lab_02_digits_of_a_number](semester_1_procedural_programming/lab_02_digits_of_a_number) - counting digits, digit sum and reformatting a number
- [lab_02_hw_triangle_geometry](semester_1_procedural_programming/lab_02_hw_triangle_geometry) - points, distances, triangle area, type and distance to a line
- [lab_03_triangle_existence_and_max_min](semester_1_procedural_programming/lab_03_triangle_existence_and_max_min) - triangle existence check, inline min / max functions
- [lab_03_hw_triangle_geometry](semester_1_procedural_programming/lab_03_hw_triangle_geometry) - homework version of the triangle geometry task
- [lab_04_bit_operations](semester_1_procedural_programming/lab_04_bit_operations) - setting, clearing and checking bits, binary printing
- [lab_04_hw_binary_output](semester_1_procedural_programming/lab_04_hw_binary_output) - printing a number in binary form
- [series_sum_and_number_digits](semester_1_procedural_programming/series_sum_and_number_digits) - sum of the first N terms of a series, digit manipulation of integers
- [lab_06_number_digits](semester_1_procedural_programming/lab_06_number_digits) - functions on the digits of an integer, with unit tests
- [lab_07_array_vectors](semester_1_procedural_programming/lab_07_array_vectors) - arrays as vectors: sums, products, lengths, proportionality
- [lab_08_median_quickselect](semester_1_procedural_programming/lab_08_median_quickselect) - median via quickselect, random element, quicksort
- [lab_09_dynamic_arrays](semester_1_procedural_programming/lab_09_dynamic_arrays) - dynamic arrays: insertion, deletion, duplicates, binary search
- [lab_10_arithmetic_means_and_function_tables](semester_1_procedural_programming/lab_10_arithmetic_means_and_function_tables) - means before / after a zero, tabulating a function given as a parameter
- [lab_11_static_matrices](semester_1_procedural_programming/lab_11_static_matrices) - fixed-size matrices: rows with zeros, inserting and deleting rows
- [lab_12_dynamic_matrices](semester_1_procedural_programming/lab_12_dynamic_matrices) - matrices in dynamic memory, determinant, transposition, row / column deletion, error codes
- [lab_13_c_strings](semester_1_procedural_programming/lab_13_c_strings) - C strings: comparison, removing and inserting characters
- [lab_14_std_string_words](semester_1_procedural_programming/lab_14_std_string_words) - `std::string`: counting words, deleting characters, inserting substrings, replacing even words
- [lab_15_text_files_letters_and_words](semester_1_procedural_programming/lab_15_text_files_letters_and_words) - text files: letter statistics, longest line, word counting
- [lab_16_text_files_real_numbers](semester_1_procedural_programming/lab_16_text_files_real_numbers) - text files of real numbers: minimum by absolute value, per-line min / max, comparing files
- [lab_17_text_file_points](semester_1_procedural_programming/lab_17_text_file_points) - reading points from a file and finding the farthest pair
- [lab_18_binary_files](semester_1_procedural_programming/lab_18_binary_files) - binary files of real numbers and of structures
- [individual_1_number_functions](semester_1_procedural_programming/individual_1_number_functions) - individual task: digit functions and a Fresnel integral, with unit tests
- [individual_2_arrays_and_function_pointers](semester_1_procedural_programming/individual_2_arrays_and_function_pointers) - individual task: sign alternation, replacing negatives, matrix sums by a condition (function pointers)
- [individual_3_files_and_structures](semester_1_procedural_programming/individual_3_files_and_structures) - individual task: text and binary files, student records
- [test_2_array_tasks](semester_1_procedural_programming/test_2_array_tasks) - test: array processing (product after the last zero, deleting between extrema)
- [test_3_string_tasks](semester_1_procedural_programming/test_3_string_tasks) - test: removing a character, inserting a word
- [test_4_arrays_strings_files](semester_1_procedural_programming/test_4_arrays_strings_files) - test: arrays, strings and file processing

## [Semester 2 - object-oriented programming](semester_2_object_oriented_programming)

- [lab_01_singly_linked_list](semester_2_object_oriented_programming/lab_01_singly_linked_list) - singly linked list on pointers
- [lab_02_point_class](semester_2_object_oriented_programming/lab_02_point_class) - `Point` class with polar coordinates
- [lab_03_fraction_and_time_classes](semester_2_object_oriented_programming/lab_03_fraction_and_time_classes) - `Fract` and `Time` classes
- [lab_04_array_class](semester_2_object_oriented_programming/lab_04_array_class) - dynamic `Array` class with operator overloading
- [lab_05_long_arithmetic](semester_2_object_oriented_programming/lab_05_long_arithmetic) - long arithmetic (`bignum`) built on `Array`
- [lab_06_move_semantics](semester_2_object_oriented_programming/lab_06_move_semantics) - move constructor and move assignment
- [lab_07_solids_inheritance](semester_2_object_oriented_programming/lab_07_solids_inheritance) - inheritance: `Circle`, `Cylinder`, `Cone`, `Sphere`
- [lab_08_array_class_extension](semester_2_object_oriented_programming/lab_08_array_class_extension) - extending `Array` (`swap` and other methods)
- [lab_09_shapes_polymorphism](semester_2_object_oriented_programming/lab_09_shapes_polymorphism) - polymorphic shapes: `Shape`, `Polygon`, `Triangle`, `Square`
- [lab_10_doubly_linked_list](semester_2_object_oriented_programming/lab_10_doubly_linked_list) - doubly linked list with memory leak checking
- [lab_11_binary_tree](semester_2_object_oriented_programming/lab_11_binary_tree) - binary tree and its traversals
- [individual_1_telephone_exchange](semester_2_object_oriented_programming/individual_1_telephone_exchange) - individual task: telephone exchange class (`ATS`)
- [individual_2_road_signs_hierarchy](semester_2_object_oriented_programming/individual_2_road_signs_hierarchy) - individual task: hierarchy of road signs with virtual functions
- [individual_3_set_on_binary_tree](semester_2_object_oriented_programming/individual_3_set_on_binary_tree) - individual task: set implemented on a recursive binary tree
- [test_1_point_class](semester_2_object_oriented_programming/test_1_point_class) - test: `Point` class with comparison
- [test_2_student_hierarchy](semester_2_object_oriented_programming/test_2_student_hierarchy) - test: `Student`, `Postgraduate`, `Conscript` hierarchy
- [test_3_template_tree](semester_2_object_oriented_programming/test_3_template_tree) - test: template tree `MyTree<T>`
- [test_4_inheritance_experiments](semester_2_object_oriented_programming/test_4_inheritance_experiments) - test: inheritance and type conversion experiments
