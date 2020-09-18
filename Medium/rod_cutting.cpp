#include <iostream>
#include <vector>

using namespace std;


int rodCutting(int n, std::vector<int> v) {
    // T(n) be the best possible price value for rod size n
    // So you gotta compare the best possible combination of rod cuts
    // at each T(i) to see if you need to update your value
    // bounded to O(n^2) time 
    // recurrence: T(n) = max (v[i] + T(n-i)) {0<=i<n}
    
    vector<int> dp(n+1,0);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int maxx = INT_MIN;
        for(int j = 0; j <= i; j++) {
            maxx = max(maxx, v[j] + dp[i-j]);
        }
        dp[i] = maxx;
    }
    return dp[n];  
}