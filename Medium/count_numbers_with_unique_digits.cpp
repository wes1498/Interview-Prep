#include <iostream>
#include <vector>
#include <vector>

using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if(n == 0){return 1;}
    
    vector<int>dp(n+1,0);
    dp[0]=1;
    
    for(int i=1; i<=n; i++) {
        dp[i]=9;
        for(int j=0; j<i-1; j++) {
            dp[i]*=(9-j);
            
        }
        dp[i]+=dp[i-1];
    }

    return dp[n];
}

int main() {
    assert(countNumbersWithUniqueDigits(3)==739);
    return 0;
}