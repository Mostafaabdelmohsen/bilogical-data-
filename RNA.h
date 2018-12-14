#ifndef RNA_H
#define RNA_H
#include "Sequence.h"
#include "DNA.h"
#include "CodonsTable.h"
#include "Protein.h"
#include "RNA.h"
#include <iostream>

using namespace std;


enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
class CodonsTable;
class DNA;
class Protein;
class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
 	 	friend class Protein;
 	 	friend class CodonsTable;
 	 	friend class DNA;
        RNA();
        RNA(char * seq, RNA_Type atype,int length);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void print();
        bool operator == (const RNA& object);
        bool operator != (const RNA& object);
        RNA operator + (const RNA& object);
        friend istream& operator >> (istream& in , RNA& object);
        friend ostream& operator << (ostream& out , RNA& object);
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein* ConvertToProtein(CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
};

#endif // RNA_H
