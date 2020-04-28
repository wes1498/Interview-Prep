#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

bool stoneGame(vector<int>& piles) {
    int length = piles.size();
    
    // dp[i][j] contains the optimal total stones Alex has with piles{i , j}
    vector<vector<int>> dp(length,vector<int>(length,0));
    
    // where i==j, dp[i][j] will just be Alex's total stones as both piles the             // same size
    for(int i=0; i<length; i++) {
        dp[i][i]=piles[i];
    }
    
    for(int i=0; i<length; i++) {
        for(int j=i; j<length; j++) {
            if (i!=j){
                dp[i][j] = max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
            }
            
        }
    }
    return dp[0][length-1]>0;
}

int main() {
    vector<int> piles;
    piles.push_back(5);
    piles.push_back(3);
    piles.push_back(4);
    piles.push_back(5);
    if(stoneGame(piles) == true){
        printf("Alex wins!\n");
    }
    assert(stoneGame(piles) == true);
    return 0;
}