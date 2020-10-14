#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

bool search(vector<int>& nums, int target) {
    if(nums.size()==1){return nums[0] == target;}
    int left = 0;
    int right = nums.size()-1;
    
    while(left <= right) {
        if(nums[left] == nums[right]){
            // dont know where the pivot starts, so iterate each value until you hit the tartget 
            while(left <= right){
                if(nums[left++] == target){return true;}
            }
            return false;
        }
        int mid = (left + right) / 2;
        if(nums[mid] == target){return true;}
        // [1,2,3,4,5,6]
        if(nums[left] < nums[right]) {
            if(target > nums[mid]){left = mid + 1;}
            else {right = mid - 1;}
        } else { 
            // if nums[left] > nums[right]
            // [4,5,6,1,2,3]
            if(nums[mid] >= nums[left]){
                // [4,5,6,1,2,3]
                if(target < nums[mid] && target >= nums[left]){
                    right = mid - 1;
                } else {left = mid + 1;}
            } else {
                // nums[left] > nums[right]
                // [6,1,2,3,4,5]
                if(target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
    }
    return false; 
}

int main() {
    vector<int>nums = {3,4,5,1,2,3};
    assert(search(nums,3) == true);
    return 0;
}