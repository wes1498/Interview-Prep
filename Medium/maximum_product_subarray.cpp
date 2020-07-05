#include <iostream>
#include <vector>

using namespace std;

// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {return 0;}

        vector<int> maxP(n,INT_MIN),minP(n,INT_MIN);
        maxP[0]=nums[0];
        minP[0]=nums[0];
        int max_prod = nums[0];

        for(int i=1; i<n; i++) {
            maxP[i]=max(nums[i],max(maxP[i-1]*nums[i],minP[i-1]*nums[i]));
            minP[i]=min(nums[i],min(maxP[i-1]*nums[i],minP[i-1]*nums[i]));
            max_prod=max(max_prod,maxP[i]);
        }
        return max_prod;
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,-2,4};
    assert(s.maxProduct(nums) == 6);
    return 0;
}