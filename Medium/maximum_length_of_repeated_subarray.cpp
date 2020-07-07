#include <iostream>
#include <vector>

using namespace std;

// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation: 
// The repeated subarray with maximum length is [3, 2, 1].

int findLength(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int m = B.size();
    
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = B[0] == A[0] ? 1 : 0;
    
    for(int i=1; i<n; i++) {
        dp[0][i] = B[0] == A[i] ? 1 : 0;
    }
    for(int i=1; i<m; i++) {
        dp[i][0] = B[i] == A[0] ? 1 : 0;
    }
    int maxx=0;
    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            dp[i][j] = B[i] == A[j] ? dp[i-1][j-1]+1 : 0;
            maxx=max(dp[i][j],maxx);
        }
    }
    return maxx;
}

int main() {
    vector<int> A;

    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(2);
    A.push_back(1);

    vector<int> B;

    B.push_back(3);
    B.push_back(2);
    B.push_back(1);
    B.push_back(4);
    B.push_back(7);

    assert(findLength(A,B)==3);

    return 0;
}