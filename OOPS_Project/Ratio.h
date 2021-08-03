#ifndef RATIO_H_INCLUDED
#define RATIO_H_INCLUDED
#include<iostream>
using namespace std;

//Class for all biological ratios.
class RatioandProb
{
    protected:
    int PhenRatio[4];

    int Prob[4];
    public:
    RatioandProb();
    void Display();
    void Displayp();
    void Probablity();
};


#endif // RATIO_H_INCLUDED
