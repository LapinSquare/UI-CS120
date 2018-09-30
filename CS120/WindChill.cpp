/* 
* Kim Huynh 
* CS 120 Section 07
* September 14 2018
* Programming Assignment #2
*/  

#include <iostream> 
#include <cmath>
using namespace std;

//Prototype.
void ShowProgramHeader(); 

//Main function.
int main()
{ 
   //The needed variables: t = temp, v = wind speed. 
   double t, v, windChillF, windChillC;
  
   ShowProgramHeader();
   cout<<"\n"; 

   //Prompt user.
   cout<<"What is the temperature in Fahrenheit?"<<endl;
   cin>>t;
   cout<<t<<" F is the temperature."<<endl;
   cout<<"What is the wind speed in MPH?"<<endl; 
   cin>>v; 
   cout<<v<<" MPH is the wind speed."<<endl;

   //Calculate wind chill in F&C/ input in formula : 
   windChillF = 35.74+(0.6215*t)-(35.75*pow(v, 0.16))+(0.4275*t*pow(v, 0.16)); 
   windChillC = (windChillF-32.0)*5.0/9.0;

   //Repeat values : 
   cout<<"\n"<<endl;
   cout<<"The temperature (F) is: "<<t<<" F . "<<endl; 
   cout<<"The wind speed (MPH) is: "<<v<<" MPH . "<<endl;   
   cout<<"The wind chill (F) is: "<<windChillF<<" F . "<<endl;
   cout<<"The wind chill (C) is: "<< windChillC <<" C . "<<endl;
   cout<<"\n"; 
  
   return 0;
}

void ShowProgramHeader(){
   cout<<"\n";
   cout<<"Kim Huynh"<<endl;
   cout<<"CS 120 - Section 07"<<endl;
   cout<<"September 14 2018"<<endl;
   cout<<"Assignment #2- WindChill"<<endl;
}


