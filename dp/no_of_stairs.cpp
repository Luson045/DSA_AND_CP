//problems
//CATEGORY- 1D
//given n, i am at 0,
//at each step i can take 1 or 2 steps
//find the no. of distinct ways to reach n from 0

/*
HOW TO UNDERSTAND IT IS DP-
  1)COUNT THE TOTAL NO. OF WAYS
  2)MIN/MAX OUTPUT OUT OF MULTIPLE WAYS

  ====(RECURSION-TRY ALL POSSIBLE WAYS)======

  **IF RECURSION -----> THEN MAYBE DP**

  SHORTCUT--
  1)TRY TO REPRESENT THE PROBLEM IN TERMS OF INDEX;
  2)DO ALL POSSIBLE STUFFS ON THAT INDEX ACC TO THE     PROBLEM STATEMENT;
  3)IF (COUNT ALL WAYS) THEN (SUM UP ALL STUFFS)
  4)IF (FIND MIN/MAX) THEN (FIND MAX/MIN)
*/


/*
INTUITION FOR THIS PROBLEM-

  TREAT THE STAIRS AS INDEX, i.e.-
  0,1,2,3,4,.........,n stairs

  RECURSION-
  f(n) return no. of ways(0->n)

  IN TERMS OF INDEX-
  f(index) return no. of indices

  DO ALL STUFFS-
    jump 1----> f(index-1);
    jump 2----> f(index-2);
    return f(index-1)+f(index-2);

    edge cases-
    index==0,index==1 return 1;
*/

//CODE
#include <bits/stdc++.h>
using namespace std;
class Solution {
  
public:
    Solution():dp(46,-1){};
    int climbStairs(int n) {
        if(n==0||n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=climbStairs(n-1)+climbStairs(n-2);
    }
private:
    vector<int> dp;
};