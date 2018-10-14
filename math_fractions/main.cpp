#include <iostream>
#include "fraction.h"

int main()
{
	int a, b;
	std::cin >> a >> b;
	auto f = fraction::create_fraction(a, b);
	std::cout << int(f.get_sign()) << " " << f.get_numerator() << " " << f.get_denominator();
}