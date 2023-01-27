#include "Steps.hpp"


Steps::Steps(double _lambda, double _mikro, unsigned int _m, unsigned int _N)
{
    this->lambda = _lambda;
    this->mikro = _mikro;
    this->m = _m;
    this->N = _N;
    this->ro = (_lambda / _mikro);

    this->p0 = 0;
    this->p1 = 0;

    //step1();

}

void Steps::step1()
{
    //drugi wzór?
    //m silnia 
    Factorial m_silnia_new(m);
    this->m_silnia = (unsigned int)m_silnia_new.getFactorial();

    //this->p_pot_m = pow(this->ro , this->m);

}


string Steps::printRo()
{
    string result = to_string(this->ro);   
    return result;
}

string Steps::printP0()
{
    string result = to_string(this->p0);
    return result;
}

string Steps::printP1()
{
    string result = to_string(this->p1);
    return result;
}

string Steps::printP0dm()
{
    string result = "4";

    return result;
}

string Steps::printM0sr()
{
    string result = "5";

    return result;
}

string Steps::printMznsr()
{
    string result = "6";

    return result;
}

string Steps::printVsr()
{
    string result = "7";

    return result;
}

string Steps::printNsr()
{
    string result = "8";

    return result;
}

string Steps::printTf()
{
    string result = "9";

    return result;
}

string Steps::printTs()
{
    string result = "10";

    return result;
}


Steps::~Steps()
{


}
