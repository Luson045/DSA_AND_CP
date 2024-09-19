#include <iostream>
using namespace std;

struct node {
  int val;
  node * next;
  //constructor
  node(int value):val(value),next(nullptr){};
};
void add(node** head, int value){
    node* newNode = new node(value);
    newNode->next = *head;
    *head = newNode;
};
int main(){
  node* head= new node(11);
  cout<<"head value"<<head->val<<endl;
  add(&head,2);
  node * current = head;
  while(current->next!=NULL){
    cout<<current->val<<",";
    current=current->next;
  }
  cout<<current->val;
  return 0;
}