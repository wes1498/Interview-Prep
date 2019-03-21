#include <iostream>
#include <string>

using namespace std;
/**
Chapter 1
Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE
Input: Tac t Coa
Output: Tru e (permutations : "tac o cat" , "atc o eta" , etc. )
**/

bool permutation(string s, string t) {
  if (s.size() != t.size()) {
    return false;
  }
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());

  for (int i=0; i<s.size(); i++){
    if (s[i] != t[i]) {
      return false;
    }
  }
  printf("t is a permutation of s\n");
  return true;
}

int main () {
  string s = "hello";
  string t = "olleh";
  bool isIt = permutation(s,t);

  return 0;
}
