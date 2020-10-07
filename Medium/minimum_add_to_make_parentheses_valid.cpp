#include <iostream>
#include <string>
#include <stack>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

int minAddToMakeValid(string S) {
    stack<char>st;
    int count=0;
    for(char c : S) {
        if(c == '('){st.push(c);}
        else if (st.empty()){count++;}
        else{st.pop();}
    }
    if(st.size() > 0){return count + st.size();}
    return count;
}

int main() {
    assert(minAddToMakeValid("(((") == 3);
    return 0;
}