/*
* Kim Huynh 
* CS - Section 07 
* October 26 2018
* Program #6 - Lottery.
*/ 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <ctype.h>
using namespace std;

/*
* Rules for the lotteries can be found online. 
* Those rules will be used in this code for the end result.
* Fun fact: the test cases are based on 10/24's numbers! :)
*/

//Prototypes 
void ShowProgramHeader();
void GenerateTicket(string choice, int ticket[], int &lastn, int nA);
void Shuffle(int ar[], int length);
void CompareTicket(int a1[], int a2[], int last1, int last2, string choice, int nA);
int main(){ 
  ShowProgramHeader();
  srand(time(NULL));
  int nSlots = 5;
  string ans;
  int UserTicket[nSlots];
  int WinningTicket[nSlots];
  int LastMPB;
  int WinningMPB;
  cout<<"THIS IS A TEST"<<endl;
  cout<<"What would you like to play?"<<endl; 
  cout<<"MegaMillions(M) or PowerBall(P)?"<<endl; 
  cin>>ans;
  cout<<"Please enter "<<nSlots<<" numbers."<<endl; 
  for (int i=0; i<nSlots; i++){ 
    cin>>UserTicket[i];
  } 
  cout<<"Please enter an additional "; 
  if (ans=="m"||ans=="M"||ans=="MegaMillions"){
    cout<<"megaball number."<<endl;
  }
  else{
    cout<<"powerball number."<<endl;
  }
  cin>>LastMPB;
  GenerateTicket(ans, WinningTicket, WinningMPB, nSlots);
  CompareTicket(WinningTicket, UserTicket, WinningMPB, LastMPB, ans, nSlots); 
} 

void ShowProgramHeader(){ 
  cout<<"\nKim Huynh"<<endl; 
  cout<<"CS - Section 07"<<endl;
  cout<<"October 26 2018"<<endl; 
  cout<<"Program #6 - Lottery\n"<<endl;
} 
void GenerateTicket(string choice, int ticket[], int &lastn, int nA){ 
  if (choice=="m"||choice=="M"||choice=="MegaMillions"){ 
    for (int i=0; i<nA; i++){
      ticket[i]=rand()%70+1; //Range 1-70
      //cout<<ticket[i]<<" "; TEST if randomized.
    }
    lastn=rand()%25+1; //Range 1-25
    //TEST CODE FOR MEGAMILLIONS: 
    /*ticket[0]=5;  
    ticket[1]=28;             
    ticket[2]=62;
    ticket[3]=65;
    ticket[4]=70;
    lastn=5;*/     
  }
  else if (choice=="p"||choice=="P"||choice=="Powerball"){ 
    for (int i=0; i<nA; i++){
      ticket[i]=rand()%69+1; //Range 1-69
    }
    lastn=rand()%26+1; //Range 1-26
    //TEST CODE FOR POWERBALL: 
    /*ticket[0]=3;
    ticket[1]=21;
    ticket[2]=45;
    ticket[3]=53;
    ticket[4]=56;
    lastn=22;*/
  }
  Shuffle(ticket, nA);
  cout<<"\nHere are the winning numbers..."<<endl; 
  cout<<"----------------------------------"<<endl;
  for (int i=0; i<nA; i++){
    cout<<ticket[i];
    cout<<" ";
  }
  cout<<"- "<<lastn<<endl;
  cout<<"----------------------------------"<<endl;
}
void Shuffle(int ar[], int leng){
  //As shown in class...
  int iTmp;
  int j;
  for (int i=0; i<leng; i++){
    j = rand()%leng;
    iTmp=ar[j];
    ar[j]=ar[i];
    ar[i]=iTmp;
  }
}

void CompareTicket(int a1[], int a2[], int last1, int last2, string choice, int nA){ 
  cout<<"\nYour results : "<<endl;
  int counter = 0;
  int lastBall = 0;
  for (int i=0; i<nA; i++){
    if (a1[i]==a2[i]){
      counter++;
    }
  }
  cout<<"You have "<<counter<<" numbers correct."<<endl;
  if (last1==last2){
    if (choice=="m"||choice=="M"||choice=="MegaMillions"){ 
      cout<<"And you got the megaball number!"<<endl;
    }
    else if (choice=="p"||choice=="P"||choice=="Powerball"){ 
      cout<<"And you got the powerball number!"<<endl;
    }
    lastBall++;
  }
  cout<<"\n|||||||||||||||||||\n"<<endl;
  /*  
  * The rules of MegaMillions and Powerball differ a little bit.
  * I accounted for the different rules below. 
  * Hence the need for the if-else statement.
  */
  if (choice=="m"||choice=="M"||choice=="MegaMillions"){ 
    if (counter==5&&lastBall==1){
      cout<<"You earn the JACKPOT! Congrats!"
          <<" Enjoy being rich while it lasts!\n"<<endl; 
    }
    else if (counter==5){ 
      cout<<"You earn $1,000,000! Don't quit your job just yet!\n"<<endl; 
    }
    else if (counter==4&&lastBall==1){ 
      cout<<"You earn $10,000! Is it enough for your student loans?\n"<<endl; 
    }
    else if (counter==4){ 
      cout<<"You earn $500! Not enough for an iPhoneX.\n"<<endl;
    }
    else if (counter==3&&lastBall==1){
      cout<<"You earn $200! Pay off your overdue electricity bill!\n"<<endl;
    }
    else if ((counter==2&&lastBall==1)||counter==3){ 
      cout<<"You earn $10. Congrats, I suppose.\n"<<endl;  
    }
    else if (counter==1&&lastBall==1){
      cout<<"You earn $4. Go treat yourself to cheap icecream.\n"<<endl;
    }
    else if (lastBall==1){
      cout<<"You earn $2. You can afford a soda at least.\n"<<endl;
    }
    else{
      cout<<"You earn $0. Back to working and saving for your retirement funds.\n"<<endl; 
    }
  }
  else if (choice=="p"||choice=="P"||choice=="Powerball"){ 
    if (counter==5&&lastBall==1){
      cout<<"You earn the JACKPOT! Congrats!"
          <<" Enjoy being rich while it lasts!\n"<<endl; 
    }
    else if (counter==5){ 
      cout<<"You earn $1,000,000! Don't quit your job just yet!\n"<<endl; 
    }
    else if (counter==4&&lastBall==1){ 
      cout<<"You earn $50,000! Is it enough for your student loans?\n"<<endl; 
    }
    else if (counter==4||(counter==3&&lastBall==1)){ 
      cout<<"You earn $100. Not enough for an iPhoneX.\n"<<endl;
    }
    else if ((counter==2&&lastBall==1)||counter==3){ 
      cout<<"You earn $7. Congrats, I suppose.\n"<<endl;  
    }
    else if (lastBall==1||(lastBall==1&&counter==1)){
      cout<<"You earn $4. Go treat yourself to cheap icecream.\n"<<endl;
    }
    else{
      cout<<"You earn $0. Back to working and saving for your retirement funds.\n"<<endl; 
    }
  }
  
}
