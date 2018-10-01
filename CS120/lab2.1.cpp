/* 
* Kim Huynh
* Section 07
* September 6 2018 
* Lab #2
*/ 

#include <iostream> 
using namespace std; 

int main()
{
	double x,y;               //Declare input variables. Used to be int. 
	double sum = 0, average;  //Declare two more variables. Used to be int. 
	
	cout<<"Please enter a number: "<<flush; 
	cin>>x; 
	cout<<"Please enter another number: "<<flush;
	cin>>y;
	sum = x + y;          //Calculate the sum 
	cout<<"The sum of "<<x<<" plus "<<y; 
	cout<<" is "<<sum<<".";
	average = sum/2; 
	cout<<"The average of your numbers is "; 
	cout<<average<<"."<<endl; 

	return 0;
}
