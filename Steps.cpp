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


String Steps::printRo()
{
    String result = "1";

    return result;
}

String Steps::printP0()
{
    String result = "2";

    return result;
}

String Steps::printP1()
{
    String result = "3";

    return result;
}

String Steps::printP0dm()
{
    String result = "4";

    return result;
}

String Steps::printM0sr()
{
    String result = "5";

    return result;
}

String Steps::printMznsr()
{
    String result = "6";

    return result;
}

String Steps::printVsr()
{
    String result = "7";

    return result;
}

String Steps::printNsr()
{
    String result = "8";

    return result;
}

String Steps::printTf()
{
    String result = "9";

    return result;
}

String Steps::printTs()
{
    String result = "10";

    return result;
}


Steps::~Steps(){


}