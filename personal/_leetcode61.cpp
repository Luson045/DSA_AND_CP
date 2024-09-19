#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode*next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp= head;
        int length=1;
        //write the exception when temp->next=NULL
        if(temp==NULL||temp->next==NULL||k==0)
            return temp;
        while(temp->next!=NULL){
            temp=temp->next;
            length++;
        }
        k=k%length;
        int steps=length-k;
        temp->next=head;
        for(int i=1;i<steps;i++)
            head=head->next;
        temp=head;
        head=head->next;
        temp->next=nullptr;
        return head;
    }
};