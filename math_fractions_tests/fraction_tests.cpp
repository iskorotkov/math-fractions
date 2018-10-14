#include "CppUnitTest.h"
#include "../math_fractions/fraction.h"
#include "../math_fractions/fraction.cpp"
#include "../math_fractions/fraction_utility.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace creating_fractions
{
	TEST_CLASS(assigning_numerator_and_denumerator)
	{
	public:

		TEST_METHOD(create_positive_fraction)
		{
			auto f = fraction::create_fraction(5, 4);
			Assert::AreEqual<unsigned int>(5, f.get_numerator());
			Assert::AreEqual<unsigned int>(4, f.get_denominator());
		}

		TEST_METHOD(create_negative_fraction)
		{
			auto f = fraction::create_fraction(-5, 4);
			Assert::AreEqual<unsigned int>(5, f.get_numerator());
			Assert::AreEqual<unsigned int>(4, f.get_denominator());
		}

		TEST_METHOD(create_zero_fraction)
		{
			auto f = fraction::create_fraction(0, 1);
			Assert::AreEqual<unsigned int>(0, f.get_numerator());
			Assert::AreEqual<unsigned int>(1, f.get_denominator());
		}

		TEST_METHOD(create_fraction_with_zero_denominator)
		{
			Assert::ExpectException<std::exception>([] {fraction::create_fraction(5, 0); });
		}

		TEST_METHOD(both_values_negative)
		{
			auto f = fraction::create_fraction(-4, -5);
			Assert::AreEqual<unsigned int>(4, f.get_numerator());
			Assert::AreEqual<unsigned int>(5, f.get_denominator());
		}
	};

	TEST_CLASS(reducing_fractions)
	{
	public:
		TEST_METHOD(create_for_reducing)
		{
			auto f = fraction::create_fraction(8, 2);
			Assert::AreEqual<unsigned int>(4, f.get_numerator());
			Assert::AreEqual<unsigned int>(1, f.get_denominator());
		}

		TEST_METHOD(create_negative_for_reducing)
		{
			auto f = fraction::create_fraction(-10, 4);
			Assert::AreEqual<unsigned int>(5, f.get_numerator());
			Assert::AreEqual<unsigned int>(2, f.get_denominator());
		}

		TEST_METHOD(create_zero_for_reducing)
		{
			auto f = fraction::create_fraction(0, 8);
			Assert::AreEqual<unsigned int>(0, f.get_numerator());
			Assert::AreEqual<unsigned int>(1, f.get_denominator());
		}
	};

	TEST_CLASS(fraction_signs)
	{
	public:
		TEST_METHOD(check_positive_sign)
		{
			auto f = fraction::create_fraction(10, 4);
			Assert::IsTrue(f.is_positive());
			Assert::IsFalse(f.is_negative());
			Assert::IsFalse(f.is_zero());
		}

		TEST_METHOD(check_negative_sign)
		{
			auto f = fraction::create_fraction(-10, 4);
			Assert::IsFalse(f.is_positive());
			Assert::IsTrue(f.is_negative());
			Assert::IsFalse(f.is_zero());
		}

		TEST_METHOD(check_zero_sign)
		{
			auto f = fraction::create_fraction(0, 4);
			Assert::IsFalse(f.is_positive());
			Assert::IsFalse(f.is_negative());
			Assert::IsTrue(f.is_zero());
		}

		TEST_METHOD(both_values_negative)
		{
			auto f = fraction::create_fraction(-4, -5);
			Assert::IsTrue(f.is_positive());
			Assert::IsFalse(f.is_negative());
			Assert::IsFalse(f.is_zero());
		}
	};
}

namespace fraction_properties
{
	TEST_CLASS(common_fractions)
	{
	public:
		TEST_METHOD(uncommon_fraction)
		{
			auto f = fraction::create_fraction(5, 4);
			Assert::IsFalse(f.is_common());
		}

		TEST_METHOD(common_fraction)
		{
			auto f = fraction::create_fraction(4, 5);
			Assert::IsTrue(f.is_common());
		}
	};
}

namespace fraction_conversions
{
	TEST_CLASS(fraction_to_double)
	{
	public:
		TEST_METHOD(negative_fraction)
		{
			auto f = fraction::create_fraction(-5, 4);
			Assert::AreEqual(-5. / 4., double(f));
		}

		TEST_METHOD(positive_fraction)
		{
			auto f = fraction::create_fraction(12, 6);
			Assert::AreEqual(12. / 6., double(f));
		}

		TEST_METHOD(zero_fraction)
		{
			auto f = fraction::create_fraction(0, 11);
			Assert::AreEqual(0., double(f));
		}
	};

	TEST_CLASS(fraction_to_string)
	{
	public:
		TEST_METHOD(positive_fraction)
		{
			auto f = fraction::create_fraction(6, 5);
			Assert::AreEqual<std::string>("6/5", std::string(f));
		}

		TEST_METHOD(negative_fraction)
		{
			auto f = fraction::create_fraction(-6, 7);
			Assert::AreEqual<std::string>("-6/7", std::string(f));
		}

		TEST_METHOD(zero_fraction)
		{
			auto f = fraction::create_fraction(0, 5);
			Assert::AreEqual<std::string>("0", std::string(f));
		}

		TEST_METHOD(positive_reduced_fraction)
		{
			auto f = fraction::create_fraction(4, 12);
			Assert::AreEqual<std::string>("1/3", std::string(f));
		}

		TEST_METHOD(negative_reduced_fraction)
		{
			auto f = fraction::create_fraction(-8, 4);
			Assert::AreEqual<std::string>("-2/1", std::string(f));
		}
	};
}