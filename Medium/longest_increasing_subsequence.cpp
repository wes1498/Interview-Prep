#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

int longestArithSeqLength(vector<int>& A) {
    int n=A.size();
    if(n==1){return 1;}
    vector<int>dp(n,0);
    
    for(int i=0;i<n;i++) {
        dp[i]=1;
        for(int j=0;j<i;j++) {
            if(A[i] > A[j] && dp[j]+1>dp[i]) {
                dp[i]=dp[j]+1;
            }
        }
    }
    return dp[n-1];
}

int main() {
    vector<int> A;
    A.push_back(3);
    A.push_back(6);
    A.push_back(9);
    A.push_back(12);
    assert(longestArithSeqLength(A)==4);
    return 0;
}