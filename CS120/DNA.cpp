/*
* Kim Huynh
* CS 120 - Section 07
* November 2 2018 
* Program #7 - DNA
*/
#include <iostream>
#include <fstream>
using namespace std;

//Prototypes
//The usual header with identification...
void ShowHeader(ofstream &fOut);
//Reads and stores fIn data in strand[], updates # in array.
void ReadStoreDNA(ifstream &fIn, char strand[], int *nA);
//Translates DNA component to complement
char ComplementBase(char orig);
//Extended version of ComplementBase...update whole complement strand.
void ComplementStrand(char base[], char cStrand[], int nA);
//Final output that draws DNA strand w/ complement and prefix.
void DrawDNA(char origStrand[], char cStrand[], int nA, ofstream &fOut);
//Gets the few beginning char.
string Prefix(ofstream &fOut, int bases, char origStrand[], string prefix);  

int main(){
  ofstream fOut;
  ifstream fIn;
  fOut.open("Prog7.out", ios::out);
  ShowHeader(fOut);
  //Error checking.
  if (!fOut){ 
    cout<<"Unable to open Prog7.out"<<endl;
  }
  char fileName[32]; 
  char DNAStrand[80];
  int nA; //# of elements in array.
  cout<<"Insert name of file to be analyzed: ";
  cin>>fileName;
  fIn.open(fileName, ios::in);
  //Error checking.
  if (!fIn){ 
    cout<<"Unable to open "<<fileName<<endl;
  }
  ReadStoreDNA(fIn, DNAStrand, &nA);
  //Tested if elements were correct.
  //cout<<"There are a total of "<<nA<<" elements.\n";
  char cStrand[nA]; //Complement strand.
  ComplementStrand(DNAStrand, cStrand, nA);
  DrawDNA(DNAStrand, cStrand, nA, fOut);
  fIn.close();
  fOut.close();
  return 0;
}
void ShowHeader(ofstream &fOut){
  fOut<<"\nKim Huynh"<<endl;
  fOut<<"CS120 - Section07"<<endl;
  fOut<<"November 2 2018"<<endl;
  fOut<<"Program #7 - DNA\n"<<endl;
}
void ReadStoreDNA(ifstream &fIn, char strand[], int *nA){
  int i=0;
  while (fIn){
    fIn>>strand[i];
    i++;
  }
  *nA = i-1; //Update # of elements that are in array.
}
char ComplementBase(char orig){
  switch(orig){
    case 'A':
      return 'T';
      break;
    case 'C':
      return 'G';
      break;
    case 'G':
      return 'C';
      break;
    case 'T':
      return 'A';
      break;
  }
}
void ComplementStrand(char base[], char cStrand[], int nA){
  for (int i=0; i<nA; i++){
    //Updates complement strand.
    cStrand[i]= ComplementBase(base[i]);
  }
}
void DrawDNA(char origStrand[], char cStrand[], int nA, ofstream &fOut){
  string prefix="";
  //Most for loops are for the DNA design outlook.
  for (int i=0; i<nA; i++){
    fOut<<"--+";
    if (i==nA-1){
      fOut<<"--"<<endl;
    }
  }
  for (int i=0; i<nA; i++){
    fOut<<"  |";
  }
  fOut<<endl;
  for (int i=0; i<nA; i++){
    fOut<<"  "<<origStrand[i]; //DNA
  }
  fOut<<endl;
  for (int i=0; i<nA; i++){
    fOut<<"  .";
  }
  fOut<<endl;
  for (int i=0; i<nA; i++){
    fOut<<"  "<<cStrand[i]; //Complement
  }
  fOut<<endl;
  for (int i=0; i<nA; i++){
    fOut<<"  |";
  }
  fOut<<endl;
  for (int i=0; i<nA; i++){
    fOut<<"--+";
    if (i==nA-1){
      fOut<<"--"<<endl;
    }
  }
  fOut<<endl;
  fOut<<"Prefix(7): "<<Prefix(fOut, 7, origStrand, prefix)<<endl;
  fOut<<"Prefix(23): "<<Prefix(fOut, 23, origStrand, prefix)<<endl;
}
string Prefix(ofstream &fOut, int bases, char origStrand[], string prefix){
  for (int i=0; i<bases; i++){
    prefix+=origStrand[i];
  }
  return prefix;
  
}