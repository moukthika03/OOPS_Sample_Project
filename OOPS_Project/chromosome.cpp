#include<iostream>
#include"Allele1.h"
#include"Parent1.h"
#include"Ratio.h"
#include"Chromosome1.h"
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
Chromosome::Chromosome()
{
    n=2;
}
void Chromosome::getn()
{
    cout<<"Enter the number of traits:-";
    cin>>n;
}
void Chromosome::getall()
{
    int i;

    cout<<"Enter the details of the first trait:-\n";
    for(i=0;i<n;i++)
    {
        if(i==1)
            cout<<"Enter details of the second trait:-\n";
        a[i].get();

    }
}
//    int i,j;
void Chromosome::get()
{
        Parent::get();

}

// To create a replica of a chromosome, '=' operator is overloaded.
void Chromosome::operator=(Chromosome c)
{
    int i;
    n=c.n;
    for(i=0;i<n;i++)
    {
        strcpy(a[i].trait,c.a[i].trait);
        strcpy(a[i].tr[0],c.a[i].tr[0]);
        strcpy(a[i].tr[1],c.a[i].tr[1]);
        strcpy(a[i].trait,c.a[i].trait);
        strcpy(a[i].tr[0],c.a[i].tr[0]);
        strcpy(a[i].tr[1],c.a[i].tr[1]);
    }

}
//This function performs a dihybrid cross between two chromosomes, following biological principles.
void Chromosome::operator*(Chromosome c)
{

    int i,k=0,p=0,j,l=0,m=0;
    char B[100][100],temp;
    for(i=0;i<n*n;i++)
    {
        if(i==n)
        {
            k++;
            p=0;
        }
        for(j=0;j<2;j++)
        {
            if(j==0)

                T1[i][j]=genotype[l][k];
            else
                T1[i][j]=c.genotype[l][p];
            B[i][j]=T1[i][j];

        }

        p++;
    }
    p=0;
    k=0;
    l=1;
    for(i=0;i<n*n;i++)
    {
        if(i==n)
        {
            k++;
            p=0;
        }
        for(j=0;j<2;j++)
        {
            if(j==0)
            {
                T1[i][j]=genotype[1][k];
            }
            else
            {
                T1[i][j]=c.genotype[1][p];
            }


        }

        p++;
    }
    for(i=0;i<(n*n);i++)
    {
        for(j=0;j<(n*n);j++)
        {
            strcpy(B1[m],B[i]);
            strcat(B1[m],T1[j]);
            m++;
        }
    }
    for(i=0;i<16;i++)
    {
        if(B1[i][0]>B1[i][1])
        {
            temp=B1[i][0];
            B1[i][0]=B1[i][1];
            B1[i][1]=temp;
        }
        if(B1[i][2]>B1[i][3])
        {
            temp=B1[i][2];
            B1[i][2]=B1[i][3];
            B1[i][3]=temp;
        }
    }

    cout<<"\n";


}

//Displaying values if Punnet square, i.e, all possible trait combinations
//Probability of each combination to be featured in the progeny are calculated.
void Chromosome::Traitdistr(Chromosome c)
{
    int i,f,fl,j;
    char trt[2][100];
    cout<<"\n";
    cout<<"\nThe values of the Punnet square are as follows:-\n";
    for(i=0;i<16;i++)
    {
        f=0;
        fl=0;
        for(j=0;j<2;j++)
        {
            if(B1[i][j]==a[0].domn[0])
            {
                f=1;
                break;
            }

        }

        if(f==1)
            strcpy(trt[0],a[0].tr[0]);
        else
            strcpy(trt[0],a[0].tr[1]);

        for(j=2;j<4;j++)
        {
            if(B1[i][j]==a[1].domn[0])
            {
                fl=1;
                break;
            }
        }
        if(fl==1)
            strcpy(trt[1],a[1].tr[0]);
        else
            strcpy(trt[1],a[1].tr[1]);

        cout<<B1[i]<<"-"<<trt[0]<<", "<<trt[1]<<"\n";
        if(f==1&&fl==1)
            PhenRatio[0]++;
        else if(f==1&&fl==0)
             PhenRatio[1]++;
        else if(f==0&&fl==1)
             PhenRatio[2]++;
        else if(f==0&&fl==0)
             PhenRatio[3]++;
    }
    cout<<"\nProbability of getting ("<<a[0].tr[0]<<","<<a[1].tr[0]<<"),("<<a[0].tr[0]<<","<<a[1].tr[1]<<"),("<<a[0].tr[1]<<","<<a[1].tr[0]<<"),("<<a[0].tr[1]<<","<<a[1].tr[1]<<"), respectively are:-\n";


    RatioandProb::Displayp();
    RatioandProb::Display();
}

//Details of alleles in the chromosome are entered.
int Chromosome::getalle()
{
    int i;
    getn();
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter details of gene at position "<<i+1<<" of the chromosome\n";
        a[i].get();

    }
    return n;
}

//The binary numbers ‘1’ and ‘0’ indicate availability and non- availability respectively.
void Chromosome::getdet()
{
    int i;

    //getn();

    for(i=0;i<n;i++)
    {

        cout<<"Press '1' if gene "<<i+1<<" is present and '0' if not present\n";
        cin>>genedet[i];
        cout<<"\n";

    }
}
void Chromosome::convert(string d1,string r1,string dn1, string rn1,string d2,string r2, string dn2, string rn2)
{
    strcpy(a[0].tr[0], d1.c_str());
    strcpy(a[0].tr[1], r1.c_str());
    a[0].domn[0]=dn1[0];
    a[0].domn[1]=rn1[0];
    strcpy(a[1].tr[0], d2.c_str());
    strcpy(a[1].tr[1], r2.c_str());
    a[1].domn[0]=dn2[0];
    a[1].domn[1]=rn2[0];

}
int Chromosome::getgenes()
{

    getn();
    int i;
    string traits[50];
    for(i=0;i<n;i++)
    {
        cout<<"Enter trait "<<i+1<<": -";
        cin>>traits[i];
    }
    return n;
}

