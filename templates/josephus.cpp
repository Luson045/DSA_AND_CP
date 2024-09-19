#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node(int val) : value(val), next(nullptr) {}
};

Node* createCircularLinkedList(int n) {
    Node* head = new Node(1);
    Node* current = head;
    
    for (int i = 2; i <= n; ++i) {
        current->next = new Node(i);
        current = current->next;
    }
    
    current->next = head;
    return head;
}

int josephus(int n, int k) {
    Node* head = createCircularLinkedList(n);
    Node* current = head;
    while (current->next != current) {
        for (int i = 1; i < k-1; i++) {
            current = current->next;
        }
        
        // Eliminate the k-th node
        Node* temp = current->next;
        cout << "Removing friend " << temp->value << endl;
        current->next = temp->next;
        delete temp;  // Free memory of the eliminated node
        if(k==2||k==n+2) current=current->next;
    }
    
    // The last remaining node is the winner
    int winner = current->value;
    return winner;
}

int main(){
  int n,k;
  cin>>n>>k;
  cout<<josephus(n,k);
  return 0;
}