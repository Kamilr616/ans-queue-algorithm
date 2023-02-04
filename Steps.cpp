#include "Steps.hpp"


Steps::Steps(double _lambda, double _mikro, unsigned int _m, unsigned int _N) : p0(0)
{
    this->lambda = _lambda;
    this->mikro = _mikro;
    this->m = _m;
    this->N = _N;
    this->ro = (_lambda / _mikro);

    Factorial mFactorial(m);
    this->mFactorialValue = mFactorial.getFactorial();

    // 1. Warunek normalizujący.

    calculateP0(); // calculate p0 according to ro / m

    p1 = probabilityAtIndex(1);
    pOdm = probabilityAtIndex(m + N);
    m0Mean = lambda * (1 - pOdm) / mikro;
    mZnMean = m - m0Mean;
    vMean = (pow(m, m) / mFactorialValue) * N * (N + 1.0) * p0 / Factorial(m-1).getFactorial();
    nMean = vMean + m0Mean;
    tf = vMean / lambda;
    ts = tf + (1 / mikro) * (1 - pow(ro, m + N) * p0 / (pow(m, N) * mFactorialValue));

}

void Steps::calculateP0()
{
    //drugi wzór?
    //m silnia 
    /*Factorial m_silnia_new(m);
    this->m_silnia = (unsigned int)m_silnia_new.getFactorial();*/

    //this->p_pot_m = pow(this->ro , this->m);

    // ---
    double sum = 0, roDivM = ro / m;
    if (roDivM == 1) {
        for (int k = 0; k <= m - 1; k++) {
            sum += pow(ro, k) / Factorial(k).getFactorial();
        }
        p0 = 1 / (sum + (pow(ro, m) / mFactorialValue) * (N+1.0));
    }
    else {
        for (int k = 0; k <= m - 1; k++) {
            sum += pow(ro, k) / Factorial(k).getFactorial();
        }
        
        p0 = 1 / (sum + (pow(ro, m) / mFactorialValue) * (1 - (pow(roDivM, N + 1.0)) / (1 - roDivM)));
    }
}

double Steps::probabilityAtIndex(int index)
{
    Factorial factorial(index);
    if (1 <= index && index <= m - 1) { // dla k
        return (pow(ro, index) / factorial.getFactorial()) * p0;
    }
    else if (m <= index && index <= m + N) { // dla j
        return (pow(ro, index) / (pow(m, index - m) * factorial.getFactorial())) * p0;
    }
    else {
        throw invalid_argument("Given index is out of range.");
    }
}

double Steps::getRo() {
    return ro;
}

double Steps::getP0() {
    return p0;
}

double Steps::getP1() {
    return p1;
}

double Steps::getPOdm() {
    return pOdm;
}

double Steps::getM0Mean()
{
    return m0Mean;
}

double Steps::getMZnMean()
{
    return mZnMean;
}

double Steps::getVMean()
{
    return vMean;
}

double Steps::getNMean()
{
    return nMean;
}

double Steps::getTf()
{
    return tf;
}

double Steps::getTs()
{
    return ts;
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
