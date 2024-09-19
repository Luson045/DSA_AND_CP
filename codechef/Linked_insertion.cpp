#include <iostream>
using namespace std;

class node {
  public:
  int val;
  node * next;
  //constructor
  node(int value):val(value),next(nullptr){};
};
class LinkedList{
  public:
  node * head;
  node * tail;
  //function for inserting at front
  void insert_f(int val){//complexity = O(1)
    node * newnode = new node(val);
    newnode->next=head;
    head=newnode;
    if (tail == NULL) { // If the list was empty
      tail = newnode;
    }
  };
  //function to insert at back
  void insert_b(int val) {//complexity = O(1)
    node *newnode = new node(val);
    if (head == NULL) { // Case when the list is empty
        head = newnode;
        tail = newnode;
    } else {
      tail->next= newnode;
      tail=newnode;       // Update the tail pointer to the new node
    }
  }
  void insert_k(int val,int k){//complexity = O(n)
    node * newnode= new node(val);
    node * current = head;
    int temp=1;
    if(k==0){
      insert_f(val);
      return;
    }
    if(head==NULL){
      head=newnode;
      return;
    }
    while(current->next!=NULL){
      if(temp==k){
        break;
      }
      current=current->next;
      temp++;
    }
    if(current->next==NULL){
      insert_b(val);
    }else{
      newnode->next=current->next;
      current->next=newnode;
    }
  }
  //function to display a linked list;
  void display(){//complexity = O(n)
    if (head==NULL){
      cout<<-1;
    }else{
      node * offset=head;
      while(offset->next!=NULL){
        cout<<offset->val<<",";
        offset=offset->next;
      }
      cout<<offset->val<<endl;
    }
  }
  //function for getting head value
  int gethead(){//complexity = O(1)
    if (head==NULL)
      return -1;
    else
      return head->val;
  };
  //function to get last value
  int gettail(){//complexity = O(1)
    if(head==NULL)
      return -1;
    else{
      if(tail==NULL)
        return -1;
      else
        return tail->val;
    }
  }
};

int main(){
  LinkedList * list= new LinkedList();
  list->insert_f(5);
  cout<<"head val: "<<list->gethead()<<endl;
  list->insert_f(7);
  cout<<"head val: "<<list->gethead()<<endl;
  list->insert_b(11);
  cout<<"tail val: "<<list->gettail()<<endl;
  list->insert_k(12,1);
  list->insert_k(13,2);
  list->insert_k(1,0);
  list->insert_k(6,6);
  cout<<"linked list is: "<<endl;
  list->display();
  cout<<"tail val: "<<list->gettail()<<endl;
  cout<<"head val: "<<list->gethead()<<endl;
}