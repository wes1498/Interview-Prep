#include <iostream>
#include <vector>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

void dfs(int start, vector<vector<int>>& graph,vector<int>& temp, vector<vector<int>>& result, int destination) {
    if(start == destination) {
        temp.push_back(start);
        result.push_back(temp);
        temp.pop_back();
        return;
    }
    for(vector<int>::iterator it = graph[start].begin(); it != graph[start].end(); ++it) {
        temp.push_back(start);
        dfs(*it,graph,temp,result,destination);
        temp.pop_back();

    }
    return;
    
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> temp;
    int destination = graph.size() -1;
    dfs(0,graph,temp,result,destination);
    return result;
}

int main() {
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> result = {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}};
    assert(allPathsSourceTarget(graph) == result);
    return 0;
}