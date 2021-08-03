//Author: Moukthika Muthukrishnan

#include <iostream>
#include"Allele1.h"
#include"Parent1.h"
#include"Chromosome1.h"
#include"Ratio.h"
#include"Population.h"
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main()
{
    int op,ch,t=1,ko,ks,et,tp;
    vector<string> row;
    string Trait,dom,rec,domn,recs,line,word;
    l92:cout<<"\nChoose from the following options:-\n1)Compute phenotype and genotypic ratios in a dihybrid cross\n2)Find the fittest generation\n";
    cin>>op;
    //First option is to perform a dihybrid cross between two traits, which is basically a permutation and combination of alleles from both parents. 
    //This gives us the list of all possible combinations of the two traits the offsprings can have, i.e, different varieties in each trait the offsprings can express. 
    //Also, the probabilities of each combination which may be expressed in the offspring is calculated.

    //The second option deals with finding the chromosome with maximum fitness.

    if(op==1)
    {
        Chromosome c1, c2;

        //The traits to be crossed are chosen by the user from a list in a file "sample.txt", which is created by file pointers. 
        //The user can also choose to add more traits by appending in the file. Vectors are used for intermediate storing of words in each line read from the file. 

        cout<<"Press '1' to choose from traits to cross or '2' to add new traits";
        cin>>ch;
        if(ch==1)
        {
            ifstream fin;
            string temp;

            fin.open("sample.txt");

            int st=1;
            while (fin>>temp)
            {
                row.clear();
                getline(fin, line);
                stringstream s(line);
                while (getline(s, word, ' '))
                {
                    row.push_back(word);
                }
                cout<<st<<" "<<row[1]<<" "<<row[2]<<" "<<row[3]<<" "<<row[4]<<" "<<row[5]<<"\n";
                st++;


            }


            fin.close();
            cout<<"Select any two traits from the above list:-";
            cin>>ko>>ks;
            fin.open("sample.txt");

            st=1;
            string d1,d2,r1,r2,dn1,dn2,rn1,rn2;
            while (fin>>temp)
            {
                row.clear();
                getline(fin, line);
                stringstream s(line);
                while (getline(s, word, ' '))
                {
                    row.push_back(word);
                }

                if(ko==st)
                {
                    d1=row[2];
                    r1=row[3];
                    dn1=row[4];
                    rn1=row[5];
                }
                if(ks==st)
                {
                    d2=row[2];
                    r2=row[3];
                    dn2=row[4];
                    rn2=row[5];
                }

                st++;


            }
            c1.convert(d1,r1,dn1,rn1,d2,r2,dn2,rn2);
        }
        if(ch==2)
        {
            c1.getall();
            c2=c1;
        }
        c1.get();
        c2.get();
        c1*c2;
        c1.Traitdistr(c2);
        cout<<"\n\nDo you want to edit trait list?Press '1' if yes and '0' if no.";
        cin>>et;
        if(et==1)
        {
            ofstream fout;
            fout.open("sample.txt",ios::app);
            int cn=1;
            while (fout)
            {

                cin>>Trait>>dom>>rec>>domn>>recs;
                fout << t<<" "<<Trait <<" "<< dom<<" "<<rec<<" "<<domn<<" "<<recs<<"\n";


                cout<<"Press 1 to continue and 0 to exit";
                cin>>cn;
                t++;
                if(cn!=1)
                    break;

            }

            fout.close();
        }

    }

    if(op==2)
    {
        int f=-1;
        int fit=-1;
        int fc;
        int n;
        cout<<"\nGeneration 1:\n";
        Population p;
         n=p.getA();
         p.getC();
         //The chromosome with higher fitness level after crossover is selected for crossover with another chromosome inputted by the user (next-generation). 
         //This loop terminates till the chromosome with maximum fitness level is reached, i.e, a chromosome with all ‘1’s. 
         //The output displays the generation at which this state is reached.

         while(fit!=n)
         {
             p.crossover();
             //p.mutation();
             p.calcfit();
             f=p.select();
             p.printdet(f);
             fit=p.mostfit();
             cout<<"\nFitness number is"<<fit<<"\n";
             if(fit==n)
                break;
             if(f==1)
                fc=0;
             else
                fc=1;
             p.getc2(fc);


             Population::gen++;
         }
        cout<<"\nThe fittest batch is observed in generation "<<Population::gen<<"\n";

    }
    cout<<"\nPress '1' to continue and any other key to exit the program";
    cin>>tp;
    if(tp==1)
        goto l92;

    return 0;
}
