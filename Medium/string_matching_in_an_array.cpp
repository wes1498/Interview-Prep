#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

int minSteps(string s, string t) {
    vector<int> mp(26,0);
    int counter = 0;
    for(auto ch : s) {
        mp[ch - 'a']++;
        counter++;
    }
    for(auto ch : t) {
        if(mp[ch - 'a'] > 0){
            mp[ch - 'a']--;
            counter--;
        }
    }
    
    return counter;
}

int main() {
    assert(minSteps("leetcode","practice") == 5);
    return 0;
}