#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    
    for(int i=0; i<m; i++){
        i == 0 ? dp[i][0] = mat[i][0] : dp[i][0] = dp[i-1][0] + mat[i][0];
    }
    for(int i=0; i<n; i++) {
        i == 0 ? dp[0][i] = mat[0][i] : dp[0][i] = dp[0][i-1] + mat[0][i];
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + mat[i][j] - dp[i-1][j-1];
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int r = min(m - 1, i + k);
            int c = min(n -1 , j + k);
            mat[i][j] = dp[r][c];
            if(i-k > 0){
                mat[i][j] -= dp[i-k-1][c];
            }
            if(j-k > 0){
                mat[i][j] -= dp[r][j-k-1];
            }
            if(i-k > 0 && j-k > 0){
                mat[i][j] += dp[i-k-1][j-k-1];
            }
        }
    }
    return mat;
}

int main() {

    vector<vector<int>> mat;
    
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
    mat.push_back(temp);
    temp.clear();

    temp.push_back(4);
    temp.push_back(5);
    temp.push_back(6);
    mat.push_back(temp);
    temp.clear();

    temp.push_back(7);
    temp.push_back(8);
    temp.push_back(9);
    mat.push_back(temp);
    temp.clear();

    vector<vector<int>> result;

    temp.push_back(12);
    temp.push_back(21);
    temp.push_back(16);
    result.push_back(temp);
    temp.clear();
    temp.push_back(27);
    temp.push_back(45);
    temp.push_back(33);
    result.push_back(temp);
    temp.clear();
    temp.push_back(24);
    temp.push_back(39);
    temp.push_back(28);
    result.push_back(temp);
    assert(matrixBlockSum(mat,1)==result);
    return 0;
}