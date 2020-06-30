#include <iostream>
#include <vector>
#include <stack>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

int findConnectedComponent(int n, vector<pair<int,int>> edges) {
    if(n == 0){return 0;}
    vector<vector<int>> adj_list;
    
    adj_list.resize(n);
    for(unsigned i = 0; i<edges.size(); i++) {
        int src = edges[i].first;
        int dst = edges[i].second;

        adj_list[src].push_back(dst);
	    adj_list[dst].push_back(src);
    }

    // bool* visited = new bool[n];
    // for(unsigned i = 0; i<n; i++) {
    //     visited[i] = false;
    // }
    // equivalent down below:
    vector<bool> visited(n, false);

    stack<int> s;
    int count=0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            s.push(i);
            count++;

            while(!s.empty()) {
                int v = s.top();
                s.pop();
                if(!visited[v]) {
                    visited[v] = true;
                }
                for(auto i = adj_list[v].begin(); i != adj_list[v].end(); ++i) {
                    if(!visited[*i]) {
                        s.push(*i);
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    vector<pair<int,int>> edges;
    edges.push_back(pair<int,int>(0,1));
    edges.push_back(pair<int,int>(1,2));
    edges.push_back(pair<int,int>(3,4));

    assert(findConnectedComponent(5, edges) == 2);
    
    return 0;
}