#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

int minFallingPathSum(vector<vector<int>>& A) {
    int row = A.size();
    int col = A[0].size();
    // dp[i][j] stores the minimum falling path sum up to A[i][j]
    vector<vector<int>> dp(row,vector<int>(col,0));
    
    for(int i=0; i<col; i++) {
        dp[0][i] = A[0][i];
    }
    
    for(int i=1; i<row; i++) {
        for(int j=0; j<col; j++) {
            if (j==0) {
                dp[i][j] = A[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
            } else if (0<j && j<col-1) {
                dp[i][j] = A[i][j]+min(dp[i-1][j],min(dp[i-1][j+1],dp[i-1][j-1])); 
            } else if(j==col-1){
                dp[i][j] = A[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            } 
        }
    }
    return *min_element(dp[row-1].begin(),dp[row-1].end()); 
}

int main() {
    //[[1,2,3],[4,5,6],[7,8,9]]
    vector<vector<int>> A;
    
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    A.push_back(temp);
    temp.clear();

    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(6);
    A.push_back(temp);
    temp.clear();

    temp.push_back(7);
    temp.push_back(8);
    temp.push_back(9);
    A.push_back(temp);
    temp.clear();

    assert(minFallingPathSum(A) == 12);

    return 0;
}