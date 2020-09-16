#include <iostream>
#include <vector>
#include <string>

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false; }();

using namespace std;

bool dfs(vector<vector<char>>& board, string word, int k,int i, int j) {
    if(i<0||i>=board.size()||j<0||j>=board[0].size()||word[k]!=board[i][j]){
        return false;
    }
    if(k == word.length()-1) return true;
    char curr = board[i][j];
    board[i][j] = 'V';
    
    bool search_check = dfs(board,word,k+1,i+1,j)
    ||dfs(board,word,k+1,i-1,j)||
    dfs(board,word,k+1,i,j+1)||
    dfs(board,word,k+1,i,j-1);
    
    board[i][j] = curr;
    
    return search_check;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(dfs(board,word,0,i,j)){return true;}
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    assert(exist(board,"ABCCED") == true);
    return 0;
}