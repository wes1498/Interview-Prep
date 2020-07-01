#include <iostream>
#include <vector>
#include <stack>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

int findCircleNum(vector<vector<int>>& M) {
    if(M.size() == 0) {return 0;}
    
    int n = M.size();
    int m = M[0].size();
    
    vector<vector<int>> adj_list;
    adj_list.resize(n);
    for(int i=0; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(M[i][j] == 1 && i != j) {
                adj_list[i].push_back(j);
            }
        }
    }
    int ans=0;
    vector<bool> visited(n,false);
    stack<int> s;
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            ans++;
            s.push(i);
            while(!s.empty()) {
                int v = s.top();s.pop();
                if(!visited[v]){visited[v]=true;}
                for(auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i) {
                    if(!visited[*i]){s.push(*i);}
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> M;
    vector<int> temp{1,1,0};
    M.push_back(temp);
    M.push_back(temp);
    vector<int> temp1{0,0,1};
    M.push_back(temp1);

    assert(findCircleNum(M) == 2);

    return 0;
}