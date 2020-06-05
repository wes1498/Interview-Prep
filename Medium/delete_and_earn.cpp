#include <iostream>
#include <vector>

using namespace std;

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