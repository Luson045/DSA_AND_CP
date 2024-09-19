#include <bits/stdc++.h>
using namespace std;
#define FOR(n) for(int i=0;i<n;i++)
#define print(something) cout<<something<<endl
typedef long long ll;
typedef unsigned long long ull;

void all_possible_sum(int index, vector<int>sums, int count,int n, vector<int> given){
  if(index==n) return;
  if(accumulate(sums.begin(),sums.end(),0)==count){
    FOR(sums.size()){
      cout<<sums[i]<<",";
    }
    cout<<endl;
    return;
  }
  sums.push_back(given[index]);
  all_possible_sum(index+1,sums,count,n,given);
  sums.pop_back();
  all_possible_sum(index+1,sums,count,n,given);
}

//print one value
bool one_possible_sum(int index, vector<int>sums, int count,int n, vector<int> given){
  if(index==n){
    if(accumulate(sums.begin(),sums.end(),0)==count){
      FOR(sums.size()){
        cout<<sums[i]<<",";
      }
      cout<<endl;
      return true;
    }
    else return false;
  }
  sums.push_back(given[index]);
  if(one_possible_sum(index+1,sums,count,n,given)==true){
    return true;
  };
  sums.pop_back();
  if (one_possible_sum(index+1,sums,count,n,given)==true) return true;
  return false;
}


int main(){
  int n;
  cin>>n;
  vector<int>arr;
  vector<int>empty;
  for(int i=1;i<n+1;i++){
    arr.push_back(i);
  }
  print("all possible answers for the sum: ");
  all_possible_sum(0,empty,n,arr.size(),arr);
  print("one possible answer for the sum: ");
  one_possible_sum(0,empty,n,arr.size(),arr);
}