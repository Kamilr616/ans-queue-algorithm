#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include "global.hpp"

using namespace std;

class Factorial
{
public:
    // constructor
    Factorial(int n);

    // destructor
    ~Factorial();

    // member functions
    void printFactorial();
    int multiply(int x, int Tres_size);

    private :
    // member variables
    int n;
    int res[MAX];
    int res_size;
};

#endif // FACTORIAL_HPP