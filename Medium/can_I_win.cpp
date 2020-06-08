#include <iostream>
#include <cassert> 
#include <unordered_map>

using namespace std;

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