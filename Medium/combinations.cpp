#include <iostream>
#include <vector>
#include <string>
#include <map>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> temp;
public:
    Solution() = default;
    void backtrack(int n, int k, int start) {
        if(temp.size() == k && find(result.begin(), result.end(), temp) == result.end()) {
            result.push_back(temp); return;
        }
        if(temp.size() > k) {return;}
        
        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            backtrack(n,k,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n,k,1);
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = {{2,4},{3,4},{2,3},{1,2},{1,3},{1,4}};
    assert(s.combine(4,2) == res);
    // for(auto i=0; i<tes.size(); i++){
    //     cout<< res[i][0] << res[i][1] << endl;
    // }
    return 0;
}