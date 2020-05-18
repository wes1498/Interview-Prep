#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

int numTreesUtil(int n){
    if(n==1){return 1;}
    if(n==2){return 2;}
    int result = 2*numTreesUtil(n-1);
    int reverse = n-2;
    for(int i=1; i<=n-2;i++,reverse--){
        result+=numTreesUtil(i)*numTreesUtil(reverse);
    }
    return result;
}

int numTrees(int n) {
    return numTreesUtil(n);
}

int main(){
    assert(numTrees(6)==132);
    return 0;
}