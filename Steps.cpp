#include "Steps.hpp"

/*
    Input:
        lambda - intensywność strumienia zgłoszeń,
        mi - średnia intensywność obłsugi,
        m - liczba kanałów obsługi,
        N - maksymalna liczba zgłoszeń.

    Calculates:
        Values describing queue system of type M/M/m/FIFO/m+N
*/
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

    calculateP0();

    double probAt_MN = probabilityAtIndex(m + N);

    p1 = probabilityAtIndex(1);
    pOdm = probAt_MN;
    m0Mean = ro * (1 - probAt_MN);
    mZnMean = m - m0Mean;
    calculateVMean();
    nMean = vMean + m0Mean;
    tf = vMean / lambda;
    ts = tf + (ro / mikro) * (1 - probAt_MN);
}

/*
    Calculates p0 according to ro / m.
*/
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
        p0 = 1 / (sum + (pow(ro, m) / mFactorialValue) * ((1 - (pow(roDivM, N + 1.0))) / (1 - roDivM)));
    }
}

/*
    Calculates v_mean wheter 'ro == m' or 'ro != m'.
*/
void Steps::calculateVMean() {
    if (ro == m) {
        vMean = (pow(m, m) / mFactorialValue) * (N * (N + 1.0) * p0 / 2);
    }
    else {
        vMean = (pow(ro, m + 1) * p0 / Factorial(m - 1).getFactorial()) 
            * (1 -pow(ro/m, N) * (N * (1 - ro / m) + 1)) / pow(m - ro, 2);
    }
}

/*
    Input
     index at which to calculate probability.

    Returns
     double value of probability.
*/
double Steps::probabilityAtIndex(int index)
{
    if (1 <= index && index <= m - 1) { // dla k
        return (pow(ro, index) / Factorial(index).getFactorial()) * p0;
    }
    else if (m <= index && index <= m + N) { // dla j
        return (pow(ro, index) / (pow(m, index - m) * mFactorialValue)) * p0;
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
    return to_string(pOdm);
}

string Steps::printM0sr()
{
    return to_string(m0Mean);
}

string Steps::printMznsr()
{
    return to_string(mZnMean);
}

string Steps::printVsr()
{
    return to_string(vMean);
}

string Steps::printNsr()
{
    return to_string(nMean);
}

string Steps::printTf()
{
    return to_string(tf);
}

string Steps::printTs()
{
    return to_string(ts);
}

Steps::~Steps() {}
