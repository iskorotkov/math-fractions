#pragma once
class fraction
{
	enum class number_sign : char { zero = 0, positive = 1, negative = -1 };

public:
	// Constructors
	fraction(fraction&& f) = default;
	fraction(const fraction& f) = default;
	fraction& operator=(fraction&& f) = default;
	fraction& operator=(const fraction& f) = default;

	// Factory
	static fraction&& create_fraction(int numerator, int denominator);

	// Relations
	bool operator==(const fraction& f) const;
	bool operator!=(const fraction& f) const;
	bool operator<(const fraction& f) const;
	bool operator>(const fraction& f) const;
	bool operator<=(const fraction& f) const;
	bool operator>=(const fraction& f) const;

	// Arithmetic
	fraction& operator+(const fraction& f);
	fraction& operator-(const fraction& f);
	fraction& operator*(const fraction& f);
	fraction& operator/(const fraction& f);
	fraction& operator%(const fraction& f);

	bool is_common() const;
	bool is_positive() const;

private:
	fraction(unsigned int numerator, unsigned int denominator, number_sign sign = number_sign::positive) : numerator(numerator), denominator(denominator), sign(sign) {}

	unsigned int numerator = 1;
	unsigned int denominator = 1;
	number_sign sign = number_sign::positive;

	void reduce();
};
