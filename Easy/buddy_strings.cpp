#include <iostream>
#include <vector>
#include <string>
#include <set>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

bool buddyStrings(string A, string B) {
    // Goal: To maintain a counter that is incremented each time a character
    //       in A doesnt match a character in B (if they're the same size!)
    // if counter > 2 : more than 2 swaps needed (return false)
    // if counter = 2 : check if swapping will match A = B (if not return false)
    //      1. A = "ab" B = "cd" return false
    //      1. A = "ab" B = "ba" return true
    // if counter = 1 : only one letter difference (return false)
    // if counter = 0 : can be one of 2 scenarios
    //      1. A = "aa" B = "aa" return true
    //      2. A = "ab" B = "ab" return false
    //      3. A = "abab" B = "abab" return true
    // both (1) and (3) return true because there exist "duplicated" chars that
    // can both be swapped and it's as if nothing changed
    if(A.size() != B.size()) {return false;}
    
    int counter = 0;
    vector<int> index;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] != B[i]){
            index.push_back(i);
            counter++;
        }
        if(counter > 2) {return false;}
    }
    if(counter == 1) {return false;}
    
    if(counter == 0) {
        set<char> _set;
        for(auto c : A) {_set.insert(c);}
        if(_set.size() < A.size()) {return true;}
        return false;
    }
    swap(A[index[0]],A[index[1]]);
    return A == B;
}

int main() {
    assert(buddyStrings("ab","ba") == true);
    assert(buddyStrings("aa","aa") == true);
    assert(buddyStrings("ab","ab") == false);
    assert(buddyStrings("ab","cd") == false);
    assert(buddyStrings("","aa") == false);
    assert(buddyStrings("abab","abab") == true);

    return 0;
}