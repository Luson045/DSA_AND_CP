/*
question:
given expression a string containing operators and operands
example-
  expression= 2-1-1
  expression=2*3-4*5

we have to find all the way to evaluate this

Approach-
we are taking 1 operator and separating each side of the operator and solving each sides

divide and conquer with recursion [memoization if needed for tle ]

what we'll do
we'll run a recursion till the last element to find all the possible ansers and store them in an empty array


1) whenever we get a sign, we split the string into two parts and return the function call again with the separated parts

2) if the argument to the function doesn't have an operator, we'll return the argument

//basically we're using recursion

cpp code below 👇  
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> waystocompute(string s){
  //create a new empty array
  vector<ll> answer;
  for(int i=0;i<s.length();i++){//to get al possible answers
    char c=s[i];
    if(c=='-'||c=='+'||c=='*'){
      vector<ll> left = waystocompute(s.substr(0,i-0));//left portion
      vector<ll> right =waystocompute(s.substr(i+1,s.length()-i+1));//right
      for(int a: left){
        for(int b:right){
          if(c=='+'){
            answer.push_back(a+b);
          }else if(c=='-'){
            answer.push_back(a-b);
          }else if(c=='*'){
            answer.push_back(a*b);
          }
        } 
      }
    }
  }
  if(answer.size()==0)//for operands
    answer.push_back(stoi(s));
  return answer;
}

int main(){
  vector<ll> solution= waystocompute("2*3-4*5");
  for(ll i:solution){
    cout<<i<<endl;
  }
  return 0;
}


