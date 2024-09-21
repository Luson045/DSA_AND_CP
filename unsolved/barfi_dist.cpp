#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    vector<ll>prefix(n+1,0);
    for(int i=0;i<n;i++)
      cin>>a[i];
    for(int i=0;i<n;i++)
      prefix[i+1]=prefix[i]+a[i];
    ll answer=min(a[0],a[n-1]);
    int first_index=0;
    int count=1;
    ll temp=a[0];
    for(int i=1;i<n;i++){
      if(count==k){
        answer=prefix[n]-prefix[i-1];
        break;
      }
      if(temp>prefix[n]-prefix[i]){
        count++;
        temp = 0;
      }
      temp+=a[i];
    }
    ll backwardAnswer=min(a[0],a[n-1]);
    count=1;
    temp=a[n-1];
    for(int i=n-2;i>=0;i--){
      if(count==k){
        backwardAnswer=prefix[i+1];
        break;
      }
      if(temp>prefix[i+1]){
        count++;
        temp=0;
      }
      temp+=a[i];
    }
    ll final = max(answer,backwardAnswer);
    cout<<final<<endl;
    return 0;
}

//correct answr

/*
#include <iostream>  
#include <vector>  
#include <algorithm> 
using namespace std;  
  
int main() {  
   int n, k;  
   cin >> n >> k;  
  
   vector<int> a(n);  
   for (int i = 0; i < n; i++) {  
      cin >> a[i];  
   }  
  
   int l = 0, r = 1e9;  
   while (l < r) {  
      int m = (l + r + 1) / 2;  
      int cnt = 0, s = 0;  
      for (int i = 0; i < n; i++) {  
        s += a[i];  
        if (s >= m) {  
           cnt++;  
           s = 0;  
        }  
      }  
      if (cnt >= k) {  
        l = m;  
      } else {  
        r = m - 1;  
      }  
   }  
  
   cout << l << endl;  
  
   return 0;  
}
*/