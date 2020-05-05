#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

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