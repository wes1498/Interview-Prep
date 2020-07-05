#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:

// Input: coins = [1, 2, 5], amount = 11
// Output: 3 
// Explanation: 11 = 5 + 5 + 1

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