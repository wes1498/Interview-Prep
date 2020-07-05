#include <iostream>
#include <cassert> 

using namespace std;

// Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
 

// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.
int minSteps(int n) {
    if(n == 1){return 0;}
    // for n>1 always have to copy first to have on in clip board
    // always paste once on page
    // given x A's on the page, you can do 1cpy + (i-1)pst
    int ans=0,i=2;
    while(n!=1) {
        if(n%i==0) {
            n/=i;
            ans+=i;
        } else
            i++;
    }
    return ans;
}

int main() {
    assert(minSteps(3)==3);
    assert(minSteps(6)==5);
    assert(minSteps(100)==14);
    return 0;
}
