#include<iostream>
#include <vector>
#include <cassert> 

using namespace std;

class NumArray {
    public:
        vector<int> nums;
        NumArray(vector<int>& nums) {
            this->nums = vector<int>(nums.size()+1, 0);
            for(int i=0; i<nums.size(); i++){
                this->nums[i+1] = this->nums[i] + nums[i];
            }
        }
        
        int sumRange(int i, int j) {
            return this->nums[j+1] - this->nums[i];
        }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    assert(obj->sumRange(0, 2)==1);
    assert(obj->sumRange(2, 5)==-1);
    assert(obj->sumRange(0, 5)==-3);
    return 0;
}