#include <iostream>
#include <math.h>
#include <functional>

#define PI 3.141592653589793238462643383279

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

/*double our_sin(double x) {
	double a = -(4 / (PI * PI));
	double b = 4 / PI;
	double c = 0;
	return a * (x*x) + b*x + c;
}*/

double our_sin(double x) {
	double a = -(4 / (M_PI * M_PI));
	double b = 4 / M_PI;

	if (x < 0)
		return -a * (x*x) + b*x;
	else
		return a * (x*x) + b*x;
}

int main() {
	/*{
		std::cout << "Range 0 to Pi" << std::endl;

		double sinErr = max_error(orig_sin, orig_sin, 0, PI);
		std::cout << "Max error of orig_sin(): " << sinErr << std::endl;

		double ourSinErr = max_error(our_sin, orig_sin, 0, PI);
		std::cout << "Max error of our_sin(): " << ourSinErr << std::endl;
		std::cout << std::endl;
	}*/

	/*{
		std::cout << "Range -Pi to Pi" << std::endl;

		double sinErr = max_error(orig_sin, orig_sin, -PI, PI);
		std::cout << "Max error of orig_sin(): " << sinErr << std::endl;

		double ourSinErr = max_error(our_sin, orig_sin, -PI, PI);
		std::cout << "Max error of our_sin(): " << ourSinErr << std::endl;
		std::cout << std::endl;
	}*/

	{
		std::cout << "Range -Pi to Pi" << std::endl;

		double sinErr = max_error(orig_sin, orig_sin, -PI, PI);
		std::cout << "Max error of orig_sin(): " << sinErr << std::endl;

		double ourSinErr = max_error(our_sin, orig_sin, -PI, PI);
		std::cout << "Max error of our_sin(): " << ourSinErr << std::endl;
		std::cout << std::endl;
	}
}
