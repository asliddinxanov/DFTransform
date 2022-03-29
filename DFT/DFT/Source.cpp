/*DFT (discrete fourier transform)*/
/*asliddinxanov*/
/*2022-02-29*/

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#define N 1000
#define dT 0.01
#define PI (M_PI)

double wave_f(double t) {
	return 4 * sin(2 * PI * 4 * t) + 2 * cos(2 * PI * 7 * t);
}
int main(void) {

	double fx[N], r, im;
	for (int i = 0; i < N; i++)
		fx[i] = wave_f(i*dT);

	for (int k = 0;k < N;k++) {
		r = 0;
		im = 0;
		for (int n = 0;n < N;n++) {
			r += fx[n] * cos((2 * PI / N)*k*n);
			im -= fx[n] * sin((2 * PI / N)*k*n);
		}
		printf("%f %f %f %f\n", k / (N*dT), 2 * r, 2 * im, 2 * sqrt(r*r + im * im));
	}
	return 0;
}