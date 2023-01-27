#include "Steps.hpp"



Steps::Steps(double _lambda, double _mikro, int _m, int _N)
{
    this->lambda = _lambda;
    this->mikro = _mikro;
    this->m = _m;
    this->N = _N;

    step1();

}

void Steps::step1()
{
    int l = this->lambda;

}


string Steps::printRo()
{
    string result = "1";

    return result;
}

string Steps::printP0()
{
    string result = "2";

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
