#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
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