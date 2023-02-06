#ifndef EXPONENTIAL_NOTATION_HPP
#define EXPONENTIAL_NOTATION_HPP

#include <cmath>

/*
	Exponential notation of type a * 10^exp.
*/
class ExponentialNotation {
private:
	double a;
	int exp;

public:
	/*
		Input:
		 real number that is converted to exponential form.
	*/
	ExponentialNotation(double realNumber);

	/*
		Input:
		 a and exp will be interpreted as: a * 10^exp
	*/
	ExponentialNotation(double a, int exp);

	ExponentialNotation operator/(ExponentialNotation val);

	ExponentialNotation operator*(ExponentialNotation val);

	operator double() const;
};

#endif