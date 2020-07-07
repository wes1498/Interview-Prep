#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

int uniquePaths(int m, int n) {
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(auto i=0;i<m;i++){
        dp[0][i]=1;
    }
    for(auto i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(auto i=1; i<n;i++){
        for(auto j=1; j<m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

int main() {
    assert(uniquePaths(7,3)==28);
    assert(uniquePaths(3,2)==3);
    return 0;
}