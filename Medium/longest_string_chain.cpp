#include <iostream>
#include <vector>
#include <map>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

int longestStrChain(vector<string>& words) {
    int n=words.size();
    if(n==1){return 1;}
    
    sort(words.begin(), words.begin()+n,[](string& first, string& second){return first.size() < second.size();});

    map<string,int>dp;
    int res=0;
    for(auto s : words) {
        for (int j=0; j<s.size(); j++) {
            dp[s]=max(dp[s.substr(0,j)+s.substr(j+1)]+1, dp[s]);
        }
        res = max(res, dp[s]);
    }
    return res;
}

int main() {
    //["a","b","ba","bca","bda","bdca"]
    vector<string> words;

    words.push_back("a");
    words.push_back("b");
    words.push_back("ba");
    words.push_back("bca");
    words.push_back("bda");
    words.push_back("bdca");

    assert(longestStrChain(words)==4);

    return 0;
}