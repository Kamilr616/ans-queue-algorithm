#include "Steps.hpp"


Steps::Steps(unsigned double _lambda, unsigned double _mikro, unsigned int _m, unsigned int _N)
{
    this->lambda = _lambda;
    this->mikro = _mikro;
    this->m = _m;
    this->N = _N;
    this->p_ = 0;
    this->pk = 0;
    this->p_pot_k = 0;
    this->k = 0;
    this->k_silnia = 0;
    this->p0 = 0;

    step1();

}

void Steps::step1()
{
    //pierwszy wzór
    this->p_ = (this->lambda/this->mikro);

    //drugi wzór
    //k silnia 
    Factorial k_silnia_new(k);
    this->k_silnia = (unsigned int)k_silnia_new.getFactorial();

    this->p_pot_k = pow(this->p_ , this->k);
    this->pk = (this->p_pot_k/this->k_silnia) * this->p0;

}


string Steps::printRo()
{
    string result = "1";

    return result;
}

string Steps::printP0()
{
    string result = to_string(this->p0);
    return result;
}

string Steps::printP1()
{
    string result = "3";

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


Steps::~Steps(){


}
