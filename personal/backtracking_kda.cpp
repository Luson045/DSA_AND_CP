#include <iostream>
#include <vector>
using namespace std;
//MAX PRODUCT
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1,max_prod=INT_MIN;
        for(int i=0;i<nums.size();i++){
            prod *= nums[i];
            max_prod=max(max_prod,prod);
            if(prod==0)
                prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){//backtracking
            prod *= nums[i];
            max_prod=max(max_prod,prod);
            if(prod==0)
                prod=1;
        }
        return max_prod;
    }
};