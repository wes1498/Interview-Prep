#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;


// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

// Example:

// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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