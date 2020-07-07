#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

// Given a square array of integers A, we want the minimum sum of a falling path through A.

// A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

// Example 1:

// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: 12
// Explanation: 
// The possible falling paths are:
// [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
// [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
// [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
// The falling path with the smallest sum is [1,4,7], so the answer is 12.

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