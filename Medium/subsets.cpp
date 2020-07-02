#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

void subsetsUtil(int x, vector<vector<int>>& result) {
    vector<vector<int>> copy;
    for(int i=0; i<result.size(); i++) {
        vector<int>temp(result[i]);
        temp.push_back(x);
        copy.push_back(temp);
    }
    result.insert(result.end(),copy.begin(),copy.end());
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size() == 0) {return result;}
    
    result.push_back(vector<int>(0));
    for(int i=0; i<nums.size(); i++) {
        subsetsUtil(nums[i], result);
    }
    return result;
}

int main() {
    vector<int> nums{1,2,3};
    vector<vector<int>> result{{},{1},{2},{3},{1,2,3},{1,2},{1,3},{2,3}};
    assert(subsets(nums).size() == result.size());
    return 0;
}