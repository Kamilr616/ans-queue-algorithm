#ifndef STEPS_HPP
#define STEPS_HPP

#include "global.hpp"
#include "Factorial.hpp"

using namespace std;



class Steps
{
private:

    unsigned double lambda;
    unsigned double mikro;
    unsigned int m;
    unsigned int N;
    unsigned int p_;
    unsigned int pk;
    unsigned int p_pot_k;
    unsigned int k;
    unsigned int k_silnia;
    unsigned int p0;    

    void step1();

public:

    Steps(unsigned double _lambda, unsigned double _mikro, unsigned int _m, unsigned int _N);
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
