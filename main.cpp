#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "CodonsTable.h"
#include "Protein.h"
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{



    char* inputDna;
    string inputString;
    cout<<"enter the DNA strand : ";
    cin>>inputString;
    cout<<endl;
    int inputLen = inputString.length(); /// inputlen equals size of inputed string
    inputDna = new char[inputLen];
    for(int i = 0;i<inputLen;i++){
            inputDna[i]=inputString[i];  /// copying the entered string to InputDNA allocated in line 24
    }
    int albadeel; /// type of entered DNA, refer to enum types
    cout<<"Press 1 for promoter,2 for motif,3 for tail,4 for noncoding  : ";
    cin>>albadeel;
    DNA_Type inputType = (DNA_Type)albadeel;

    cout<<endl;
    DNA D(inputDna,inputType,inputLen); /// creating object to DNA constructor which contains the string, size and type
    D.BuildComplementaryStrand(); /// passing to complementary strand function
    ///_______________________________________________


    ///inputting the RNA sequence
    cout<<endl;
    RNA* Robj;
    Robj =D.ConvertToRNA(D.seq,D.complementary_strand); /// function to convert to RNA
    cout<<"Your RNA sequence is : ";
    Robj->print();
    cout<<endl;
     ///_______________________________________________


    ///loading the Codon table
    string FileName = "RNA_codon_table.txt";
    CodonsTable C;
    C.LoadCodonsFromFile(FileName); /// load data from file
    ///_______________________________________________


    ///getting the protein sequence from the RNA sequence
    Protein* P;
    P = Robj->ConvertToProtein(C);
    P->print();
    ///_______________________________________________


    ///Getting DNA from already existing Protein
    cout<<"Enter a DNA sequence to compare it with the protein sequence : ";
    cout<<"enter the DNA strand : ";
    cin>>inputString;
    cout<<endl;
    inputLen = inputString.length();
    inputDna = new char[inputLen];
    for(int i = 0;i<inputLen;i++){
            inputDna[i]=inputString[i];
    }
    DNA Dobj2(inputDna,inputType,inputLen);
    //Dobj2.print();
    //CodonsTable C2;
    //C2.LoadCodonsFromFile("RNA_codon_table.txt");
    Dobj2.BuildComplementaryStrand();
    RNA* Robj2;
    Robj2 = Dobj2.ConvertToRNA(Dobj2.seq,Dobj2.complementary_strand);
    DNA* compareDna = P->GetDNAStrandsEncodingMe(Dobj2,Robj2,C); /// Passing ( DNA object, RNA object , Codons table object )
    compareDna->print();    /// compare DNA Function

    ///____________________________________________________________________

     ///inputing a DNA sequence
     /// inputing first and second (s1,s2)
    string s1string;
    string s2string;
    char* s1seq = new char[s1string.length()];
    char* s2seq = new char[s2string.length()];
    cout<<"Enter the 1st seq :";
    cin>>s1string;
    cout<<endl;
    cout<<"Enter the 2st seq :";
    cin>>s2string;
    cout<<endl;
    strcpy(s1seq,s1string.c_str()); ///copying s1 string to s1seq
    strcpy(s2seq,s2string.c_str()); /// ~~~~~~ s2   ~~~~~~~~

     /// initializing the size of s1 and s2 to pass it to the the new allocation of objects S1 and S2 to DNA constructor
    int x = strlen(s1seq);
    int y = strlen(s2seq);

    Sequence* S1= new DNA(s1seq,motif,x);
    //S1->print();

    Sequence* S2= new DNA(s2seq,motif,y);
    //S2->print();
    char * align;
    align = Align(S1,S2); /// passing both objects to align function
    cout<<align;        /// print align value
////////////////////////////////////////////////////////////////////////////////////
    return 0;
}
istream& operator>> (istream& in, DNA& object)
{
    int le;
    int ty;

    cout << "enter the length of the sequence: " << endl;
    in >> le;
    object.length = le;
    object.seq = (char*)malloc(sizeof(char) * (object.length));
    cout << "enter the sequence: " << endl;
    in >> object.seq;
        return in ;

}
ostream& operator<< (ostream& out, DNA& object)
{
    string type ;
    if (object.type == 1)
        type = "promoter" ;
    else if (object.type == 2)
        type = "motif" ;
    else if (object.type == 3)
        type = "tail" ;
    else if (object.type == 4)
        type = "noncoding" ;
    out << object.seq << " of type: " << type << endl;
    return out ;
}
istream& operator>> (istream& in, RNA& object)
{
    int le;
    int ty;

    cout << "enter the length of the sequence: " << endl;
    in >> le;
    object.length = le;
    object.seq = (char*)malloc(sizeof(char) * (object.length));
    cout << "enter the sequence: " << endl;
    in >> object.seq;
        return in ;

}
ostream& operator<< (ostream& out, RNA& object)
{
    string type ;
    if (object.type == 1)
        type = "mRNA" ;
    else if (object.type == 2)
        type = "pre_mRNA" ;
    else if (object.type == 3)
        type = "mRNA_exon" ;
    else if (object.type == 4)
        type = "mRNA_intron" ;
    out << object.seq << " of type: " << type << endl;
    return out ;
}
istream& operator>> (istream& in, Protein& object)
{
    int le;
    int ty;

    cout << "enter the length of the sequence: " << endl;
    in >> le;
    object.length = le;
    object.seq = (char*)malloc(sizeof(char) * (object.length));
    cout << "enter the sequence: " << endl;
    in >> object.seq;
    return in ;

}
ostream& operator<< (ostream& out, Protein& object)
{
    string type ;
    if (object.type == 1)
        type = "Hormon" ;
    else if (object.type == 2)
        type = "Enzyme" ;
    else if (object.type == 3)
        type = "TF" ;
    else if (object.type == 4)
        type = "Cellular_Function" ;
    out << object.seq << " of type: " << type << endl;
    return out ;
}














