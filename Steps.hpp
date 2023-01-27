#ifndef STEPS_HPP
#define STEPS_HPP

#include "global.hpp"

using namespace std;



class Factorial
{
private:

    double lambda;
    double mikro;
    int m;
    int N;
    int test;

    void step1();

public:
    Steps(double _lambda; double _mikro; int _m; int _N;);

    ~Steps();

};
#endif // STEPS_HPP