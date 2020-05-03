#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

vector<int> dp;
int coinChangeUtil(int i) {
    if (i<0){
        return 100000;
    } else if (i==0) {
        return 0;
    } else 
        return dp[i];
}

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    dp = vector<int>(amount+1, 0);
    for(int i=0; i<=amount; i++) {
        int min = 100000;
        for(int j=0; j<coins.size(); j++) {
            int change = coinChangeUtil(i-coins[j])+1;
            if (change < min) {
                min = change;
            }
        }
        dp[i] = min;
    }
    return dp[amount] != 100000 ? dp[amount]  : -1;
}

int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);

    assert(coinChange(coins,11) == 3);
    return 0;
}