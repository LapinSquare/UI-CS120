/*
* Kim Huynh 
* CS 120 - Section 07
* November 16 2018
* Program #8 - States
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

//Global variables 
const int Max_Line = 128;
const int Max_States = 50;
//For struct primarily.
const int maxStateC = 33; //Char allowed for state
const int maxCapitalC = 33; //Char allowed for capital
const int maxPopC = 32; //Char allowed for population

struct stateInfo{
  char state[maxStateC];
  char capital[maxCapitalC];
  char pop[maxPopC];
  int nPop; //Population in int format. Makes life easy for me.
};
typedef struct stateInfo State;

//Prototypes. What they do is explained by their name.
//A lot of these are from class notes, excluding the sorts.
int ReadData(State sArray[]); 
void GetSubString(char s[], int iStart, int iEnd, char dst[]);
void RemoveCommas(char s[]);
void TrimBlanks(char s[]);
void SortByState(State sArray[]);
void SortByPop(State sArray[]);
void LessThan5Mil(State sArray[]);
void MoreThan10Mil(State sArray[]);

int main(){
  State stateData[Max_States];
  cout<<"|||||||||||||||||||||||||||||||||||"<<endl;
  //State information is covered in ReadData.
  ReadData(stateData);
  cout<<"|||||||||||||||||||||||||||||||||||"<<endl;
  cout<<"Here is the info sorted alphabetically by state :"<<endl;
  SortByState(stateData);
  cout<<"|||||||||||||||||||||||||||||||||||"<<endl;
  cout<<"Here is the info sorted by population, smallest to largest :"<<endl;
  SortByPop(stateData);
  cout<<"|||||||||||||||||||||||||||||||||||"<<endl;
  cout<<"Here are the states whose population is less than 5 million :"<<endl;
  LessThan5Mil(stateData);
  cout<<"|||||||||||||||||||||||||||||||||||"<<endl;
  cout<<"Here are the states whose population is more than 10 million :"<<endl;
  MoreThan10Mil(stateData);
  cout<<"\n";
  return 0;
}

int ReadData(State sArray[]){
  char stateFile[30];
  ifstream fIn;
  //Just in case, to make it more versatile...
  cout<<"Please enter in state file to be analyzed: ";
  //In this case it's "states.dat".
  cin>>stateFile;
  fIn.open(stateFile, ios::in); 
  if (!fIn){ //Error checking.
    cout<<"There was an error opening the file."<<endl;
  }
  cout<<"Here is all the state information :"<<endl;
  int i=0;
  char line[Max_Line];
  //Throw away header (first 6 lines) below.
  for (int i=0; i<6; i++){
    fIn.getline(line, Max_Line);
  }
  while (fIn.getline(line, Max_Line)&&i<Max_States){
    GetSubString(line,5,20,sArray[i].state);
    GetSubString(line,20,45,sArray[i].capital);
    GetSubString(line,46,66,sArray[i].pop);
    RemoveCommas(sArray[i].pop);
    TrimBlanks(sArray[i].state);
    TrimBlanks(sArray[i].capital);
    TrimBlanks(sArray[i].pop);
    sArray[i].nPop = atoi(sArray[i].pop); //Convert to int.
    
    cout<<"State Information (#"<<i+1<<"): "<<sArray[i].state<<endl;
    cout<<"\tCapital : "<<sArray[i].capital<<endl;
    cout<<"\tPopulation : "<<sArray[i].nPop<<endl;
    cout<<" - "<<endl;
    i++;
  }
  fIn.close();
  return 1;
} 
void GetSubString(char s[], int iStart, int iEnd, char dst[]){
  //sIndex=source index, dest = destination. 
  int sIndex = iStart; 
  int dest = 0;
  while (sIndex<iEnd && s[sIndex]!='\0'){
    dst[dest] = s[sIndex];
    sIndex++;
    dest++;
  }
  dst[dest] = '\0'; //Sealing it.
}
void RemoveCommas(char s[]){
  int i = 0;
  int dest = 0; 
  while (s[i]!='\0'){
    if ((s[i]!=',')&&(s[i]!=' ')){
      s[dest]=s[i];
      dest++;
    }
    i++;
  }
  s[dest]='\0'; //Sealing it.
}
void TrimBlanks(char s[]){
  int len = strlen(s);
  int i= len;
  while(s[i]==' '){
    i--;
    s[i]='\0';
  }
}
void SortByState(State sArray[]){
  State tmp[Max_States];
  int counter;
  bool track; //Tracks the loop.
  for (int i=0; i<(Max_States-1); i++){
    for (int j =(i+1); j<Max_States; j++){
      // Reset counter and track every iteration.
      counter=0;
      track=true;
      while(track){ //While track is true...
        if (sArray[i].state[counter]>sArray[j].state[counter]){
          tmp[i]=sArray[i];
          sArray[i]=sArray[j];
          sArray[j]=tmp[i];
          track=false;
        }
        else if (sArray[i].state[counter]==sArray[j].state[counter]){
          counter++;
          continue;
        }
        else{
          break;
        }
      }
    } 
  }
  //Prints.
  for (int i=0; i<Max_States; i++){
    cout<<sArray[i].state<<" ";
    cout<<"("<<sArray[i].capital<<", ";
    cout<<sArray[i].pop<<")"<<endl;
  }
}
void SortByPop(State sArray[]){
  State tmp[Max_States];
  for (int i=0; i<(Max_States-1); i++){
    for (int j =(i+1); j<Max_States; j++){
      if (sArray[i].nPop>sArray[j].nPop){
        tmp[i]=sArray[i];
        sArray[i]=sArray[j];
        sArray[j]=tmp[i];
      }
    }
  }
  for (int i=0; i<(Max_States); i++){
    cout<<sArray[i].pop;
    //Makes spacing look nicer. :)
    if (sArray[i].nPop<1000000){
      cout<<"  ";
    }
    else if (sArray[i].nPop<10000000){
      cout<<" ";
    }
    cout<<"    from "<<sArray[i].state<<", ";
    cout<<sArray[i].capital<<endl;
  }
}
void LessThan5Mil(State sArray[]){
  for (int i=0; i<(Max_States); i++){
    if (sArray[i].nPop<5000000){
      cout<<sArray[i].state<<", ";
      cout<<sArray[i].capital;
      cout<<", population "<<sArray[i].nPop<<endl;
    }
  }
}
void MoreThan10Mil(State sArray[]){
  for (int i=0; i<(Max_States); i++){
    if (sArray[i].nPop>10000000){
      cout<<sArray[i].state<<", ";
      cout<<sArray[i].capital;
      cout<<", population "<<sArray[i].nPop<<endl;
    }
  }
}