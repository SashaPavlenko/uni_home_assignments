#include "Conscript.h"

Conscript::Conscript() : student("Ivanov", 1, 1), year_of_con{ 2021 }, height{ 178 }, size_of_shoes{41}
{
}

Conscript::Conscript(string name, int year, int _height, int size): student(name, 2021-year+1, 1), \
year_of_con{ year }, height{ _height }, size_of_shoes{ size } {}

void Conscript::print(std::ostream& os) {
    os << this->get_name() << " " << this->get_course() << "." << this->get_group() << "\n";
    os << "Year of conscription: " << year_of_con << "\nHeight - " << height << ", size of shoes - " \
        << size_of_shoes << ";\n";

}