#include <iostream>
#include <vector>
#include <string>
#include <map>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

class Solution {
private:
    vector<string> result;
    map<char,string> table = {{'2',"abc"},
                                    {'3',"def"},
                                    {'4',"ghi"},
                                    {'5',"jkl"},
                                    {'6',"mno"},
                                    {'7',"pqrs"},
                                    {'8',"tuv"},
                                    {'9', "wxyz"}
                                   };
public:
    Solution() = default;
    void backtrack(string digits, string combo) {
        if(combo.size() == digits.size()){
            result.push_back(combo);}
        
        char letter_pos = digits[combo.size()];
        string letters = table[letter_pos];
        
        for(int i=0; i<letters.size(); i++) {
            backtrack(digits,combo+letters[i]);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){return result;}
        backtrack(digits, "");
        return result;
    }
};

int main() {
    Solution s;
    vector<string> result = {"ad","ae","af","bd","be","bf","cd",
    "ce","cf"};
    assert(s.letterCombinations("23") == result);
    return 0;
}