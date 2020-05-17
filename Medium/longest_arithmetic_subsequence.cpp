#include <iostream>
#include <vector>
#include <cassert>
#include <map> 

using namespace std;

int longestArithSeqLength(vector<int>& A) {
    int n=A.size();
    if(n==1){return 1;}
    
    map<int,map<int,int>> dp;
    // base case: LAS = 2 
    dp[1][A[1]-A[0]]=2;
    int maxx=INT_MIN;
    
    for(int i=2;i<n;i++){
        for(int j=i-1;j>=0;j--){
            dp[j][A[i]-A[j]]==0 ? dp[i][A[i]-A[j]]=max(dp[i][A[i]-A[j]],2) : dp[i][A[i]-A[j]]=max(dp[i][A[i]-A[j]],1+dp[j][A[i]-A[j]]);
            maxx=max(maxx,dp[i][A[i]-A[j]]);
        }
    }
    return maxx;
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