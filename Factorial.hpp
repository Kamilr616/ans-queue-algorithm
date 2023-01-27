#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP

#include "global.hpp"

using namespace std;

// This class contains functions to find factorial of large numbers
// and print/return the result
class Factorial
{
private:
    // 'n' is the number for which we want to find the factorial
    // 'res' is an array to store the result
    // 'res_size' is the size of the 'res' array
    int n;
    int res[MAX];
    int res_size;

    // This function multiplies x with the number represented by res[]
    // 'Tres_size' is the size of the 'res' array or number of digits in the
    // number represented by 'res[]'
    // This function uses simple school mathematics for multiplication
    // It returns the new value of 'res_size'
    int multiply(int x, int Tres_size);

public:
    // Constructor to initialize 'n' and other class variables
    Factorial(int _n);
    // Destructor
    ~Factorial();

    // This function prints the factorial of 'n'
    void printFactorial();

    // This function prints the factorial of 'n' in exponential notation
    void printFactorialExp();

    // This function returns the factorial of 'n' as an unsigned int
    unsigned long long getFactorial();
};

#endif // FACTORIAL_HPP