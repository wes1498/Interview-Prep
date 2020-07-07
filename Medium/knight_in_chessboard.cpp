#include <iostream>
#include <vector>

using namespace std;

//Fast IO
static auto magic = []() {std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return false;}();

// On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

// A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in a cardinal direction, then one square in an orthogonal direction.

// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly K moves or has moved off the chessboard. Return the probability that the knight remains on the board after it has stopped moving.

//dp[K][i][j] = probability of staying on the board after K moves starting from position i j
double dp[101][25][25];
// possible moves a knight can make (8)
int moves[8][2] = {{-2,-1}, {-2,1}, {2,-1}, {2,1}, {-1,-2}, {-1,2}, {1,-2}, {1,2}};

double get(int N, int K, int r, int c) {
    if (K == 0) return 1;
    if (dp[K][r][c] > -1) return dp[K][r][c];
    
    double prob = 0;
    for (auto move: moves) {
        int x = r + move[0], y = c + move[1];
        if (x >= 0 && x < N && y >= 0 && y < N)
            prob += get(N, K - 1, x, y) * static_cast<double>(1)/8;
    }
    return dp[K][r][c] = prob;
}
double knightProbability(int N, int K, int r, int c) {
    // initialize dp to size dp[101][25][25] and value -1
    memset(dp, -1, sizeof(dp[0][0][0]) * 101 * 25 * 25);
    return get(N, K, r, c);
}

int main(){
    assert(knightProbability(3,2,0,0)==0.0625);
    return 0;
}