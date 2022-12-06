#include "headers/global.hpp"
#include "headers/Factorial.hpp"
#include "Factorial.cpp"

using namespace std;

int multiply(int x, int res[], int res_size);


int main()
{
    int n1;
    cout << "Podaj n (silnia) >> ";
    cin >> n1;
    Factorial A(n1);
    A.printFactorial();

    return 0;
}