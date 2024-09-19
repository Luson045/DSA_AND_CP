#include <iostream>
using namespace std;

bool isprime(int n){
  if(n==2)
    return true;
  if(n%2==0)
    return false;
  for(int i=3;i*i<=n;i=i+2){
    if(n%i==0)
      return false;
  }
  return true;
}

int findprime(int num){
  while(!isprime(++num));
  return num;
}

class Node{
  public:
  int data;
  Node * next;
  Node * prev;
  Node(int val):data(val),prev(nullptr),next(nullptr){};
};
class LinkedList{
  public:
  Node * head;
  Node * tail;
  void kthLargest(int k){
    int max=INT_MAX;
    Node * ptr = nullptr;
    for(int i=0;i<k;i++){
      Node * temp = head;
      int temp_max=INT_MIN;
      while(temp!=NULL){
        if(temp->data>temp_max&&temp->data<max){
          temp_max=temp->data;
          ptr = temp;
        }
        temp=temp->next;
      }
      max=temp_max;
    }
    cout<<"kth largest is "<<max<<endl;
    cout<<"ptr value: "<<ptr->data<<endl;
    int prime=findprime(max);
    Node * newnode = new Node(prime);
    newnode->next=ptr->next;
    newnode->prev=ptr;
    ptr->next=newnode;
  }
  void insert(int val){
    Node * temp = tail;
    Node * newnode = new Node(val);
    if(head==NULL&& tail==NULL){
      head=newnode;
      tail=newnode;
      return;
    }
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
  }
  void show(){
    Node * temp = head;
    while(temp!=NULL){
      cout<<temp->data<<",";
      temp=temp->next;
    }
    cout<<endl;
  }
};
int main(){
  LinkedList * list = new LinkedList();
  int val;
  for(int i=0;i<10;i++){
    cin>>val;
    list->insert(val);
  }
  list->show();
  cin>>val;
  list->kthLargest(val);
  list->show();
  return 0;
}