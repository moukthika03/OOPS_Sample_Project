#include<iostream>
#include"Ratio.h"
#include<cstring>
#include<string>
using namespace std;
void RatioandProb::Display()
{
        int i;
        cout<<"\nPhenotypic ratio  (dominant,dominant):(dominant,recessive):(recessive,dominant):(recessive,recessive)-\n";

        for(i=0;i<4;i++)
        {
            cout<<PhenRatio[i];
            if(i!=3)
                cout<<":";
        }

}
RatioandProb::RatioandProb()
{
    PhenRatio[0]=0;
    PhenRatio[1]=0;
    PhenRatio[2]=0;
    PhenRatio[3]=0;
}

//Calculating and displaying.
void RatioandProb::Displayp()
{
    int i;
    for(i=0;i<4;i++)
    {
        Prob[i]=PhenRatio[i]*100/16;
        cout<<Prob[i]<<"%\t";
    }
}
