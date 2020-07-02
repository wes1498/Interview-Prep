#include <iostream>
#include <vector>
#include <queue>
#include <functional>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    if(matrix.size() == 0) {return matrix;}
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    queue<pair<int,int>> bfs;
    // Keep track of the positions of 0's
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0){bfs.push(pair<int,int>(i,j));} 
            else{matrix[i][j] = INT_MAX;}
        }
    }
    
    vector<pair<int,int>> directions{pair<int,int>(0,1),pair<int,int>(1,0),pair<int,int>(0,-1),pair<int,int>(-1,0)};
    
    // for each 0 located and stored in your bfs queue
    while(!bfs.empty()) {
        pair<int,int> current = bfs.front(); bfs.pop();
        
        for(auto direction : directions) {
            int i = current.first + direction.first;
            int j = current.second + direction.second;
            
            // if the new position is out of bounds, or added direction exceeds the current distance
            // at matrix[i][j]
            if(i < 0||j < 0||i >= n||j >= m||matrix[i][j] <= matrix[current.first][current.second]+1)
            {continue;}
            
            bfs.push(pair<int,int>(i, j)); 
            // if valid direction added, then increment the matrix[i][j] cell by 1
            // one more move done
            matrix[i][j] = matrix[current.first][current.second] + 1;   
        }
    }
    return matrix;
}

int main() {
    // [[0,0,0],
    // [0,1,0],
    // [1,1,1]]
    // should return 
    //
    // [[0,0,0],
    // [0,1,0],
    // [1,2,1]]
    vector<vector<int>> matrix;
    vector<int> temp{0,0,0};
    vector<int> temp1{0,1,0};
    vector<int> temp2{1,1,1};
    matrix.push_back(temp);
    matrix.push_back(temp1);
    matrix.push_back(temp2);

    vector<vector<int>> result;
    vector<int> res{0,0,0};
    vector<int> res1{0,1,0};
    vector<int> res2{1,2,1};
    result.push_back(res);
    result.push_back(res1);
    result.push_back(res2);

    assert(updateMatrix(matrix) == result);

    return 0;
}