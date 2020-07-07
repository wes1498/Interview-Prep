#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;


// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

class Solution {

private:
    vector<vector<int>> powerset;
    vector<int> subset;
public:
    Solution() = default;

    void backtrack(vector<int>& nums, int start) {
        powerset.push_back(subset);
        for(int i=start; i<nums.size(); i++) {
            // if you encounter a duplicate when 
            if(i > start && nums[i] == nums[i-1]){continue;}
            subset.push_back(nums[i]);
            backtrack(nums, i+1);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums,0);
        return powerset;
    }
};

int main() {
    Solution s;
    vector<int> sol{1,2,2};
    assert(s.subsetsWithDup(sol).size() == 6);
    return 0;
}