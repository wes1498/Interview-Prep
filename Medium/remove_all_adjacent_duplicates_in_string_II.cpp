#include <iostream>
#include <unordered_map>
#include <cassert> 

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

class Solution {
public:
    bool noDuplicates(string s, int k) {
        unordered_map<char, int> table;
        for(auto ch : s) {
            table[ch]++;
        }
        for(const auto &p : table){
            if( p.second >= k) {
                return false;
            }
        }
        return true;
    }
    string removeDuplicatesUtil(string s, int k, int begin, int counter) {
        //cout<<s<<endl;
        if(noDuplicates(s,k)){
           return s; 
        }
        
        for(int i = begin+1; i < s.size(); i++) {
            if(s[i] == s[begin]) {
                counter++;
                if(counter == k) {
                    return removeDuplicatesUtil(s.erase(begin,k), k,0,1);
                }
            } else {
                begin = i;
                counter = 1;
            }
        }
        return removeDuplicatesUtil(s.erase(begin,k), k,0,1);
    }
    string removeDuplicates(string s, int k) {
        return removeDuplicatesUtil(s, k, 0, 1);
    }
};

int main() {
    Solution s;
    assert(s.removeDuplicates("abcd", 2) == "abcd");
    return 0;
}