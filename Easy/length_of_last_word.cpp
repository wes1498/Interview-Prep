#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

int lengthOfLastWord(string s) {
    int i = s.size()-1, count = 0;
    for(;i >= 0; i--) {
        if(isalpha(s[i])){break;}
    }
    
    for(int j = i; j >= 0; j--) {
        if(isalpha(s[j])){count++;}
        else{break;}
    }
    
    return count;
}

int main() {
    assert(lengthOfLastWord("Hello World") == 5);
    return 0;
}