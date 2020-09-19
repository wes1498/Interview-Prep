#include <iostream>
#include <vector>
#include <set>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

int rotate(vector<int>& A, vector<int>& B, int target) {
    int count = 0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == B[i] && A[i] == target){continue;}
        if(A[i] == target){continue;}
        if(B[i] == target){count++;} else {return -1;}
    }
    return count;
}

int minDominoRotations(vector<int>& A, vector<int>& B) {
    std::set<int> a_set(A.begin(), A.end());
    std::set<int> b_set(B.begin(), B.end());
    
    int a_min=INT_MAX,b_min=INT_MAX,a_current,b_current;
    for(auto a : a_set) {
        if((a_current = rotate(A,B,a)) != -1){
            a_min = min(a_current,a_min);
        }
    }
    
    for(auto b : b_set) {
        if((b_current = rotate(B,A,b)) != -1){
            b_min = min(b_current,b_min);
        }
    }
    
    return a_min != INT_MAX || b_min != INT_MAX ? min(a_min,b_min) : -1;
}

int main() {
    vector<int> A = {2,1,2,4,2,2};
    vector<int> B = {5,2,6,2,3,2};
    assert(minDominoRotations(A,B) == 2);
    return 0;
}