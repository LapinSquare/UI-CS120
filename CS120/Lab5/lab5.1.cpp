/* 
* Kim Huynh (Sole author, did all 3 parts by self) ! :)
* CS 120 - Section 07 
* September 27 2018
* Lab 5.1
*/ 

#include <iostream> 
#include <cmath> 
using namespace std;

//Prototypes
void naturalNumber(); 
int product2(int a, int b); 
int productPrint(int product);

int a_num, b_num; //Global variables that'll be used.

int main(){ 
   naturalNumber(); 
   int product_ab = product2(a_num,b_num);
   productPrint(product_ab);
} 
 
void naturalNumber(){   
   //I am assuming natural numbers DON'T INCLUDE 0.
   do {
      cout<<"\nPlease enter two natural numbers that are greater than 0: "<<endl;
      cout<<"(Note: 0 is not a natural number!)"<<endl;
      cin>>a_num>>b_num;
      if (a_num<=0||b_num<=0){
         cout<<"One of the inputs is not a natural number. Try again."<<endl; 
      }  
   } 
   while (a_num<=0||b_num<=0);
   cout<<"The numbers you entered in are "<<a_num<<" and "<<b_num<<" . "<<endl; 
} 
int product2(int a, int b){ 
   int product = a*b; 
   return product; 
} 
int productPrint(int product){
   cout<<"\n"<<product<<" is the product of "<<a_num<<" and "<<b_num<<" !\n "<<endl; 
   return product; 
}
