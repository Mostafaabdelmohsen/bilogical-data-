#include "RNA.h"
#include <iostream>
#include <cstring>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "CodonsTable.h"
#include "Protein.h"

using namespace std;
class CodonsTable;
RNA::RNA()
{

    //ctor
}

RNA :: RNA (char * seq, RNA_Type atype,int length)
{
    this->length = length; ///setters for type, length of string and the DNA sequence
    this->seq = seq;
    type = atype;
}


RNA :: RNA(RNA& rhs)
{
    this->length = rhs.length;
    seq = new char [length];
    for(int i = 0 ; i < length ; i++){
        *(seq+i)=*(rhs.seq+i);
    }
}


void RNA :: print()
{
    this->seq[length] = '\0';   ///null character initiator .... to terminate last character for dynamic allocation
    cout<< this->seq << endl;
    cout << endl;

    cout << "RNA type: " << endl;
    switch(this->type){
    case 0:
        cout << "mRNA" << endl;
        break;
    case 1:
        cout << "pre_mRNA" << endl;
        break;
    case 2:
        cout << "mRNA_exon" << endl;
        break;
    case 3:
        cout << "mRNA_intron" << endl;
        break;
    default:
        cout << "No Type" << endl;



    }

}

Protein* RNA :: ConvertToProtein(CodonsTable & table)
{

    int len = strlen(seq);
    int part_len = len / 3 ;    /// size of each 3 letters of RNA sequence

    //cout<<"length of part = "<<part_len<<endl;
    if(len%3==0){

    int j = 0;
        char* pass = new char [4];
        char* pr = new char[part_len];
        for(int i = 0 ; i< len ; i=i+3){
            //char* pr = new char[part_len];
            pass[0]=seq[i];
            pass[1]=seq[i+1];
            pass[2]=seq[i+2];
            pass[3]='\0';   ///null terminator
            pr[j]=table.getAminoAcid(pass);
            j++;

        }

        Protein* Pobj = new Protein(pr,part_len);
        return Pobj;
    }



}

DNA RNA::ConvertToDNA(){
    for(int i = 0 ; i <length ; i++){
        if(seq[i]=='U' || seq[i]=='u'){
            seq[i]='T'; /// change U's to T's
        }
    }
    DNA Dobj(seq,length);
    return Dobj;
}
bool RNA :: operator == (const RNA& object)
{
    bool check = true;
    if(this->length != object.length){
        return false;
    }else{

        for(int i = 0; i < length; i++)
        {
            if(this->seq[i] != object.seq[i])
            {
               check = false;
               break;
            }
        }
        return check;

    }
}
bool RNA ::operator!=(const RNA& object)
{
    if(this->length == object.length)
    {
        int check = 0;
        for(int i = 0; i < length; i++){
            if(this->seq[i] == object.seq[i]){
                check++;
            }
        }
        if(check != 0){
            return false;
        }else{
            return true;
        }
    }else{
        return true;
    }
}
RNA RNA::operator+(const RNA& object)
{
    RNA replacement;
    replacement.length = this->length + object.length;
    replacement.seq = (char*)malloc(sizeof(char) * (replacement.length));
    replacement.type = this->type;
    for(int i = 0; i < length; i++){
        if(i < length){
            replacement.seq[i] = this->seq[i];
        }else{
            replacement.seq[i] = object.seq[i - length];
        }
    }
    return replacement;
}



RNA :: ~RNA()
{

}
