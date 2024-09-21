#include <bits/stdc++.h>
using namespace std;

//for more info visit cpprefeerence....

vector<int> arr{10,20,30,40,50};

int main(){
  int ele;
  cin>>ele;
  vector<int>::iterator iter = find(arr.begin(),arr.end(),ele);
  if(iter!=arr.end()){
        cout << "Element " << ele << " found at position : ";
        int index= iter - arr.begin();
        cout<<index<<endl;
  }else{
    cout<<"element: "<<ele<<"does not exits in the arr"<<endl;
  }
  return 0;
}