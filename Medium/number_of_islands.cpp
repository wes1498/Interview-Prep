#include <iostream>
#include <vector>
#include <stack>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

using namespace std;

void dfs(int i, int j, vector<vector<char>>& grid) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1'){return;}
    
    grid[i][j] = 'v';
    
    dfs(i + 1, j, grid);
    dfs(i - 1, j, grid);
    dfs(i, j + 1, grid);
    dfs(i, j - 1, grid);
}

int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()) return 0;
    int n = grid.size();
    int m = grid[0].size();
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '1') {
                res++;
                dfs(i, j, grid);
            }
        }
    }
    return res;
}

int main() {
    vector<vector<char>> grid;
    vector<char> temp{'1','1','0','0','0'};
    grid.push_back(temp);
    grid.push_back(temp);

    vector<char> temp1{'0','0','1','0','0'};
    grid.push_back(temp1);

    vector<char> temp2{'0','0','0','1','1'};
    grid.push_back(temp2);

    assert(numIslands(grid) == 3);

    return 0;
}