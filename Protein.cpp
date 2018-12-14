#include "Protein.h"
#include <fstream>
#include "CodonsTable.h"
#include "RNA.h"
#include <string>
#include <cstring>
Protein::Protein()
{
    //ctor
}

Protein::Protein(char * p,Protein_Type atype,int length)
{
    this->length = length; ///setters for length, seq of proteins and type of protein
    this->seq = p;
    type = atype;
}

DNA* Protein :: GetDNAStrandsEncodingMe(const DNA& bigDNA,const RNA* Robj,CodonsTable C3) {

    int get_len_of_protien = 0; /// initialize length of protein and DNA
    int get_len_of_DNA = 0;
    while(seq[get_len_of_protien] != '\0'){
        get_len_of_protien++;
    }

/// get the actual length:
    get_len_of_protien = get_len_of_protien * 3;

    while(bigDNA.seq[get_len_of_DNA] != '\0'){
        get_len_of_DNA++;
    }

    char *temp = nullptr;

    DNA *obj;


    for(int i = 0; i <= get_len_of_DNA-get_len_of_protien; i++){
/// type casting because its void:

        temp = (char*)realloc(temp,get_len_of_protien*sizeof(char));

        //int h = i;

        for(int j = i; j < i+get_len_of_protien; j++){

            temp[j] = bigDNA.seq[j];

        }

    ///Creating new obj of Temp to convert from to DNA to RNA to protein and compare with Protein in hand


        temp[get_len_of_protien] = '\0'; /// last character null terminator

        int temp_len = strlen(temp);

        obj = new DNA(temp,motif,temp_len);

        obj->BuildComplementaryStrand();

        RNA* new_RNA = obj->ConvertToRNA(bigDNA.seq,bigDNA.complementary_strand);

        C3.LoadCodonsFromFile("RNA_codon_table.txt");


        Protein *PR = new_RNA->ConvertToProtein(C3);

        bool check = 1;

        for(int k =0 ; k<get_len_of_protien/3; k++)
        {

            if(PR->seq[k] != seq[k])
                check = 0;
        }

            if(check == 1){

                return obj;

            }

            delete obj;


    }
}



Protein :: Protein (char* pr,int len){
    seq = pr;
    length = len;
}
void Protein::print()
{
    cout<<"Your Protein sequence is : ";
    cout << seq <<endl;
    cout<<endl;
    //cout << type <<endl;
}
bool Protein :: operator == (const Protein& object)
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
bool Protein ::operator!=(const Protein& object)
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
Protein Protein::operator+(const Protein& object)
{
    Protein replacement;
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



Protein :: ~Protein()
{

}

