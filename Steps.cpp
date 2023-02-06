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
Steps::Steps(double _lambda, double _mikro, unsigned int _m, unsigned int _N)
{
    this->lambda = _lambda;
    this->mikro = _mikro;
    this->m = _m;
    this->N = _N;
    this->ro = (_lambda / _mikro);

    this->p0 = 0;
    this->p1 = 0; 
    this->pOdm = 0;
    this->m0Mean = 0;
    this->mZnMean = 0;
    this->vMean = 0;
    this->nMean = 0;
    this->tf = 0;
    this->ts = 0;

    calculateAll();
}

void Steps::calculateAll()
{
    Factorial mFactorial(m);
    mFactorialValue = mFactorial.getFactorial();

    // 1. Warunek normalizujący trzeba sprawdzać?

    calculateP0();

    this->pOdm = probabilityAtIndex(this->m + this->N);

    this->p1 = probabilityAtIndex(1);
    this->m0Mean = (this->ro * (1 - this->pOdm));
    this->mZnMean = (this->m - this->m0Mean);

    calculateVMean();
    this->nMean = (this->vMean + this->m0Mean);
    this->tf = (this->vMean / this->lambda);
    this->ts = (this->tf + (this->ro / this->mikro) * (1 - this->pOdm));
}

/*
    Calculates p0 according to ro / m.
*/
void Steps::calculateP0()
{
    double sum = 0;
    double roDivM = (this->ro / this->m);

    if (roDivM == 1) {
        for (int k = 0; k <= this->m - 1; k++) {
            sum += pow(this->ro, k) / Factorial(k).getFactorial();
        }
        this->p0 = 1 / (sum + (pow(this->ro, this->m) / this->mFactorialValue) * (this->N + 1.0));
    }
    else {
        for (int k = 0; k <= this->m - 1; k++) {
            sum += pow(this->ro, k) / Factorial(k).getFactorial();
        }
        this->p0 = 1 / (sum + (pow(this->ro, this->m) / this->mFactorialValue) * ((1 - (pow(roDivM, this->N + 1.0))) / (1 - roDivM)));
    }
}

/*
    It's a function of p0 so it must be calculated earlier!
    Calculates v_mean whether 'ro == m' or 'ro != m'.
*/
void Steps::calculateVMean() {
    //TODO rzutowanie m na double
    if (this->ro == this->m) {
        this->vMean = (pow(this->m, this->m) / this->mFactorialValue) * (this->N * (this->N + 1.0) * this->p0 / 2);
    }
    else {
        this->vMean = (pow(this->ro, this->m + 1) * this->p0 / Factorial(this->m - 1).getFactorial()) 
            * (1 -pow(this->ro/this->m, this->N) * (N * (1 - this->ro / this->m) + 1)) / pow(this->m - this->ro, 2);
    }
}

/*
    Input
     index at which to calculate probability. It's a function of p0 so it must be calculated earlier!

    Returns
     double value of probability.
*/
double Steps::probabilityAtIndex(int index)
{
    if (1 <= index && index <= this->m - 1) { // dla k
        return (pow(this->ro, index) / Factorial(index).getFactorial()) * this->p0;
    }
    else if (this->m <= index && index <= (this->m + this->N)) { // dla j
        return (pow(this->ro, index) / (pow(this->m, index - this->m) * this->mFactorialValue)) * this->p0;
    }
    else {
        throw invalid_argument("Given index: " + to_string(index) + " is out of range.");
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

/*
    Input:
     Range [from, to] to calculate probabilites.
    
    Out:
     String of listed probabilities separeted by comma.
*/
string Steps::probabilitesAtRange(const unsigned int from, const unsigned int to)
{
    string result = "";
    for (unsigned int i = from; i <= to; i++) {
        try {
            result += to_string(i) + ": " + to_string(probabilityAtIndex(i)) + ", ";
        }
        catch (const invalid_argument &ex) {
            return ex.what();
        }
    }
    result[result.length() - 2] = ' '; // clear last comma
    return result;
}

string Steps::printRo()
{ 
    return to_string(this->ro);
}

string Steps::printP0()
{
    return to_string(this->p0);
}

string Steps::printP1()
{
    return to_string(this->p1);
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
