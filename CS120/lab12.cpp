/* 
* Kim Huynh
* CS 120 - Section 07
* November 29 2018
* Lab 12 - 2D Arrays
*/

/* !!!!
* Please note that I start from 0 
* for rows and columns as my number system. 
* EX: Row 0, Column 0 would be the 1st slot.
* That's why a char at "row 5, column 5" 
* would look a bit off (6,6 in reality).
* However, it fits with the designed system. :)
* 30 rows/ 40 columns in total anyways. 
*/
#include <iostream>
using namespace std;

//Necessary global variables
const int Height = 30; //Row
const int Width = 40;  //Column

//Prototypes 
void init_array(char ar[][Width]);
void print_array(char ar[][Width]);
//r=row, c=column. 
void find(char ar[][Width], int &r, int &c, char target);

int main(){
  char targetC;          //target character
  //-1 helps signify if coordinates changed or not.
  int targetRow = -1;    //target's row
  int targetColumn = -1; //target's column
  char Array2D[Height][Width];
  cout<<endl;
  init_array(Array2D);
  print_array(Array2D);
  cout<<endl;
  cout<<"What character would you like to look for?"<<endl;
  cin>>targetC;
  find(Array2D, targetRow, targetColumn, targetC);
  if (targetRow==-1){ //AKA default coordinate not changed.
    cout<<targetC<<" not found. :-("<<endl;
  } 
  else{
    //Prints last coordinate where char is found.
    //Repeated appearences are dealt with by find().
    cout<<targetC<<" can be found at the following location: "
        <<"Row "<<targetRow<<" , Column "<<targetColumn<<endl;
  }
  return 0;
}

void init_array(char ar[][Width]){ 
  int row, col;
  char tempC;
  for (int i=0; i<Height; i++){
    for (int j=0; j<Width; j++){
      ar[i][j] = 'a';
    }
  }
  for (int k=0; k<10; k++){
    cout<<"Character #"<<k+1<<" -";
    cout<<"Please enter in the following in this exact order: "
        <<"Row number, column number, character"<<endl;
    cin>>row>>col>>tempC;
    //Check if coordinates exceeds limit.
    if (row>=Height|| col>=Width){
      cout<<"That is not a valid row or column."<<endl;
      k--;
      continue;
    }
    else{
      ar[row][col]=tempC;
    }
  }
}
void print_array(char ar[][Width]){
  cout<<endl;
  for (int i=0; i<Height; i++){
    for (int j=0; j<Width; j++){
      cout<<ar[i][j]<<" ";
    }
    cout<<endl;
  }
}
void find(char ar[][Width], int &r, int &c, char target){   
  int counter=0; //To deal with repeats.
  for (int i=0; i<Height; i++){
    for (int j=0; j<Width; j++){
      if (ar[i][j]==target){
        //If it repeats...print location.
        if (counter>=1){ 
          if (counter<2){ //Prevent repeated warnings. 
            cout<<target<<" has appeared more than once."<<endl;
          }
          //Print repeated location(s)
          cout<<target<<" can be found at the following location: "
              <<"Row "<<r<<" , Column "<<c<<endl;
        }
        r=i;
        c=j;
        counter++;
      }
    }
  }
}
