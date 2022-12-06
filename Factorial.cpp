#include "headers/Factorial.hpp"

// This function finds factorial of large numbers
// and prints them
Factorial::Factorial(int _n)
{
    // Initialize result
    this->n = _n;
    this->res[0] = 1;
    this->res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3
    // * 4...*n
    for (int x = 2; x <= n; x++)
        this->res_size = multiply(x, this->res_size);

}

void Factorial::printFactorial(){
    cout << "\n Silnia dla n = "<< n << " wynosi: \n";
    for (int i = this->res_size - 1; i >= 0; i--)
        cout << this->res[i];
}


// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function returns the
// new value of res_size
int Factorial::multiply(int x, int Tres_size)
{
    int carry = 0; // Initialize carry

    // One by one multiply n with individual digits of res[]
    for (int i = 0; i < Tres_size; i++)
    {
        int prod = this->res[i] * x + carry;

        // Store last digit of 'prod' in res[]
        this->res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and increase result size
    while (carry)
    {
        this->res[Tres_size] = carry % 10;
        carry = carry / 10;
        Tres_size++;
    }
    return Tres_size;
}
Factorial::~Factorial(){
}