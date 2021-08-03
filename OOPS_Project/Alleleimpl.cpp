#include<iostream>
#include"Chromosome1.h"
#include<string>
#include"Allele1.h"
using namespace std;
void Allele::get()
{
    //Example
    //Trait: Height, Dominant:Tall, Recessive: Short
    cout<<"Enter the trait, dominant character and recessive character:-";
    cin>>trait;
    cin>>tr[0];
    cin>>tr[1];
    //Example
    //Tall: T, Short: t
    l90:cout<<"Enter the symbols for dominant and recessive trait:-";
    cin>>domn[0]>>domn[1];
    try
    {
        if(domn[1]==domn[0])
            throw domn[1];
    }
    catch(char domn[1])
    {
        //Exception handling is used to ensure that the symbols for dominant and recessive alleles are not the same.
        cout<<"Exception caught: Dominant and Recessive alleles cannot have same symbols!";
        goto l90;
    }
}

