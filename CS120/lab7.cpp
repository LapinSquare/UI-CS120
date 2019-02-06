/* 
* Kim Huynh
* CS 120 - Section 07
* 18 October 2018
* Lab #7 - Arrays
*/ 

#include <iostream>
using namespace std; 

int main(){ 
  int ar[10];
  int sum; 
  double average; 
  cout<<"Enter in 10 integers: "<<endl;
  for (int i=0; i<10; i++){
    cin>>ar[i];
    sum += ar[i];
  } 
  average = sum/10.0;
  cout<<"\nThe numbers in the array are..."<<endl;
  for (int i=0; i<10; i++){ 
    cout<<ar[i]<<" ";
  }
  cout<<""<<endl;
  cout<<"The sum of the array is "<<sum<<endl;
  cout<<"The average of the array is "<<average<<endl;
  cout<<"\n";


  //Testing 11th element. 
  //cout<<ar[10]<<endl; 
  //Some output:-1717986918,858993459,0,976565051,-858993459 
  //Different/ varied results most of the time. 

  //Testing 10,000th element. 
  //10,000th element is 9999 index. 
  //cout<<ar[9999];
  //Prints Segmentation fault

} 
