#include<iostream>
using namespace std;

class Node{
  public:
    int val;
    Node* next;

    Node(int val):val(val),next(nullptr){};
};

Node* createCircularLinkedList(int n){
    Node* head = new Node(1);
    Node* current = head;
    
    for(int i=2;i<=n;++i){
        current->next = new Node(i);
        current = current->next;
    }
    
    current->next = head;
    return head;
}

int josephus(int n, int k){
  Node* head = createCircularLinkedList(5);
  Node* current = head;
  while(current->next!=current){
    for(int i=0;i<k;i++){
      current=current->next;
    }
    current->next=current->next->next;
  }
  int winner = current->val;
  delete current;
  return winner;
}

int main(){
  int n,k;
  cin>>n>>k;
  cout<<josephus(n,k);
  return 0;
}
