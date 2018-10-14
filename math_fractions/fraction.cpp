#include "fraction.h"
#include <assert.h>
#include <utility>
#include <string>
#include <ostream>
#include <sstream>
#include "fraction_utility.h"

fraction fraction::create_fraction(int numerator, int denominator)
{
	assert(denominator);

	auto sign = numerator * denominator > 0 ? number_sign::positive : numerator == 0 ? number_sign::zero : number_sign::negative;
	return fraction(abs(numerator), abs(denominator), sign)
		.reduce();
}

unsigned int fraction::get_numerator() const
{
	return numerator;
}

unsigned int fraction::get_denominator() const
{
	return denominator;
}

fraction::number_sign fraction::get_sign() const
{
	return sign;
}

bool fraction::is_positive() const
{
	return sign == number_sign::positive;
}

bool fraction::is_negative() const
{
	return sign == number_sign::negative;
}

bool fraction::is_zero() const
{
	return sign == number_sign::zero;
}

bool fraction::is_common() const
{
	return numerator < denominator;
}

std::string fraction::to_string() const
{
	if (sign == number_sign::zero)
	{
		return { "0" };
	}
	else
	{
		std::ostringstream out_string;
		if (sign == number_sign::negative)
		{
			out_string << '-';
		}
		out_string << numerator << '/' << denominator;
		return out_string.str();
	}
}

fraction& fraction::reduce()
{
	auto gcd = fraction_utility::greatest_common_divider(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const fraction& f)
{
	stream << f.to_string();
	return stream;
}