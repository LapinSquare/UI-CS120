/*
* Kim Huynh
* CS 120 - Section 07
* September 20 2018
* Lab 4.1 - FOR LOOP
*/

#include <iostream>
using namespace std;

int main(){ 

   int ans, input, sum; 
   cout<<"\nThis is the For Loop Code!"<<endl; 
   //I didn't understand instructions, so I did both versions. :)
   cout<<"\nWould you like to enter in 5 or 100 integers?"<<endl; 
   cout<<"Type in 5 or 100: "<<endl;
   cin>>ans; 
   if (ans == 5){ 
      cout<<"\nType in 1 integer at a time."<<endl; 
      for (int i=0; i<5; i++){ 
         cin>>input; 
         sum += input; 
      } 
      cout<<"The sum is : "<<sum<<endl; 
   }
   else if (ans==100){
      cout<<"\nType in 1 integer at a time."<<endl;
      cout<<"To stop, press 0."<<endl; 
      for (int i=0; i<100; i++){    
         cin>>input;
         sum += input;
         if (input == 0){ 
         i+=200;
         }
      }
      cout<<"Your sum total is : "<<sum<<endl;  
   } 
   else{ 
      cout<<"I don't recognize that as a 5 or 100."<<endl; 
      cout<<"AKA : I am too lazy to foolproof/ addon stuff."<<endl;  
   }
   return 0;
}

