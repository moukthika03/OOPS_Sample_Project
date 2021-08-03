#include<iostream>
#include"Chromosome1.h"
//#include"Allele1.h"
#include"Parent1.h"
#include<string>
using namespace std;
Parent::Parent()
{
    gender='f';

}

// Getting parental details.
void Parent::get()
{
    cout<<"Enter the gender of the parent from which chromosome comes";
    cin>>gender;
    int i,j;

    cout<<"Enter the genotype of the parent:-";
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            cin>>genotype[i][j];


       }
   }
}
