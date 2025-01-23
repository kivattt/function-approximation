#ifndef SIN_HPP
#define SIN_HPP

#include <math.h>

double our_sin1(double x) {
	double a = -(4 / (M_PI * M_PI));
	double b = 4 / M_PI;

	if (x < 0)
		return -a * (x*x) + b*x;
	else
		return a * (x*x) + b*x;
}

double our_sin_branchless(double x) {
	double a = -(4 / (M_PI * M_PI));
	double b = 4 / M_PI;

	return (((std::signbit(x) ^ 1) << 1) - 1) * a * (x*x) + b*x;
}

#endif // SIN_HPP
