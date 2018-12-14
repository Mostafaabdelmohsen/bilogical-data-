#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include "Sequence.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;


class CodonsTable
{
  	private:


   	public:
   	    struct Codon
        {
            char* value= new char[4];    	    // 4th location for null character
            char AminoAcid;  	    // corresponding AminoAcid according to Table
        };
        Codon codons[64];
 	 	// constructors and
 	 	friend class RNA;
 	 	friend class DNA;
 	 	friend class Sequence;
        friend class Protein;
        void printcodons();
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);
        char  getAminoAcid(char * value);
        void setCodon(char * input, char amaino, int index);
};

#endif // CODONSTABLE_H
