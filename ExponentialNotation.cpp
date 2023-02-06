#include "ExponentialNotation.hpp"

ExponentialNotation::ExponentialNotation(double realNumber) : exp(0), a(realNumber)
{
    if (a <= -1 || 1 <= a) {
        while (10.0 <= abs(a)) {
            a /= 10.0;
            exp++;
        }
    }
    else {
        while (abs(a) < 1) {
            a *= 10.0;
            exp--;
        }
    }
}

ExponentialNotation::ExponentialNotation(double a, int exp)
{
	this->a = a;
	this->exp = exp;
}

ExponentialNotation ExponentialNotation::operator/(ExponentialNotation val)
{
	return ExponentialNotation(this->a / val.a, this->exp - val.exp);
}

ExponentialNotation ExponentialNotation::operator*(ExponentialNotation val)
{
    return ExponentialNotation(this->a * val.a, this->exp + val.exp);
}

ExponentialNotation::operator double() const
{
    return a * pow(10, exp);
}

