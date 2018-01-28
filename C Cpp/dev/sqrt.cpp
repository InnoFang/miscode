#include<iostream>
#include<cmath>
#include<cassert>

double sqrt(double a) {
	assert( a >= 0 );
	double err = 1e-15;
	double t = a;
	while (std::abs(t - a / t) > err * t)
		  t = (a / t + t) / 2.0;
    return t;
}

int main() {
	double a = 8;
	std::cout << sqrt(a) << std::endl;
	return 0;
}
