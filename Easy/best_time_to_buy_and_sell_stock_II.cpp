#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==0) {return 0;}

    vector<int> buy(n), sell(n);
    buy[0]=-prices[0];
    sell[0]=0;

    for(int i=1; i<n; i++) {
        buy[i]=max(buy[i-1],sell[i-1]-prices[i]);
        sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
    }
    return sell[n-1];
}

int main() {
    //[7,1,5,3,6,4]

    vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    assert(maxProfit(prices)==7);
    return 0;
}