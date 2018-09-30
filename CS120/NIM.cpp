/*
* Kim Huynh
* CS 120 - Section 07
* September 28 2018
* Assignment #3 - NIM
*/

/* The game of NIM */  

#include <iostream> 
#include <cstdlib>

using namespace std;

//Prototypes 
void ShowProgramHeader(); 
void ShowRules();

int main() // start of program  
{  
   ShowProgramHeader();
   ShowRules();

   int i = 0;  //Counter for loop. 
   char ans;   //For when loop repeats.
   int minMove = 1;  //Gets rid of magic number.
   int maxMove = 3;  //Gets rid of magic number.
   int compScore = 0; //Computer Score
   int userScore = 0; //User Score
   while (i==0){

   int num_objects = 23; // Variable declarations 
   int current_player = 1; 
   int move; // Beginning of the main game loop  
   for (int j=0; j<23; j++){
      cout<<" * ";
   }
   cout<< " There are 23 objects. "<<endl;

      do  
      {  
	if (current_player == 1) { // conditional: if 
	   cout << "Player 1 enter your move (1-3): "; // output  
	   cin >> move; // input  
	   while (move < minMove || move > maxMove || move > num_objects){ 
		cout << "That's an illegal move! \nEnter a new move: "; 
		cin >> move;  
		}  
	} 
	else { // else part of conditional 
	   do { // make sure move is legal   
                if (num_objects==4){ 
                   move = 3; 
                } 
                else if (num_objects==3){ 
                   move = 2; 
                } 
                else if (num_objects==2){ 
                   move = 1; 
                } 
                else{
		   move = minMove + rand() % maxMove; // random computer move 
                }  
	   }  
	   while (move < minMove || move > maxMove || move > num_objects);  
	   cout << "Computer removed " << move << endl;  
	} 
   	num_objects = num_objects - move; // implement the move 
        for (int i=0; i<num_objects; i++){ 
           cout<<" * ";
        } 
        cout << num_objects << " objects remaining.\n";
        if (current_player==0){
           if (num_objects>=15&&num_objects<=23){
              cout<<"----Optimism is permissable at this point.\n"<<endl;
           }
           else if (num_objects>=10&&num_objects<15){
              cout<<"----Don't be too optimistic.\n"<<endl;
           }
           else if (num_objects<10&&num_objects>2){
              cout<<"----Your hopes and dreams might be crushed.\n"<<endl;
           }    
           else if (num_objects==2){
              cout<<"----The end is near.\n"<<endl; 
           }
           else { 
              cout<<"----It seems like you have lost the game, haha!\n"<<endl; 
           }
        }
   	current_player = (current_player + 1) % 2; // switch players  
      }  
      while (num_objects > 0); // end of the game loop  
 
   cout << "Player " << current_player << " wins!!! Hooray!\n"; 
   if (current_player == 1){ 
   	cout<<"You beated a simple program! Congrats!"<<endl;
        userScore++; 
   }  
   else{ 
   	cout<<"Wow, what a loser you are! You can't even beat a simple program!"<<endl; 
        compScore++; 
   }  
   cout<<"\nOut of "<<(compScore+userScore)<<" game(s)..."<<endl; 
   cout<<"The computer has won "<<compScore<<" game(s)."<<endl; 
   cout<<"You have won "<<userScore<<" game(s)."<<endl; 
   cout<<"\nWould you like a rematch (y/n)?"<<endl; 
   cin>>ans; 
   if (ans=='y'){ 
   	cout<<"\nHave fun!\n"<<endl; 
   	continue; 
   } 
   else{ 
   	i=1; 
   } 
 
   } 
 
   cout<<"\nThanks for playing my NIM program!\n"<<endl;

   //cin.ignore ();  
   //cout << "\nPress enter to quit.\n"; 
   //cin.ignore ();  
   return 0 ; 
} 

void ShowProgramHeader(){ 
   cout<<"\nKim Huynh"<<endl; 
   cout<<"CS 120 - Section 07"<<endl; 
   cout<<"September 28 2018"<<endl;
   cout<<"Assignment #3 - NIM\n"<<endl;
}
void ShowRules(){ 
   cout<<"Welcome to the game of NIM!"<<endl; 
   cout<<"The last one to remove the object(s) out of 23 loses!"<<endl;
   cout<<"Have fun!\n"<<endl;  
}
