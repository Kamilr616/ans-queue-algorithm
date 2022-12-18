#include "headers/global.hpp"
#include "Factorial.cpp"

using namespace std;


int main()
{
    int n1;
    cout << " Podaj n (silnia) >> ";
    cin >> n1;
    Factorial A(n1);
    A.printFactorial();
    A.printFactorialExp();
    unsigned int A0;
    A0 = A.getFactorial();
    cout << "\n getFactorial() >> " << A0;

    return 0;
}