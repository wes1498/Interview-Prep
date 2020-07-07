#include <iostream>
#include <cassert> 
#include <unordered_map>
#include <vector>

using namespace std;

// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

int lengthOfLongestSubstring(string s) {
    if(s.empty())return 0;
    
    unordered_map<char,int> table;
    int begin=0, end=0, max_len=0;
    
    while(end < s.length()) {
        char endChar = s[end];
        if(table.count(endChar) == 1 && table[endChar] >= begin) {
            // only move begin pointer if you've:
            //    1. endChar is already in the table
            //    2. Where you last saw endChar (stored inside table) position is after begin
            // then set begin to one AFTER the previously seen endChar
            begin = table[endChar]+1;
        } else {
            table[endChar] = end;
            end++;
        }
        
        if(end-begin > max_len) {
            max_len = end-begin;
        }
    }
    return max_len;
}

int main() {
    assert(lengthOfLongestSubstring("abcabcbb") == 3);

    return 0;
}