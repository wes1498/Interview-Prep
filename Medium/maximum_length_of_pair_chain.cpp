#include <iostream>
#include <vector>
#include <cassert> 

using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    int n=pairs.size();
    if (n==1){return 1;}
    
    std::sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
    return a[1] < b[1];   
    });
    vector<int>dp(n,0);
    dp[0]=1;
    int prev=pairs[0][1];
    for(int i=1; i<n; i++) {
        if(prev<pairs[i][0]){
            dp[i]=dp[i-1]+1;
            prev=pairs[i][1];
        }else{
            dp[i]=dp[i-1];
        }      
    }
    return dp[n-1];
}

int main() {
    
    vector<vector<int>> pairs;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(2);
    pairs.push_back(temp);
    temp.clear();
    temp.push_back(2);
    temp.push_back(3);
    pairs.push_back(temp);
    temp.clear();
    temp.push_back(3);
    temp.push_back(4);
    pairs.push_back(temp);
    temp.clear();

    assert(findLongestChain(pairs)==2);
    return 0;
}