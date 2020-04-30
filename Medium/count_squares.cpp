#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int col = matrix.size();
    int row = matrix[0].size();
    //dp[i][j] will hold the number of square submatricies that it can
    // store. this depends on the MIN (dp[i-1][j-1], dp[i-1][j], dp[i][j-1])
    vector<vector<int>> dp(col,vector<int>(row,0));
    int count=0;
    
    for(int i=0; i<col; i++){
        dp[i][0] = matrix[i][0];
    }
    for(int i=0; i<row; i++){
        dp[0][i] = matrix[0][i];
    }

    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            if (matrix[i][j]) {
                if(i!=0 && j!=0) {
                    dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
                }
                count+=dp[i][j];
            }
            
        }
    }
    return count;
}

int main() {
    vector<vector<int>> matrix;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    matrix.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    matrix.push_back(temp);
    temp.clear();

    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    matrix.push_back(temp);
    temp.clear();

    assert(countSquares(matrix) == 15);
    return 0;
}