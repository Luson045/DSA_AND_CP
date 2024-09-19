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
};

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m, vector<int>(n, -1));
        ListNode* temp = head;
        int i=0,j=0,d=m,r=n,l=0,u=0;
        while(temp!=NULL){
            if((i+1)==r&&(j+1)!=d){
                j++;
                u++;
            }else if((j+1)==d){
                i--;
                r--;
            }else if(i-1<l){
                j--;
                d--;
            }else if(j-1<u){
                i++;
                l++;
            }
            arr[i][j]=temp->val;
            temp=temp->next;
        }
        return arr;
    }
};

int main() {
    FAST_IO;
    vector<vector<int>> arr(4, vector<int>(5, -1));
    for(vector<int>v:arr){
      for(int i:v){
        cout<<i<<" ";
      }
      cout<<endl;
    }
    // ********** BY LUSON BASUMATARY ********** //

    return 0;
}