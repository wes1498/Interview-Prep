#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

class Solution {
private:
    unordered_map<int,int> char_count;
    map<string,int> substr_count;
public:
    Solution() = default;
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int result = 0;
        for(int i = 0; i < minSize; i++) {
            char_count[s[i]]++;
        }
        if(char_count.size() <= maxLetters) {
            substr_count[s.substr(0,minSize)]++;
            result = max(result,substr_count[s.substr(0,minSize)]);
        }
        for(int right = minSize; right < s.size(); right++) {
            char_count[s[right-minSize]]--;
            if(char_count[s[right-minSize]] == 0) {
                char_count.erase(s[right-minSize]);
            }
            char_count[s[right]]++;
            if(char_count.size() <= maxLetters) {
                substr_count[s.substr(right-minSize+1,minSize)]++;
                result = max(result,substr_count[s.substr(right-minSize+1,minSize)]);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    assert(s.maxFreq("aabcabcab",2,2,3) == 3);
    return 0;
}