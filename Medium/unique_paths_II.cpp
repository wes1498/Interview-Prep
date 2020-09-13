#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// Now consider if some obstacles are added to the grids. How many unique paths would there be?



// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Note: m and n will be at most 100.

// Example 1:

// Input:
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// Output: 2
// Explanation:
// There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row=obstacleGrid.size();
    int col=obstacleGrid[0].size();
    
    if(obstacleGrid[0][0]==1 || obstacleGrid[row-1][col-1]==1){return 0;}
    
    vector<vector<int>>dp(row,vector<int>(col,0));
    dp[0][0]=1;
    
    for(auto i=1;i<col;i++){
        if(obstacleGrid[0][i]!=1 && obstacleGrid[0][i-1]!=1)
            dp[0][i]=dp[0][i-1];
    }
    for(auto i=1;i<row;i++){
        if(obstacleGrid[i][0]!=1 && obstacleGrid[i-1][0]!=1)
            dp[i][0]=dp[i-1][0];
    }
    for(auto i=1; i<row;i++){
        for(auto j=1; j<col;j++){
            if(obstacleGrid[i][j]!=1)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[row-1][col-1];
}

int main() {
//   [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
//   ]
    vector<vector<int>> obstacleGrid;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    obstacleGrid.push_back(temp);
    temp.clear();

    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(0);
    obstacleGrid.push_back(temp);
    temp.clear();

    temp.push_back(0);
    temp.push_back(0);
    temp.push_back(0);
    obstacleGrid.push_back(temp);
    
    assert(uniquePathsWithObstacles(obstacleGrid)==2);
    return 0;
}