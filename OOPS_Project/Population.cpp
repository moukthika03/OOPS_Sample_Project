#include<iostream>
#include"Population.h"
#include"Chromosome1.h"
using namespace std;
int Population::gen=2;
Population::Population()
{
    np=2;
    int i;
    for(i=0;i<2;i++)
        fit[i]=0;
}
//A population consists of a number of chromosomes.
void Population::getN()
{
    cout<<"Enter the number of chromosomes in the population";
    cin>>np;
}
int Population::getA()
{
    int nts;
    nts=c[0].getgenes();
    c[1]=c[0];
    return nts;
}
void Population::getC()
{
    int i;

    for(i=0;i<np;i++)
    {

        if(i==0)
            cout<<"For Chromosome 1:-\n";
        else
            cout<<"For chromosome 2:-\n";
        c[i].getdet();

    }
}

//Swapping the halves of each chromosome.
void Population::crossover()
{
    int cp;
    l50:cout<<"Choose a crossover point:-";
    cin>>cp;
    if(cp<1||cp>c[0].n)
    {
        cout<<"Please enter a valid crossover point";
        goto l50;
    }
    int i;
    bool temp;
    for(i=(cp-1);i<c[0].n;i++)
    {
            temp=c[0].genedet[i];
            c[0].genedet[i]=c[1].genedet[i];
            c[1].genedet[i]=temp;
    }
}

//Mutation is the change in genetic composition of DNA.
// Changing '1' to '0' or '0' to one in any random position.
void Population::mutation()
{
    int mp, nt;
    nt=c[0].n;
    nt--;
    mp=(rand()%nt);
    if(c[0].genedet[mp]==0)
        c[0].genedet[mp]=1;
    else
        c[0].genedet[mp]=0;
}

//Calculating the fitness level of chromosome, i.e, calculating number of '1's.
void Population::calcfit()
{
    int i,j;
    fit[0]=0;
    fit[1]=0;
    for(i=0;i<2;i++)
    {
        for(j=0;j<c[i].n;j++)
        {
            if(c[i].genedet[j]==1)
                fit[i]++;
        }
    }
}
void Population::printdet(int f)
{
    int i;
    cout<<"\nThe fittest chromosome is:-";
    for(i=0;i<c[0].n;i++)
    {
        cout<<"\n"<<c[f].genedet[i];
    }
    cout<<"\n";
}
int Population::select()
{
    if(fit[0]>fit[1])
        return 0;
    else
        return 1;
}

void Population::getc2(int i)
{
    cout<<"\nGeneration: "<<gen<<"\n";
    cout<<"\nKindly enter details of the other chromosome to cross with:-";
    c[i].getdet();
}
int Population::mostfit()
{
    if(fit[0]>fit[1]||fit[0]==fit[1])
        return fit[0];
    else
        return fit[1];
}
