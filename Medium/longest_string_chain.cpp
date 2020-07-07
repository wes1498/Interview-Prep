#include <iostream>
#include <vector>
#include <map>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// Given a list of words, each word consists of English lowercase letters.

// Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2.  For example, "abc" is a predecessor of "abac".

// A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

// Return the longest possible length of a word chain with words chosen from the given list of words.

 

// Example 1:

// Input: ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: one of the longest word chain is "a","ba","bda","bdca".

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