#ifndef STEPS_HPP
#define STEPS_HPP

#include "global.hpp"
#include "Factorial.hpp"

using namespace std;

class Steps
{
private:

    const double lambda, mikro, m, N;
    double ro, p0, p1, pOdm, m0Mean, mZnMean, vMean, nMean, tf, ts;
    unsigned long long mFactorialValue;

    void calculateAll();
    void calculateP0();
    void calculateVMean();
    double probabilityAtIndex(int index);

public:

    Steps(const double _lambda, const double _mikro, const unsigned int _m, const unsigned int _N);
    ~Steps();

    string probabilitesAtRange(const unsigned int from, const unsigned int to);

    string printRo();
    string printP0();
    string printP1();
    string printP0dm();
    string printM0sr();
    string printMznsr();
    string printVsr();
    string printNsr();
    string printTf();
    string printTs();

};

#endif // STEPS_HPP
