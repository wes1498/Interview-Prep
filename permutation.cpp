#include <iostream>
#include <string>

using namespace std;

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
