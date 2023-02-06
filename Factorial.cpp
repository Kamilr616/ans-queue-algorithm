#include "Factorial.hpp"

// This function finds the factorial of 'n' and stores the result in the 'res' array
// 'res_size' is updated to the size of the result
Factorial::Factorial(int _n)
{
    // Initialize result
    this->n = _n;
    this->res[0] = 1;
    this->res_size = 1;

    // Apply simple factorial formula n! = 1 * 2 * 3 * 4...*n
    for (int x = 2; x <= n; x++)
        this->res_size = multiply(x, this->res_size);
}

// This function prints the factorial of 'n' stored in the 'res' array
void Factorial::printFactorial(){
    cout << "\n Factorial of n = "<< n << " is: \n";
    for (int i = this->res_size - 1; i >= 0; i--)
        cout << this->res[i];
}

// This function returns the factorial of 'n' stored in the 'res' array as an unsigned int
unsigned long long Factorial::getFactorial(){
    unsigned long long out = 0;
    for (int i = this->res_size - 1; i >= 0; i--)
        out += ((this->res[i]) * pow(10, i));
        
    return out;
}

// This function multiplies x with the number represented by res[]
// 'Tres_size' is the size of the 'res' array or number of digits in the
// number represented by 'res[]'
// This function uses simple school mathematics for multiplication
// It returns the new value of 'res_size'
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

void Factorial::getExponentialForm(double &x, int &y)
{
    int trailing_zeros = 0;
    for (int i = this->res_size - 1; i >= 0; i--)
    {
        if (this->res[i] == 0)
            trailing_zeros += 1;
        else
            break;
    }

    double result = 0.0;
    int magnitude = 1;
    for (int i = 0; i < this->res_size - trailing_zeros; i++)
    {
        result = result * magnitude + this->res[i];
        magnitude *= 10;
    }

    x = result;
    y = trailing_zeros;
}

Factorial::~Factorial(){
}