#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    if( row == 0 || col == 0){return 0;}
    
    vector<vector<int>> dp(row,vector<int>(col,0));
    
    dp[0][0]=grid[0][0];
    for(int i=1; i<row; i++){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int i=1; i<col; i++){
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
        }
    }
    return dp[row-1][col-1];
}

int main() {
    //    [
    //   [1,3,1],
    //   [1,5,1],
    //   [4,2,1]
    //  ]
    vector<vector<int>> grid;

    vector<int> temp;
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(1);
    grid.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(5);
    temp.push_back(1);
    grid.push_back(temp);
    temp.clear();

    temp.push_back(4);
    temp.push_back(2);
    temp.push_back(1);
    grid.push_back(temp);

    assert(minPathSum(grid)==7);

    return 0;
}