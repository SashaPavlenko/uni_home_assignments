#include <cmath>

double sum_el(double* a, int num) {
	double sum{ 0.0 };

	for (int i = 0; i < num; i++)
		sum += a[i];

	return sum;
}

double* prod_el(double* a, double* b, double* c, int num) {
	for (int i = 0; i < num; i++)
		*c++ = *a++ * *b++;
	return c;
}

double len_vec(double* a, int num) {
	double sum{ 0.0 };

	for (int i = 0; i < num; i++)
		sum += a[i]*a[i];

	sum = sqrt(sum);

	return sum;
}

double cos_similarity(double* a, double* b, double* c, int size) {

	prod_el(a, b, c, size); 
	double prod_arr{ sum_el(c, size) };
	double len_a{ len_vec(a, size) };
	double len_b{ len_vec(b, size) };

	double cos_sim{ prod_arr / len_a / len_b };

	return cos_sim;
}


double* prod_matrix(double* a, double* b, double* c, int N) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			// c[i][j] = Sum for k from 0 to N (a[i][k] * b[k][j])
			double sum{ 0.0 };
			for (int k = 0; k < N; k++) {
				double a_i_k{ a[i * N + k] };
				double b_k_j{ b[k * N + j] };
				sum += a_i_k * b_k_j;

			}
			c[i * N + j] = sum;
		
		}
	}
	return c;
}


double* tran_matrix(double* a, int size_a) {
	for (int i = 0; i < size_a; i++)
		for (int j = i; j < size_a; j++) {
			// a[index1] = a[i][j].
			// a[index2] = a[j][i].
			int index1{ i * size_a + j }, index2{ j * size_a + i };

			double t = a[index1];
			a[index1] = a[index2];
			a[index2] = t;
		}
	return a;
}

double* flip_matrix_90(double* a, int size_a) {
	tran_matrix(a, size_a);

	for(int j = 0; j < size_a; j++)
		for (int i = 0; i < (size_a / 2); i++) {
			// a[index1] = a[i][j].
			// a[index2] = a[size_a - i - 1][j].
			int index1{ i * size_a + j }, index2{ (size_a - i - 1) * size_a + j };
			
			double t = a[index1];
			a[index1] = a[index2];
			a[index2] = t;
		}
	return a;
}