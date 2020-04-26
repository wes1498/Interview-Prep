#include<iostream>
#include <string>
#include <unordered_map>


using namespace std;

// Chapter 1
// Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you
// cannot use additional data structures?

bool unique(string s) {
  unordered_map<char, int> mymap;
  for (int i=0; i<s.size(); i++) {
    mymap[s[i]]++;
  }
  for (int i=0; i<s.size(); i++) {
    if (mymap[s[i]] > 1) {
      printf("false!\n");
      return false;
    }
  }
  printf("this string is unique: True!\n");
  return true;
}

int main() {
  string s = "wesly";
  bool a = unique(s);
}
