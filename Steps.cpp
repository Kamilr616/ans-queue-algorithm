#include "Steps.hpp"

Steps::Steps(const double _lambda, const double _mikro, const unsigned int _m, const unsigned int _N):
    lambda(_lambda), mikro(_mikro), m((double)_m), N((double)_N)
{    
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
    mFactorialValue = Factorial(m).getFactorial();

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

void Steps::calculateP0()
{
    double sum = 0;
    double roDivM = (this->ro / this->m);

    if (roDivM == 1)
    {
        for (int k = 0; k <= this->m - 1; k++)
        {
            sum += pow(this->ro, k) / Factorial(k).getFactorial();
        }
        this->p0 = 1 / (sum + (pow(this->ro, this->m) / this->mFactorialValue) * (this->N + 1.0));
    }
    else
    {
        for (int k = 0; k <= this->m - 1; k++)
        {
            sum += pow(this->ro, k) / Factorial(k).getFactorial();
        }
        this->p0 = 1 / (sum + (pow(this->ro, this->m) / this->mFactorialValue) * ((1 - (pow(roDivM, this->N + 1.0))) / (1 - roDivM)));
    }
}

void Steps::calculateVMean()
{
    if (this->ro == this->m)
    {
        this->vMean = (pow(this->m, this->m) / this->mFactorialValue) * (this->N * (this->N + 1.0) * this->p0 / 2);
    }
    else
    {
        this->vMean = (pow(this->ro, this->m + 1) * this->p0 / Factorial(this->m - 1).getFactorial())
            * (1 -std::pow(this->ro/this->m, this->N) * (N * (1 - this->ro / this->m) + 1)) / std::pow(this->m - this->ro, 2);
    }
}

double Steps::probabilityAtIndex(int index)
{
    if (1 <= index && index <= this->m - 1)
    {
        return (pow(this->ro, index) / Factorial(index).getFactorial()) * this->p0;
    }
    else if (this->m <= index && index <= (this->m + this->N))
    {
        return (pow(this->ro, index) / (pow(this->m, index - this->m) * this->mFactorialValue)) * this->p0;
    }
    else
    {
        throw invalid_argument("Given index: " + to_string(index) + " is out of range.");
    }
}

string Steps::probabilitesAtRange(const unsigned int from, const unsigned int to)
{
    string result = "";
    for (unsigned int i = from; i <= to; i++)
    {
        try
        {
            result += to_string(i) + ": " + to_string(probabilityAtIndex(i)) + ", ";
        }
        catch (const invalid_argument &ex)
        {
            return ex.what();
        }
    }
    result[result.length() - 2] = ' ';
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
    return to_string(this->pOdm);
}

string Steps::printM0sr()
{
    return to_string(this->m0Mean);
}

string Steps::printMznsr()
{
    return to_string(this->mZnMean);
}

string Steps::printVsr()
{
    return to_string(this->vMean);
}

string Steps::printNsr()
{
    return to_string(this->nMean);
}

string Steps::printTf()
{
    return to_string(this->tf);
}

string Steps::printTs()
{
    return to_string(this->ts);
}

Steps::~Steps() {}
