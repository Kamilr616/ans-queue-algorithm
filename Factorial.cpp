#include "Factorial.hpp"

Factorial::Factorial(int _n)
{
    this->n = _n;
    this->res[0] = 1;
    this->res_size = 1;

    for (int x = 2; x <= n; x++)
    {
        this->res_size = multiply(x, this->res_size);
    }
}

unsigned long long Factorial::getFactorial()
{
    unsigned long long out = 0;

    for (int i = this->res_size - 1; i >= 0; i--)
    {
        out += ((this->res[i]) * pow(10, i));
    }
    return out;
}

int Factorial::multiply(int x, int Tres_size)
{
    int carry = 0;

    for (int i = 0; i < Tres_size; i++)
    {
        int prod = this->res[i] * x + carry;
        this->res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        this->res[Tres_size] = carry % 10;
        carry = carry / 10;
        Tres_size++;
    }
    return Tres_size;
}

void Factorial::getExponentialForm(double& x, int& y)
{
    double x_result = 0;
    int y_result = (res_size - 1);
    double j = 1;

    for (int i = 1; i <= 6; i++, j /= 10)
    {
        x_result += res[res_size - i] * j;
    }

    x = x_result;
    y = y_result;
}

Factorial::~Factorial(){
}
