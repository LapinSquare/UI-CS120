/*
* Kim Huynh
* CS 120 - Section 07
* September 20 2018
* Lab 4.1 - DO WHILE LOOP
*/

#include <iostream>
using namespace std;

int main()
{
   int i, input, sum;
   i=0;
   cout<<""<<endl;
   cout<<"This is the Do-While Loop code!\n"<<endl;
   cout<<"Put in integers one at a time."<<endl;
   cout<<"To stop the loop, press 0."<<endl;
   do{
      cout<<"Enter in an integer: "<<endl;
      cin>>input;
      sum+=input; 
      i++;
      if (input==0){
         i = 100;
      }
   } 
   while(i<100);
   cout<<"The sum total is: "<<sum<<endl;

}

