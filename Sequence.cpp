#include "Sequence.h"
#include <iostream>
#include "RNA.h"
#include "DNA.h"
#include <algorithm>
using namespace std;

///SEQRUENCE CLASS
///__________________________________________________
Sequence::Sequence()
{

}


Sequence::Sequence(int length)
{
    this->length = length;
    seq = new char [length]; ///setter for length

}

///Getting sequence from user
Sequence::Sequence(Sequence& rhs)
{
    seq = new char [length];
    for(int i = 0 ; i < length ; i++){
        *(seq+i)=*(rhs.seq+i);
    }

}
Sequence::Sequence(char* s) ///object constructor
{
    seq = s;
}


char* Sequence :: enterSequence()
{
    for(int i = 0 ; i<length;i++){
        cin>>seq[i];
    }
    return seq;
}
void Sequence::print() ///virtual print function for sequence
{
cout<<"ok";

}

/*char* Sequence :: getSeq()
{
    return seq;
}*/
char* Align(Sequence * s1, Sequence * s2)   /// align function
{
/// get input from user
    int len1 = strlen(s1->seq);
    //cout << "len is: " << len1 << endl;
    int len2 = strlen(s2->seq);
    //cout << "len is: " << len2 << endl;

/// But the null char;
    s1->seq[len1] = '\0';
    s2->seq[len2] = '\0';
/// Initialize the matrix:
    int temp[len1 + 1][len2 + 2];
/// Initialize the whole matrix to zeros:
    for(int i = 0; i <= len1; i++){
        for(int j = 0; j<= len2; j++){
            temp[i][j] = 0;
        }
    }


/// start to fill the matrix:
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
/// If the two end char are the same:
            if(s1->seq[i-1] == s2->seq[j-1]){
                temp[i][j] = temp[i-1][j-1] + 1;
            }else{
                temp[i][j] = max(temp[i-1][j],temp[i][j-1]);
            }
        }
    }

    int Len_Of_LCS = temp[len1][len2];
    cout << "the length of long common subsequence is: " << Len_Of_LCS << endl;


/// char array that will carry the LCS:
    char *LCS = new char[Len_Of_LCS + 1];
/// set the null char:
    LCS[Len_Of_LCS] = '\0';

    int temp_i = len1;
    int temp_j = len2;
    while(temp_i > 0 && temp_j > 0)
    {
        if(s1->seq[temp_i - 1] == s2->seq[temp_j - 1])
        {
            LCS[Len_Of_LCS - 1] = s1->seq[temp_i - 1];
            temp_i--;
            temp_j--;
            Len_Of_LCS--;
        }
        else if(temp[temp_i - 1][temp_j] > temp[temp_i][temp_j - 1])
            temp_i--;
        else
            temp_j--;
    }

    return LCS;
}


Sequence::~Sequence()
{

}


//void Sequence :: Print() = 0;





