# OOPS_Sample_Project

The main aim of this project is to perform two functions. Firstly, it performs a dihybrid cross between two traits, which is basically a permutation and combination of alleles from both parents. This gives us the list of all possible combinations of the two traits the offsprings can have, i.e, different varieties in each trait the offsprings can express. Also, the probabilities of each combination which may be expressed in the offspring is calculated.

The traits to be crossed are chosen by the user from a list in a file, which is created by file pointers. The user can also choose to add more traits by appending in the file. Vectors are used for intermediate storing of words in each line read from the file. 

Exception handling is used to ensure that the symbols for dominant and recessive alleles are not the same.
The classes used are- Chromosome, RatioandProb, Population, Allele, Parent.

Relationship among Classes:-
Chromosome class derives its properties from Parent and RatioandProb class under public inheritance. Chromosome class includes Allele class as its private data member. Population class is the friend class of Chromosome class, because of which the former can access the private data members of the latter. 


The second part of the project deals with finding the chromosome with maximum fitness.
An array is used to represent the chromosome with each index position representing availability of a particular gene. The binary numbers ‘1’ and ‘0’ indicate availability and non- availability respectively. Two chromosomes undergo crossover. 
The chromosome with higher fitness level after crossover is selected for crossover with another chromosome inputted by the user (next-generation). This loop terminates till the chromosome with maximum fitness level is reached, i.e, a chromosome with all ‘1’s. The output displays the generation at which this state is reached.


