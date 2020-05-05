#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

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