#include <iostream>
#include <cassert> 

using namespace std;

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
