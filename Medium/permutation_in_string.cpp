#include <iostream>
#include <cassert> 
#include <unordered_map>

using namespace std;

// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

// Example 1:

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False

bool checkInclusion(string s1, string s2) {
    if(s2.size() < s1.size()){return false;}
    
    // store a count for each char in string
    unordered_map<char, int> table;
    for(auto s : s1){
        table[s]++;
    }
    int begin=0,end=0,counter=table.size();
    
    while(end < s2.length()) {
        char endChar = s2[end];
        if(table.count(endChar) == 1) {
            table[endChar]--;
            if(table[endChar] == 0){counter--;}
        }
        end++;
        
        while(counter == 0) {
            if(end - begin == s1.length()) {
                return true;
            }
            
            char startChar = s2[begin];
            if(table.count(startChar) == 1) {
                table[startChar]++;
                if(table[startChar]>0){counter++;}
            }
            begin++;
        }
    }
    return false;   
}

int main() {
    assert(checkInclusion("ab","eidbaooo") == true);
    return 0;
}