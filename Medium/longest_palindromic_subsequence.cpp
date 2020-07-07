#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

// Example 1:
// Input:

// "bbbab"
// Output:
// 4
// One possible longest palindromic subsequence is "bbbb".

int longestPalindromeSubseq(string s) {
    if(s.size()==0){return 0;}
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    
    for(int i=0; i<n; i++){
        dp[i][i]=1;
    }
    for(int i=0; i<n-1; i++){
        if(s[i]==s[i+1])
            dp[i][i+1]=2;
        else
            dp[i][i+1]=1;
    }
    for(int j=3; j<=n; j++){
        for(int i=0; i<=n-j; i++){
            dp[i][i+j-1]=max(dp[i+1][i+j-1],dp[i][i+j-2]);
            if(s[i]==s[i+j-1])
                dp[i][i+j-1]=max(dp[i][i+j-1],dp[i+1][i+j-2]+2);
        }
    }
    return dp[0][n-1];
}

int main() {
    assert(longestPalindromeSubseq("bbbab")==4);
    return 0;
}