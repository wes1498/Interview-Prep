#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// Example:

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
    // Only difference is that now you have to track whether the repeated number is used or not
    // keep a used(n, flase) vector that will track whether you have used the number in your 
    // next permutation or not.
    // continue to next number if:
    //    1. You've used nums[i] already
    //
    //    2. nums[i] == nums[i-1] AND you haven't checked out nums[i-1] yet
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if(temp.size() == nums.size()){
            result.push_back(temp);
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i] || i>0 && nums[i-1] == nums[i] && !used[i-1]){continue;}
            temp.push_back(nums[i]);
            used[i]=true;
            backtrack(nums,used);
            used[i]=false;
            temp.pop_back();
            }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {return result;}
        vector<bool>used(n,false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,1,2};
    assert(s.permuteUnique(nums).size() == 3);
    return 0;
}