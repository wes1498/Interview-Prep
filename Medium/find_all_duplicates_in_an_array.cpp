#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int>result;
    // given the constraint that 1 ≤ a[i] ≤ n (n = size of array)
    // we can deduce that manipulating the array such that nums[i]
    // is stored in their respective index to make nums[nums[i]-1] = nums[i]
    // will be a good place to start
    for(int i = 0; i < nums.size(); i++) {
        while(nums[nums[i]-1] != nums[i]){swap(nums[nums[i]-1],nums[i]);}
    }

    for(int i = 0; i < nums.size(); i++) {
        // Now each number is in its respective position
        // if nums[nums[i]-1] == nums[i] -> if number seeking is in its position
        // AND if i+1 != nums[i] -> if the next index is a new value 
        //      0 1 ->2 3 ... i
        //      1 ->1 2 3 ... n
        if(i+1 != nums[i] && nums[nums[i]-1] == nums[i]){
            result.push_back(nums[i]);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {3,2,1,4,4};
    vector<int> res = {4};
    assert(findDuplicates(nums) == res);
    return 0;
}