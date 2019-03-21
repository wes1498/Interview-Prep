#include<iostream>
#include <string>

using namespace std;

/**
Chapter 1
description:

Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. (Note: If implementing in Java, please use a character array so that you can
perform this operation in place.)
EXAMPLE

      Input: "Mr 3ohn Smit h 13
      Output: "Mr%203ohn%20Smith"
**/
void urlify(string s, int n) {
  for (int i=0; i<n; i++) {
    if (s[i] == " ") {
      s[i].replace(1,0,"%20");
      // s[i] = "%20";
    }
  }
  cout << "this is " s << '\n';
}

int main() {
  string s = "Hi My Name Is Wesley";
  int n = (int)s.size();

  urlify(s,n);
  return 0;
}
