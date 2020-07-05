#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

// A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

// For example, these are arithmetic sequences:

// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
// The following sequence is not arithmetic.

// 1, 1, 2, 5, 7
 
// A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

// A slice (P, Q) of the array A is called arithmetic if the sequence:
// A[P], A[P + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

// The function should return the number of arithmetic slices in the array A.
int numberOfArithmeticSlices(vector<int>& A) {
    int n=A.size();
    // Check if A is arithmetic
    if(n<3){return 0;}
    vector<int> dp(n,0);
    
    for(int i=2; i<n; i++) {
        int x = A[i-1]-A[i-2];
        int y = A[i]-A[i-1];
        if(x==y){
            dp[i]=dp[i-1]+1;
        }
    }
    int sum=0;
    for(int i=2; i<n; i++) {
        sum+=dp[i];
    }
    return sum;
}

int main(){
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);

    //return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
    assert(numberOfArithmeticSlices(A)==3);
    return 0;
}