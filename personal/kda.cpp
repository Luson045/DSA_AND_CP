#include <iostream>
#include <vector>
using namespace std;
//FOR SUM
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0,max_sum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            max_sum=max(max_sum,sum);
            if(sum<0)
                sum=0;
        }
        return max_sum;
    }
};

