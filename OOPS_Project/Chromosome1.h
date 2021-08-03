#ifndef CHROMOSOME1_H_INCLUDED
#define CHROMOSOME1_H_INCLUDED
#include<iostream>
#include"Allele1.h"
#include"Parent1.h"
#include"Ratio.h"
using namespace std;
class Chromosome:public Parent, public RatioandProb
{
    protected:
    int n;
    Allele a[20];
    bool genedet[100];
    friend class Population;

    public:
    Chromosome();
    void getall();
    void get();
    void getn();
    void operator=(Chromosome c);
    void operator*(Chromosome c);
    void Traitdistr(Chromosome c);
    void getdet();
    int getalle();
    void convert(string d1,string r1,string dn1, string rn1,string d2,string r2, string dn2, string rn2);
    int getgenes();
};

#endif // CHROMOSOME1_H_INCLUDED
