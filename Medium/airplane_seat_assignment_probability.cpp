#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

// n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:

// Take their own seat if it is still available, 
// Pick other seats randomly when they find their seat occupied 
// What is the probability that the n-th person can get his own seat?
double nthPersonGetsNthSeat(int n) {
    // always a 50% probability for the nth person to pick their seat?
    if (n==1){return 1.0f;}
    if (n==2){return 0.5f;}
    vector<double> dp(n,0);
    dp[0]=0;
    dp[1]=1.0f;
    dp[2]=0.5f;
    for(int i=3; i<n; i++) {
        float first = 1/float(n);
        dp[i] = first + (float(dp[i-1]) * (float(n-2)/float(n)));
    }
    return dp[n-1];
}

int main() {
    // all have 50% probability 
    assert(nthPersonGetsNthSeat(1) == 1);
    assert(nthPersonGetsNthSeat(4) == 0.5f);
    assert(nthPersonGetsNthSeat(9) == 0.5f);
    assert(nthPersonGetsNthSeat(1000) == 0.5f);
    return 0;
}