/*
* Kim Huynh
* CS 120 - Section 07
* December 5 2018
* Program 9 - Recursion and Linked Lists
*/ 

#include <iostream>
#include <cmath>
#include <string>
using namespace std; 

//Linked list
struct Node{
  string info; 
  struct Node *next;
}; 
typedef struct Node *NodePtr; 
NodePtr head = NULL;

//Prototypes 
int Fibo(int n); //Fibonacci
double sRoot(double n, double est, double tol); //Square root
void insertList(string word, NodePtr &n); //Insertion
int lengthList(Node *n); //Length
string shortest(Node *n, string &shortw); //Shortest word
string longest(Node *n, string &longw); //Longest word
int searchList(Node *n,string word); //Search
void printList(); //Displays list.

int main(){
  int fiboN;        //Fibonacchi response
  double sr_n;      //Square root number
  double sr_est;    //Square root estimate
  double sr_tol;    //Square root tolerance
  string response;  //For adding to linked list
  string shortWord; //Initialize short word later
  string longWord;  //Initialize long word later
  string searchW;   //Search for word response
  cout<<"What number would you like to calculate with Fibonacci?"<<endl; 
  cin>>fiboN;
  cout<<"Answer: "<<Fibo(fiboN)<<endl;
  cout<<"What number would you like to square root?"<<endl;
  cout<<"Enter in this exact order: number, approximate answer, specified tolerance."<<endl;
  cin>>sr_n>>sr_est>>sr_tol; 
  cout<<"Answer: "<<sRoot(sr_n,sr_est,sr_tol)<<endl;
  cout<<"Now enter in some words to make a list:"<<endl;
  while(response!="stop"){
    cin>>response;
    if (response=="stop"){
      break; //Prevents "stop" from being registered in list.
    }
    insertList(response, head);
  }
  cout<<"----------\n"<<endl;
  cout<<"List : ";
  printList();
  cout<<"\n"<<endl;
  cout<<"The list is "<<lengthList(head)<<" words long."<<endl;
  //Initialize beforehand. Makes recursion work.
  shortWord=head->info;
  longWord=head->info;
  cout<<"The shortest word is "<<shortest(head,shortWord)<<"."<<endl;
  cout<<"The longest word is "<<longest(head,longWord)<<"."<<endl;
  cout<<"Insert a word you would like to look for: "<<endl;
  cin>>searchW;
  if (searchList(head, searchW)){
    cout<<"The word "<<searchW<<" is in the list.\n"<<endl; 
  }
  else{
    cout<<"The word "<<searchW<<" is NOT in the list.\n"<<endl; 
  }
  return 0;
}

int Fibo(int n){
  if (n==0||n==1){
    return n;
  }
  else{
    return Fibo(n-1)+Fibo(n-2);
  }
}

double sRoot(double n, double est, double tol){
  if (abs(pow(est,2)-n)<=tol){
    return est;
  }
  else{
    return sRoot(n,((pow(est,2)+n)/(2*est)),tol);
  }
}

void insertList(string word, NodePtr &n){ 
  if (n==NULL){
    NodePtr x = new Node; 
    x->info=word; 
    x->next=NULL; 
    n=x;
  }
  else{
    insertList(word, n->next);
  }
  
  /*Iterative version :
  NodePtr x = new Node;
  x->info=word; 
  x->next=NULL;
  if (head==NULL){
    head=x;
  }
  else{
    x->next=head; 
    head = x;
  }*/
}

int lengthList(Node *n){
  if (n==NULL){
    return 0;
  } 
  else {
    return 1+lengthList(n->next);
  }
}

string shortest(Node *n, string &shortw){
  if (n==NULL){ 
    return shortw;
  }
  else{
    if (n->info.length()<shortw.length()){
      shortw=n->info;
    }
  }
  return shortest(n->next, shortw);
  
  /* Iterative version:
  string temp = n->info;
  while (n!=NULL){
    if(n->info.length()<=temp.length()){
      temp = n->info;
    }
    n = n->next;
  }
  return temp;*/ 
}

string longest(Node *n, string &longw){
  if (n==NULL){ 
    return longw;
  }
  else{
    if (n->info.length()>longw.length()){
      longw=n->info;
    }
  }
  return longest(n->next, longw);
  
  /* Iterative version :
  NodePtr n = head; 
  string temp = n->info;
  while (n!=NULL){
    if(n->info.length()>=temp.length()){
      temp = n->info;
    }
    n = n->next;
  }
  return temp;*/ 
}

int searchList(Node *n,string word){  
  if (n==NULL){ 
    return 0;
  }
  if (n->info==word){
    return 1;
  }
  else {
    return searchList(n->next,word);
  }
  return 0;
  
  /* Iterative version : 
    while (n!=NULL){
    if(n->info==word){
      return 1;
    }
    n = n->next;
  }*/
}

void printList(){
  NodePtr n = head; 
  while (n!=NULL){
    cout<< n->info <<"  ";
    n = n->next;
  }
}