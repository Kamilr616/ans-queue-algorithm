#ifndef STEPS_HPP
#define STEPS_HPP

#include <cmath>
#include "global.hpp"
#include "Factorial.hpp"
#include "ExponentialNotation.hpp"

using namespace std;

typedef ExponentialNotation ExpNot;

class Steps
{
private:

    unsigned long long mFactorialValue;

    double lambda, mikro, ro, p0, p1, pOdm, m0Mean, mZnMean, vMean, nMean, tf, ts, m, N;

    void calculateAll();
    void calculateP0();
    void calculateVMean();
    double probabilityAtIndex(int index);

public:

    Steps(double _lambda, double _mikro, unsigned int _m, unsigned int _N);
    ~Steps();

    double getRo();
    double getP0();
    double getP1();
    double getPOdm();
    double getM0Mean();
    double getMZnMean();
    double getVMean();
    double getNMean();
    double getTf();
    double getTs();

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
