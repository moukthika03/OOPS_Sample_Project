#ifndef ALLELE1_H_INCLUDED
#define ALLELE1_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;
class Allele
{
    public:
    char trait[20];         //Example: Eye Color
    char domn[2];           //Example: Brown
    char tr[2][100];
    void get();
    friend void linkage(Allele a1,Allele a2);

};


#endif // ALLELE1_H_INCLUDED
