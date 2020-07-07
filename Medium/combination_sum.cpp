#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

// The same repeated number may be chosen from candidates unlimited number of times.

// Note:

// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
    Solution() = default;
    void combinationSumUtil(vector<int>& candidates, int target, int start) {
        // solution found, store the array into result
        if(target == 0) {result.push_back(temp);return;}
        // no solution found, do nothing
        if(target < 0) {return;}
        for(int i=start; i<candidates.size(); i++) {
            temp.push_back(candidates[i]);
            combinationSumUtil(candidates, target-candidates[i],i);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0 || target == 0){return result;}
        combinationSumUtil(candidates, target, 0);
        return result;
    }
};

int main() {
    Solution s;
    vector<int> candidates{2,3,6,7};
    vector<int> temp{7};
    vector<int> temp2{2,2,3};
    vector<vector<int>> result;
    result.push_back(temp);
    result.push_back(temp2);
    assert(s.combinationSum(candidates,7).size() == result.size());
    return 0;
}