#include<iostream>
#include <vector>         // std::vector
using namespace std;


void rotate(vector<int>& nums, int k) {
    vector<int> ret;
    int count=0;
    while (k>0) {
        for (int i=nums.size()-1; i>0; i--) {
            if (count <= k-1) {
                ret.push_back(nums[i]);
            }
            nums[i] = nums[i-1];
            count++;
        }
        if (nums.size() > 1) {
            nums.erase(nums.begin()); 
        }
            
        k--;
    }

    // nums.erase(nums.begin());
    for (int i=0; i<ret.size(); i++) {
        nums.insert(nums.begin(), ret[i]);
    }
    cout << "the effective rotation is:" << '\n';
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << '\n';
    }
        
}

int main () {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    int k = 3;
    rotate(nums, k);
}