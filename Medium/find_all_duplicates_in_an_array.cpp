#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for(int i = 0; i < nums.size(); i++) {
        while(nums[nums[i] - 1] != nums[i]){swap(nums[nums[i] - 1], nums[i]);}
    }

    for(vector<int>::iterator it = nums.begin(); it!=nums.end(); ++it){
        if(std::distance(nums.begin(), it)+1 != *it && nums[*it - 1] == *it)
            result.push_back(*it);
    }

    return result;
}

int main() {
    vector<int> nums = {3,2,1,4,4};
    vector<int> res = {4};
    assert(findDuplicates(nums) = res);
    return 0;
}