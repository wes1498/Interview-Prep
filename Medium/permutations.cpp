#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
    void backtrack(vector<int>& nums, int start) {
        if(temp.size() == nums.size() && find(result.begin(), result.end(), temp) == result.end()){
            result.push_back(temp);
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()){continue;}
            temp.push_back(nums[i]);
            backtrack(nums,i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 0){return result;}
        result.push_back(nums);
        backtrack(nums, 0);
        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums{1,2,3};
    assert(s.permute(nums).size() == 6);
    
    return 0;
}