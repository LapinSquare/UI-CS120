/* 
* Kim Huynh
* CS 120 Section 07
* September 13 2018
* Lab #3, IF STATEMENTS ONLY
*/ 

#include <iostream> 
using namespace std; 

int main() 
{
   //Declare integers.
   int first, second;

   //Ask.
   cout<<""<<endl;    
   cout<<"This is the If Version !"<<endl;
   cout<<""<<endl;
   cout<<"Enter in an integer: "<<endl; 
   cin>>first; 
   cout<<"Enter in another integer: "<<endl;
   cin>>second;
   cout<<""<<endl;
 
   //Process.
   if (first>second){
	cout<<first<<" is bigger than "<<second<<" !"<<endl;
   }
   if (second>first){
	cout<<second<<" is bigger than "<<first<<" !"<<endl;
   }
   if (first==second){
	cout<<first<<" is equal to "<<second<<" !"<<endl;
   }
   return 0;
   
}
