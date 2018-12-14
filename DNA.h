#ifndef DNA_H
#define DNA_H
#include "RNA.h"
#include "Sequence.h"
#include <iostream>

using namespace std;

enum DNA_Type{promoter, motif, tail, noncoding};
class RNA;
class DNA : public Sequence
{
  	private:

    public:
 	 	// constructors and destructor
 	 	DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
 	 	friend class RNA;
 	 	friend class Protein;
 	 	friend class CodonsTable;
 	 	//DNA(char* s);
 	 	DNA(char* seq,int length);
        DNA();
        DNA(char * seq, DNA_Type atype,int length);
        DNA(DNA& rhs);
        ~DNA();
 	 	// function printing DNA sequence information to user
        void print();
        bool operator == (const DNA& object);
        bool operator != (const DNA& object);
        DNA operator + (const DNA& object);
        friend istream& operator >> (istream& in , DNA& object);
        friend ostream& operator << (ostream& out , DNA& object);
        /// function to convert the DNA sequence to RNA sequence
        /// It starts by building the complementary_strand of the current
        /// DNA sequence (starting from the startIndex to the endIndex), then,
        /// it builds the RNA corresponding to that complementary_strand.
        RNA* ConvertToRNA(char* seq,DNA* complementary_strand);
 	 	/// function to build the second strand/pair of DNA sequence
	    /// To build a complementary_strand (starting from the startIndex to
        /// the endIndex), convert each A to T, each T to A, each C to G, and
        /// each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();
  };
#endif // DNA_H
