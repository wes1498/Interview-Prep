#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

class Solution {

private:
    vector<vector<int>> soln;
    vector<int> temp;
    vector<int> candidates{1,2,3,4,5,6,7,8,9};
public:
    Solution() = default;
    void backtrack(int k, int n, int start) {
        if(n == 0 && find(soln.begin(), soln.end(), temp) == soln.end() && temp.size() == k){
            soln.push_back(temp);
            return;
        }
        if(n < 0 || temp.size() > k){return;}

        for(int i=start; i<candidates.size(); i++) {
            temp.push_back(candidates[i]);
            backtrack(k,n-candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k,n,0);
        return soln;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = {{1,2,4}};
    assert(s.combinationSum3(3,7) == res);
    return 0;
}