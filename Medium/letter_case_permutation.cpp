#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<string>result;

void backtrack(int start, string& S) {
    for(int i=start; i<S.length(); i++) {
        if(isupper(S[i])){
            S[i] = tolower(S[i]);
            result.push_back(S);
            backtrack(i+1,S);
            S[i] = toupper(S[i]);
        }
        if(islower(S[i])) {
            S[i] = toupper(S[i]);
            result.push_back(S);
            backtrack(i+1,S);
            S[i] = tolower(S[i]);
        }
    }   
}
vector<string> letterCasePermutation(string S) {
    result.push_back(S);
    backtrack(0,S);
    return result;
}

int main() {
    vector<string> result{"a1b2",
"A1b2",
"A1B2",
"a1B2"};
    // for(auto a : letterCasePermutation("a1b2")) {
    //     cout<<a<<endl;
    // }
    assert(letterCasePermutation("a1b2") == result);
    return 0;
}