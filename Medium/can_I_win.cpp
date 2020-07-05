#include <iostream>
#include <cassert> 
#include <unordered_map>

using namespace std;

// In the "100 game," two players take turns adding, to a running total, any integer from 1..10. The player who first causes the running total to reach or exceed 100 wins.

// What if we change the game so that players cannot re-use integers?

// For example, two players might take turns drawing from a common pool of numbers of 1..15 without replacement until they reach a total >= 100.

// Given an integer maxChoosableInteger and another integer desiredTotal, determine if the first player to move can force a win, assuming both players play optimally.

// You can always assume that maxChoosableInteger will not be larger than 20 and desiredTotal will not be larger than 300.
bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(desiredTotal<=1){return true;}
    //if sum(maxChoosableInteger)< desiredTotal, then return false
    if(((maxChoosableInteger*(maxChoosableInteger+1))/2) < desiredTotal){return false;}
    
    // dp[i]=  1 if P1 can win with i choosable Ints, 0 otherwise
    unordered_map<int, bool>dp;
    
    function<bool(int,int)>canIWinUtil = [&](int total, int state) {
        if(total<=0){return false;}
        if (dp.count(state)) return dp[state];
    
        for(int i=1; i<=maxChoosableInteger; i++) {
            if(state & (1<<i)){continue;}
            if(!canIWinUtil(total - i, state | (1<<i))){return true;}
        }
        return dp[state]=false;
    };
    
    return canIWinUtil(desiredTotal,0);
}

int main() {
    assert(canIWin(10,11)==false);
    return 0;
}