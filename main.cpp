#include <iostream>
#include <math.h>
#include <functional>

#include "sin.hpp"

double max_error(std::function<double(double)> ourFunction,
                 std::function<double(double)> referenceFunction,
                 double rangeLower,
                 double rangeUpper)
{
	const double steps = 60000;

	double maxError = 0;
	for (double x = rangeLower; x <= rangeUpper; x += (rangeUpper - rangeLower) / steps) {
		double error = referenceFunction(x) - ourFunction(x);
		if (std::abs(error) > std::abs(maxError)) {
			maxError = error;
		}
	}
	return maxError;
}

double orig_sin(double x) {
	return sin(x);
}

int main() {
	{
		std::cout << "Range -Pi to Pi" << std::endl;

		double sinErr = max_error(orig_sin, orig_sin, -M_PI, M_PI);
		std::cout << "Max error of orig_sin(): " << sinErr << std::endl;

		double ourSinErr = max_error(our_sin_branchless, orig_sin, -M_PI, M_PI);
		std::cout << "Max error of our_sin(): " << ourSinErr << std::endl;
		std::cout << std::endl;
	}
}
