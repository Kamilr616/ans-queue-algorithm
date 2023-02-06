#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include "global.hpp"

using namespace std;

class Factorial
{
private:

    int n;
    int res[MAX_F];
    int res_size;

    int multiply(int x, int Tres_size);

public:

    Factorial(int _n);
    ~Factorial();

    void getExponentialForm(double& x, int& y);
    unsigned long long getFactorial();

};

#endif // FACTORIAL_HPP
