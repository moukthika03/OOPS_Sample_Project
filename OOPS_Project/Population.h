#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED
#include<iostream>
#include"Chromosome1.h"
class Population
{

    int np;
    Chromosome c[2];
    int fit[100];

//    bool pres[100][100];
    public:
    static int gen;
    Population();
    void calcfit();
    void getC();
    void getN();
    int getA();
    void crossover();
    void mutation();
    void getc2(int i);
    int select();
    void printdet(int f);
    int mostfit();
};

#endif // POPULATION_H_INCLUDED
