#ifndef STEPS_HPP
#define STEPS_HPP

#include "global.hpp"

using namespace std;



class Steps
{
private:

    double lambda;
    double mikro;
    int m;
    int N;
    int test;

    void step1();

public:

    Steps(double _lambda, double _mikro, int _m, int _N);
    ~Steps();

    String printRo();
    String printP0();
    String printP1();
    String printP0dm();
    String printM0sr();
    String printMznsr();
    String printVsr();
    String printNsr();
    String printTf();
    String printTs();

};
#endif // STEPS_HPP