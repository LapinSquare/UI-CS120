/*
* Kim Huynh
* CS 120 - Section 07
* September 20 2018
* Lab 4.2 - NESTED LOOPS
*/

#include <iostream>
using namespace std;

int main()
{
   cout<<"    0 1 2 3 4 5 6 7 8 9"<<endl;  //Initial row.
   for(int i=40;i<120;i+=10){              //ROW LOOP
      cout<<i<<flush;
      if (i<100){ 
         cout<<" ";                        //Makes spacing nicer. :)
      } 
      for(int a=0; a<10; a++){             //COLUMN LOOP
         cout<<" "<<static_cast<char>(a+i)<<flush; 
      } 
      cout<<""<<endl;
   } 
   return 0;
}

