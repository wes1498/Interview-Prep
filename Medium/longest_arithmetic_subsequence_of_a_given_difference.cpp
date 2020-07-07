#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Given an integer array arr and an integer difference, return the length of the longest subsequence in arr which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals difference.

 

// Example 1:

// Input: arr = [1,2,3,4], difference = 1
// Output: 4
// Explanation: The longest arithmetic subsequence is [1,2,3,4].
int longestSubsequence(vector<int>& arr, int difference) {
    int n=arr.size();
    if(n==1){return 1;}
    int _max=0;
    unordered_map<int,int> dp;
    dp[arr[n-1]]=1;
    for(int i=n-2; i>=0; i--) {
        if(dp.find(arr[i]+difference) != dp.end()) {
            dp[arr[i]]=dp[arr[i]+difference]+1;
        }else {
            dp[arr[i]]=1;
        }
        _max=max(_max,dp[arr[i]]);
    }
    return _max;
}

int main() {

    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4); 

    assert(longestSubsequence(arr, 1));

    return 0;
}