#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();
    vector<int>res(n,0);
    
    res[0] = nums[0];
    
    for(int i=1; i<n; i++) {
        res[i] = nums[i] + res[i-1];
    }
    
    return res;
}

int main() {
    vector<int> nums{1,2,3,4};
    vector<int> res{1,3,6,10};
    assert(runningSum(nums)==res);
    
    return 0;
}