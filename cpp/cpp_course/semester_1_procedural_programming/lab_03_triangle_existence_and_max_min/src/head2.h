#ifndef HEAD2_H
#define HEAD2_H

#include "funcs.h"

/*
int f1() {
	return 0;
}
*/

enum triangle_type{
	tRight, // Right.
	tAcute, // Acute.
	tObtuse, // Obtuse.
};

triangle_type x = tRight;
triangle_type y = static_cast <triangle_type> (1);
#endif // !HEAD2_H