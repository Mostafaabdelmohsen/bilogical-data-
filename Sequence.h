#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include "CodonsTable.h"
#include <algorithm>
using namespace std;
class Sequence
{
  	private:

    public:
 	 	// constructors and destructor
 	 	char * seq;
        int length;
        Sequence(char* s);
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        char* enterSequence();
        char* getSeq();
        virtual ~Sequence();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void print() = 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2);
};

//class RNA;





// struct representing a codon of 3 DNA/RNA characters and ‘\0’


// need to create one object of that class to load the AminoAcids table
// into memory








#endif // SEQUENCE_H
