#include <iostream>
#include <unordered_map>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

int characterReplacement(string s, int k) {
    // pick the best place to change the character (k places)
    // "best" aims to maximize length of substring that contains all repeating letters
    if(s.empty()){return 0;}
    
    // table stores the number of 'seen' chars within window
    unordered_map<char, int> table;
    
    // count = The most occurred char so far
    int start=0,end=0,count=0;
    int max_len=INT_MIN;
    
    while(end < s.length()) {
        char endChar = s[end];
        table[endChar]++;
        end++;
        count = max(count, table[endChar]);
        
        // end - start = window size of repeated chars
        // end - start - count = number of non-repetitions that need operations to make repeated
        if(end - start - count > k) {
            char beginChar = s[start];
            table[beginChar]--;
            start++;
        }
        max_len = max(max_len, end - start);
    }
    
    return max_len;
}

int main() {
    assert(characterReplacement("ABAB", 2) == 4);
    
    return 0;
}