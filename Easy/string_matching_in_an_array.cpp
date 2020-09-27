#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

bool isSubstring(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    if(n > m){return false;}
    
    for(int i = 0; i <= m-n; i++) {
        int j;
        for(j=0; j < n; j++) {
            if(s2[i+j] != s1[j]){break;}
        }
        if(j == n){return true;}
    }
    return false;
}
vector<string> stringMatching(vector<string>& words) {
    vector<string> res;
    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words.size(); j++) {
            if(j != i && isSubstring(words[i],words[j])){
                res.push_back(words[i]);
                break;
            }
        }
    }
    return res;
}
int main() {
    vector<string> words = {"leetcoder","leetcode","od","hamlet","am"};
    vector<string> ret = {"leetcode","od","am"};
    asert(stringMatching(words) == ret);
    return 0;
}