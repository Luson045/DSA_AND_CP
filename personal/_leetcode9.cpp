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

    bool isPalindrome(int x) {
        string s = to_string(x);
        int length = s.length()-1;
        string sub1,sub2;
        if(length%2!=0){
            sub1 = s.substr(0,(length/2)+1);
            sub2 = s.substr((length/2)+1,(length/2)+1);
        }else{
            sub1 = s.substr(0,(length/2));
            sub2 = s.substr((length/2)+1,(length/2));
        }
        reverse(s.begin(), s.end());
        if(sub1==sub2)
            return true;
        return false;
    }

int main() {
    FAST_IO;
    int t;
    cin>>t;
    cout<<isPalindrome(t);

    // ********** BY LUSON BASUMATARY ********** //

    return 0;
}