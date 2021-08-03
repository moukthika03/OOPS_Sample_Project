#ifndef PARENT1_H_INCLUDED
#define PARENT1_H_INCLUDED
#include<iostream>
//#include"Allele1.h"
using namespace std;

//Details of the parent from which the chromosome comes  
class Parent
{
    protected:
    char gender;
    char T1[100][100];        //Variables used for intermediate steps of Dihybrid cross.
    char B1[100][100];        //Variables used for intermediate steps of Dihybrid cross.
    char genotype[100][2];
    public:
    Parent();
    void get();


};


#endif // PARENT1_H_INCLUDED
