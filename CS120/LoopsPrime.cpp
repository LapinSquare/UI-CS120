/* 
* Kim Huynh  
* CS 120 - Section 07 
* 12 October 2018 
* Program #4 - LoopsPrime
*/

#include <iostream> 
#include <cstdlib> 
#include <fstream>
#include <math.h>
#include <cmath> 
#include <iomanip>
using namespace std; 

//Prototypes
void ShowHeader(ofstream &fOut);
void FunctionTable(ofstream &fOut);
void PNumberTable(ofstream &fOut);
int isPrime(int n);

int main(){ 
  //Declare ofstream + file.
  ofstream fOut; 
  fOut.open("Prog4.out", ios::out);
  //Checking for errors.
  if (!fOut){ 
    cerr<<"File unable to be opened."<<endl; 
    exit(-1); 
  }
  //Apply functions.
  ShowHeader(fOut); 
  FunctionTable(fOut); //Simple function table. 
  PNumberTable(fOut); //Prime # table.
  
  fOut.close();
} 

void ShowHeader(ofstream &fOut){ 
  fOut<<"Kim Huynh"<<endl; 
  fOut<<"CS 120 - Section 07"<<endl; 
  fOut<<"12 October 2018"<<endl; 
  fOut<<"Program #4 - LoopsPrime"<<endl; 
  fOut<<"\n"<<endl; //For spacing :)
} 

void FunctionTable(ofstream &fOut){

  //Aesthetic labels, so it looks neat. Not the table. 
  fOut<<"Simple Function Table:\n"<<endl; 
  fOut<<"x:"<<setw(15)<<"sqrt(x):"<<setw(15)<<"square(x):"; 
  fOut<<setw(15)<<"log(x):"<<endl;

  //Where the real calculations happen. 
  for (double i=0; i<=50; i++){ 
     fOut<<i; 
     //Spacing concerns.
     if (i<10){ 
       fOut<<setw(15);
     } 
     else{ 
       fOut<<setw(14); 
     }

     //Output sqrt, square, log. 
     fOut<<(pow(i,0.5))<<setw(15); 
     fOut<<(pow(i,2))<<setw(15);
     //I am assuming natural log.
     fOut<<log(i)<<endl;
     if (i>=10){
       //To make sure 10-50 by 5 steps (4+i++). 
       i+=4; 
     }
  } 
} 

void PNumberTable(ofstream &fOut){
  //Counter is just for spacing/ when to end.
  int counter = 0; 
  fOut<<"\nPrime Number Table: \n"<<endl; 
  for (int i=0; i<10000; i++){ 
    if (isPrime(i)){ 
      fOut<<i<<" "; 
      counter++;
    }
    //To make 8 numbers per line.
    if (counter==8){ 
      fOut<<"\n"; 
      counter = 0; 
    }
  }
}

int isPrime(int n){
//Like shown in-class... 
  if (n==2)   //Check if 2. 
    return 1; 
  if (n%2==0) //Check if even. 
    return 0; 
  //Otherwise...
  for (int i=3; i<n/2; i+=2){ 
    if (n%i==0){ 
      return 0; 
    }
  }
}
