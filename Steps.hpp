#ifndef STEPS_HPP
#define STEPS_HPP

#include "global.hpp"
#include "Factorial.hpp"

using namespace std;


class Steps
{
private:

    double lambda;
    double mikro;
    unsigned int m;
    unsigned int N;

    double ro;
    double p0;    
    double p1;    

    unsigned int m_silnia;

    void step1();

public:

    Steps(double _lambda, double _mikro, unsigned int _m, unsigned int _N);
    ~Steps();

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
