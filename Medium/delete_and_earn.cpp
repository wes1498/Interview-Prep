#include <iostream>
#include <vector>

using namespace std;


// Given an array nums of integers, you can perform operations on the array.

// In each operation, you pick any nums[i] and delete it to earn nums[i] points. After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.

// You start with 0 points. Return the maximum number of points you can earn by applying such operations.

// Example 1:

// Input: nums = [3, 4, 2]
// Output: 6
// Explanation: 
// Delete 4 to earn 4 points, consequently 3 is also deleted.
// Then, delete 2 to earn 2 points. 6 total points are earned.

int deleteAndEarn(vector<int>& nums) {
    vector<int> dp(10001,0);
    
    for(int i=0; i<nums.size(); i++) {
        dp[nums[i]]+=nums[i];
    }
    
    for(int i=2; i<10001; i++) {
        dp[i]=max(dp[i]+dp[i-2],dp[i-1]);
    }
    
    return dp[10000];
}

int main() {
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(2);
    
    assert(deleteAndEarn(nums));
    return 0;
}