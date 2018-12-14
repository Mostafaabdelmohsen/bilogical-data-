#ifndef PROTEIN_H
#define PROTEIN_H
#include "DNA.h"
#include "RNA.h"
#include "CodonsTable.h"
#include <fstream>
#include <string>
#include <cstring>
class CodonsTable;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
class DNA;
class RNA;
class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	friend class DNA;
 	 	friend class RNA;
 	 	friend class CodonsTable;
 	 	Protein();
 	 	Protein(char * p,Protein_Type atype,int length);
 	 	Protein(char * p,int length);
 	 	~Protein();
        void print();
        bool operator == (const Protein& object);
        bool operator != (const Protein& object);
        Protein operator + (const Protein& object);
        friend istream& operator >> (istream& in , Protein& object);
        friend ostream& operator << (ostream& out , Protein& object);
 	 	/// return an array of DNA sequences that can possibly
                /// generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(const DNA& bigDNA,const RNA* Robj,CodonsTable C3);
};

#endif // PROTEIN_H
