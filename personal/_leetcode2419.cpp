#include <bits/stdc++.h>
using namespace std;

/*
class Classname{
  public:
  //static int static_variable
  int i;
  float f;
  string s;
  
  private:
  //static int static_function(int a,int b);
  void function1(int arg1, int arg2);
  void function2(int arg1, int arg2){
  //body
  }
};
*/

//vector<int> arr(n);
//vector<char> arr(n);
//vector<float> arr(n);
//vector<ll> arr(n);



int main(){
  vector<int> a{1,2,11,12,13,43,14,43};
  cout<<*max_element(a.begin(), a.end());
  return 0;
}