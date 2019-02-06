/*
* Kim Huynh
* CS 120 - Section 07
* 19 October 2018
* Program 5 - Rock, Paper, Scissors, Lizard, Spock
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <ctype.h>
using namespace std;

//Prototypes
void ShowProgramHeader();
char P1_Input(); //Player 1 Input 
char P2_Input(); //Player 2 (Computer)
void outcome(char P1, char P2);

int main(){
  int counter=0;
  char P1_Ans; //Player 1 Answer
  char P2_Ans; //Player 2 Answer
  ShowProgramHeader();
  //Loops make it easier to test. :)
  while (counter!=1){
    P1_Ans = P1_Input();
    if (P1_Ans=='Z'||P1_Ans=='z'){ 
      counter++; 
      break;
    }
    P2_Ans = P2_Input();
    outcome(P1_Ans,P2_Ans); 
    cout<<"\n";
  } 
  cout<<"\nThanks for playing! :-)\n"<<endl;
}

void ShowProgramHeader(){ 
  cout<<"\nKim Huynh"<<endl;
  cout<<"CS 120 - Sectiom 07"<<endl;
  cout<<"19 October 2018"<<endl;
  cout<<"Program #5 - Rock, Paper, Scissors, Lizard, Spock\n"<<endl;  
} 
char P1_Input(){
  char ans; 
  cout<<"Player 1, choose from one of the following:"<<endl; 
  cout<<"Rock (R), Paper (P), Scissors(S), " 
      <<"Lizard (L), Spock (K)"<<endl;
  cout<<"Press Z to exit."<<endl;
  cin>>ans; 
  cout<<"You chose "<<ans<<" ! "<<endl;; 
  return ans;
} 
char P2_Input(){
  char ans; 
  //I want a somewhat random generator, hence srand for seed.
  srand(time(NULL));
  //This was used to test the function... 
  /*cout<<"\nPlayer 2, choose from one of the following:"<<endl; 
  cout<<"Rock (R), Paper (P), Scissors(S), " 
      <<"Lizard (L), Spock (K)"<<endl;
  cin>>ans; 
  cout<<"Player 2 chose "<<ans<<" ! \n\n";*/
  char Arr[5]={'R','P','S','L','K'};
  ans = Arr[rand()%5]; //Range 0-4.
  cout<<"\n*-*-*-*-*\n"<<endl; //Looks pretty.
  cout<<"The computer chose "<<ans<<" ! \n\n";
  return ans;
}
void outcome(char P1, char P2){ 
  /*
  * R < K&P 
  * P < L&S
  * S < K&R 
  * L < R&S 
  * K < L&P
  */
  if (toupper(P1)==toupper(P2)){ 
    cout<<"It's a tie!\n"<<endl;
  } 
  //Note that the lowercase for P2 is only for when humans play (test). 
  //Otherwise, computer always chooses uppercase. 
  else if ((P2=='R'||P2=='r')&&(P1=='K'||P1=='P'||P1=='k'||P1=='p')){ 
    cout<<"Player 1 Wins!\n"; 
  }
  else if ((P2=='P'||P2=='p')&&(P1=='L'||P1=='S'||P1=='l'||P1=='s')){ 
    cout<<"Player 1 Wins!\n"; 
  }
  else if ((P2=='S'||P2=='s')&&(P1=='K'||P1=='R'||P1=='k'||P1=='r')){ 
    cout<<"Player 1 Wins!\n"; 
  }
  else if ((P2=='L'||P2=='l')&&(P1=='R'||P1=='S'||P1=='r'||P1=='s')){ 
    cout<<"Player 1 Wins!\n"; 
  }
  else if ((P2=='K'||P2=='k')&&(P1=='L'||P1=='P'||P1=='l'||P1=='p')){ 
    cout<<"Player 1 Wins!\n"; 
  }
  else { 
    //cout<<"Player 2 Wins!\n";
    cout<<"The computer Wins!\n";
  }
} 


