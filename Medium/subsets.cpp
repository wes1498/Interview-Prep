#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// void subsetsUtil(int x, vector<vector<int>>& result) {
//     vector<vector<int>> copy;
//     for(int i=0; i<result.size(); i++) {
//         vector<int>temp(result[i]);
//         temp.push_back(x);
//         copy.push_back(temp);
//     }
//     result.insert(result.end(),copy.begin(),copy.end());
// }

// vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> result;
//     if(nums.size() == 0) {return result;}
    
//     result.push_back(vector<int>(0));
//     for(int i=0; i<nums.size(); i++) {
//         subsetsUtil(nums[i], result);
//     }
//     return result;
// }
vector<vector<int>> result;
vector<int> subset;
void backtrack(vector<int>& nums, int start) {
    result.push_back(subset);
    for(int i = start; i<nums.size(); i++) {
        subset.push_back(nums[i]);
        backtrack(nums, i+1);
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    backtrack(nums, 0);
    return result;
}

int main() {
    vector<int> nums{1,2,3};
    vector<vector<int>> result{{},{1},{2},{3},{1,2,3},{1,2},{1,3},{2,3}};
    assert(subsets(nums).size() == result.size());
    return 0;
}