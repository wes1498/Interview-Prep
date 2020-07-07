#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// Each number in candidates may only be used once in the combination.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
    void backtrack(vector<int>& candidates, int target, int start) {
        if(target == 0 && find(result.begin(),result.end(), temp) == result.end()) {
            result.push_back(temp);
            return;
        }
        if(target < 0){return;}
        for(int i=start; i<candidates.size(); i++) {
            temp.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0 || target == 0) {return result;}
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> candidates{10,1,2,7,6,1,5};
    assert(s.combinationSum2(candidates,8).size() == 4);
    return 0;
}