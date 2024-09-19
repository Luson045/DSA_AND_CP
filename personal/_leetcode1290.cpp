/*
 *  Created by LUSON045
 *  This template is personalized for CP contests and designed with efficiency in mind.
 */

#include <bits/stdc++.h>
using namespace std;

// ********** FAST INPUT/OUTPUT ********** //
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// ********** TYPE DEFINITIONS ********** //
typedef long long ll;
typedef unsigned long long ull;

// ********** MACROS ********** //
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

// ********** CUSTOM CONSTANTS ********** //
const int MOD = 1e9 + 7;
const int INF = INT_MAX;

// ********** LOOP SHORTCUTS ********** //
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = a; i >= b; i--)
#define FOREACH(x, v) for (auto &x : v)

// ********** DEBUGGING HELPER ********** //
#define debug(x) cerr << "[DEBUG] " << #x << " = " << x << endl

// ********** MODULAR EXPONENTIATION ********** //
ll mod_exp(ll base, ll exp, ll mod = MOD) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp= head;
        int count=-1, answer=0;
        if(!temp)
            return 0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            answer+=pow((temp->val),count);
            count--;
        }
        return answer;
    }
};
int main() {
    FAST_IO;
    Solution s1;
    ListNode l = ListNode(1);
    l.next = new ListNode(0);
    cout<<s1.getDecimalValue(&l);


    // ********** BY LUSON BASUMATARY ********** //

    return 0;
}