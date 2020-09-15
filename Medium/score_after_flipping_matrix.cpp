#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

void toggle(vector<int>& a) {
    for(int &x : a){x = 1-x;}
}

int matrixScore(vector<vector<int>>& A) {
    int n = A.size();
    int m = A[0].size();
    int result=0;
    for(int i=0; i<n; i++) {
        if(A[i][0] == 0){toggle(A[i]);}
    }
    result += pow(2,m-1) * n;
    for(int j=1; j<m; j++) {
        int c0=0,c1=0;
        for(int i=0; i<n; i++) {
            if(A[i][j] == 1){c1++;}else{c0++;}
        }
        result += pow(2,m-1-j)*max(c0,c1);
    }
    return result;
}

int main() {
    vector<vector<int>> A{{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    assert(matrixScore(A) == 39);
    return 0;
}
