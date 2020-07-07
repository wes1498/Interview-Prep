#include <iostream>
#include <vector>

using namespace std;

// We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

// Note that our partition must use every number in A, and that scores are not necessarily integers.

// Example:
// Input: 
// A = [9,1,2,3,9]
// K = 3
// Output: 20
// Explanation: 
// The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
// We could have also partitioned A into [9, 1], [2], [3, 9], for example.
// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

double largestSumOfAverages(vector<int>& A, int K) {
    int n=A.size();
    if(n==1){return A[0];}
    A.insert(A.begin(),-1);
    vector<vector<double>>dp(K+1,vector<double>(n+1,0));
    vector<int> prefix(n+1,0);
    prefix[0]=-1;
    int count=0;
    for(int i=1; i<=n; i++) {
        count+=A[i];
        prefix[i]= count;
    }
    
    count=0;
    for(int i=1;i<=n;i++){
        count+=A[i];
        dp[1][i]=(double)count/i;
    }
    
    for(int i=2; i<=K; i++) {
        for (int j=i; j<=n; j++) {
            for(int k=i-1; k<j; k++) {
                double sum = prefix[j]-prefix[k];
                double result = (double)sum/(j-k);
                dp[i][j]=max(dp[i][j],dp[i-1][k]+result);
            }
        }
    }
    return dp[K][n];
}

int main() {
    vector<int>A;
    A.push_back(9);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(9);
    assert(largestSumOfAverages(A,3)==20);
    return 0;
}