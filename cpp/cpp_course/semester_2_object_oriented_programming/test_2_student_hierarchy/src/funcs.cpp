#include "funcs.h"
#include "student.h"

bool course_less(const student* s1, const student* s2)
{
	return s1->get_course() < s2->get_course();
}
