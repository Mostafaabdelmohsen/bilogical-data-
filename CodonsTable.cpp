#include "CodonsTable.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>


CodonsTable::CodonsTable()
{

}

 void CodonsTable ::LoadCodonsFromFile(string codonsFileName) /// load codons from file
 {
    int counter = 0;
    //strcat(codonsFileName,".txt");
    fstream myFile("RNA_codon_table.txt");

    //char *input = new char [4];

    char amaino;

    if(myFile.is_open()){
        while(!myFile.eof()){
            char* input = new char[4];
            myFile >> input >> amaino;
            if(amaino=='$'){amaino=' ';} ///if stop codon is found  add space instead
            //cout<<input<<" -> "<<amaino<<endl;

           /* bool isTrue = true;
            for ( int i = 0; i < strlen(input); i++ )
                    if ( !isupper( input[i] ) ) isTrue = false;

            if ( isTrue )*/
            setCodon(input,amaino,counter);  /// passing input, Amino Acid of all codons , counter of file
            counter++;
    }

 }
 }
void CodonsTable ::setCodon(char * input, char amaino, int index)
{

    codons[index].value = input; /// setters for input and Amino Acid
    codons[index].AminoAcid = amaino;

}

char CodonsTable :: getAminoAcid(char * value)
{
    for(int i = 0 ; i < 64 ; i ++){
        if(strcmp(value,codons[i].value)==0){
            return codons[i].AminoAcid; ///Comparing string in hand to the codons table if their is an equality .... Bool == 0
        }                               /// return the found amino acid
    }
}


void CodonsTable::printcodons(){
    for(int i = 0; i <64 ; i++){
        cout<<codons[i].value<<"->"<<codons[i].AminoAcid<<endl;
    }
}

CodonsTable :: ~CodonsTable()
{


}
