#include <iostream>
#include <vector>
#include <string>
#include <stack>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> temp;
    string palindrome = "";
public:
    Solution() = default;
    bool isPalindrome(string s) {
        stack<char> stack;
        for(auto c : s) {
            stack.push(c);
        }
        int i = 0;
        while(!stack.empty() || i != s.size()) {
            if(stack.top() != s[i]){return false;}
            i++;
            stack.pop();
        }
        return true;
    }
    void backtrack(string s) {
        if(s.size() == 0) {
            res.push_back(temp);return;}

        for(int i = 0; i < s.size(); i++) {
            if(isPalindrome(s.substr(0,i+1))){
                temp.push_back(s.substr(0,i+1));
                backtrack(s.substr(i+1));
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s);
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<string>> res = {{"aa","b"},{"a","a","b"}};
    assert(s.partition("aab") == res);
    return 0;
}