#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

// You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

// Return the maximum profit you can make.

// Example 1:
// Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// Buying at prices[0] = 1
// Selling at prices[3] = 8
// Buying at prices[4] = 4
// Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if(n==0) {return 0;}
    
    vector<int> buy(n), sell(n);
    buy[0]=-prices[0];
    sell[0]=0;
    
    for(int i=1; i<n; i++) {
        buy[i]=max(buy[i-1],sell[i-1]-prices[i]);
        sell[i]=max(sell[i-1],buy[i-1]+prices[i]-fee);
    }
    return sell[n-1];
}

int main() {
    //[1, 3, 2, 8, 4, 9]
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(8);
    prices.push_back(4);
    prices.push_back(9);

    assert(maxProfit(prices,2)==8);
    return 0;
}