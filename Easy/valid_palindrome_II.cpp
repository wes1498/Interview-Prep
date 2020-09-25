#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end) {
        if(s[start] != s[end])
            return false ;
        start += 1;
        end -= 1;
    }
    return true;      
}

bool validPalindrome(string s) {
    int start = 0,diff = 0;
    int end = s.length() - 1;
    while(start <= end){
        if(s[start] != s[end]) {
            diff++;
            if(diff > 1){return false;}
            // check if you get a palindrom by removing either of the unmatched                         // characters (s[start] or s[end])
            bool removed_start = isPalindrome(s, start +1 , end);
            bool removed_end = isPalindrome(s, start, end-1);
            // if none are palindromes, return false
            if(!removed_start && !removed_end){return false;}
            // else, continue with either of them removed
            if(removed_start){start++;}
            else{end -= 1;}
        }
        start++ ;
        end-- ;
    }
    return true ;
}

int main() {
    assert(validPalindrome("abca") == true);
    return 0;
}