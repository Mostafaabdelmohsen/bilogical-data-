#include "DNA.h"
#include "Sequence.h"
#include "RNA.h"
#include <iostream>

using namespace std;
class RNA;
///DNA CLASS
///__________________________________________________

DNA::DNA()
{

}
/// DNA Constructor to receive sequence and its size
DNA :: DNA (char* seq,int length){

    this->length = length;
    this->seq = new char [length];
    for(int i = 0 ; i < length ; i++){
        *(seq+i)=*(seq+i);
    }
}

DNA::DNA(char * seq, DNA_Type atype,int length)
{
    this->length = length;
    this->seq = seq;
    type = atype;   ///setter type
}

DNA :: DNA(DNA& rhs)
{
    this->length = rhs.length;
    seq = new char [length];
    for(int i = 0 ; i < length ; i++){
        *(seq+i)=*(rhs.seq+i);
    }
}

/// adding start and end point to give user choice to covert a part of the sequence else convert all
 void DNA :: BuildComplementaryStrand()
 {
        int start,finish,choice;
        char* compSeq = new char [length];
        for(int i = 0 ; i<length;i++){
            compSeq[i] = seq[i];
        }
        cout<<"press 1 to convert the whole string , press 2 to convert from a specific index"<<endl;
        cin>>choice;
        if(choice==1){

        for(int i = 0 ; i<length;i++){
            if((compSeq[i]=='A')||(compSeq[i]=='a')){
                compSeq[i] = 'T';
            }
            else if((compSeq[i]=='C')||(compSeq[i]=='c')){
                compSeq[i] = 'G';
            }
            else if((compSeq[i]=='G')||(compSeq[i]=='g')){
                compSeq[i] = 'C';
            }
            else if((compSeq[i]=='T')||(compSeq[i]=='t')){
                compSeq[i] = 'A';
                }

        }
        }
        else if(choice==2)
        {
            cout<<"enter starting index :";
            cin>>start;
            cout<<"enter finishing index :";
            cin>>finish;
            cout<<endl;
          for(int i = start ; i<=finish;i++){
            if((compSeq[i]=='A')||(compSeq[i]=='a')){
                compSeq[i] = 'T'; ///change A's to T's
            }
            else if((compSeq[i]=='C')||(compSeq[i]=='c')){
                compSeq[i] = 'G'; ///change C's to G's
            }
            else if((compSeq[i]=='G')||(compSeq[i]=='g')){
                compSeq[i] = 'C';   ///G's to C's
            }
            else if((compSeq[i]=='T')||(compSeq[i]=='t')){
                compSeq[i] = 'A';   ///Change T's to A's
                }

        }

        }
        complementary_strand = new DNA(compSeq,type,length); ///passing to complementary strand function
 }

 RNA* DNA:: ConvertToRNA(char* seq,DNA* complementary_strand)
 {
     /*int choice;
     cout<<"press 1 to convert the whole string , press 2 to convert from a specific index"<<endl;
     cin>> choice;*/

     //if(choice==1){
        for(int i=0; i<length; i++){
            if(complementary_strand->seq[i]=='T' || complementary_strand->seq[i]=='t'){
                complementary_strand->seq[i]='U';
            }
        }
    // }
        /*else if (choice==2){
            for ( int i= start; i<=finish;i++){
                  if(complementary_strand->seq[i]=='T' || complementary_strand->seq[i]=='t'){
                    complementary_strand->seq[i]='U';
            }
        }

     }*/
     RNA* Robj = new RNA(complementary_strand->seq,mRNA,length);

     return Robj;
 }
/// print DNA Strand
void DNA :: print()

{
    cout << "SEQ : ";
    this->seq[length] = '\0';
    cout<< this->seq << endl;
    cout << endl;

    cout << "DNA type: " << endl;
    switch(this->type){
    case 0:
        cout << "promoter" << endl;
        break;
    case 1:
        cout << "motif" << endl;
        break;
    case 2:
        cout << "tail" << endl;
        break;
    case 3:
        cout << "noncoding" << endl;
        break;
    default:
        cout << "No Type" << endl;
    }
}

bool DNA :: operator == (const DNA& object)
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

bool DNA ::operator!=(const DNA& object)
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
DNA DNA::operator+(const DNA& object)
{
    DNA replacement;
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








DNA::~DNA()
{

}


