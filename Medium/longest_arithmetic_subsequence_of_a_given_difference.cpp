#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

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