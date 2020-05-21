#include <iostream>
#include <vector>

using namespace std;

int numRollsToTarget(int d, int f, int target)
{
    vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            for (int k = 1; k <= f; k++)
            {
                if (j >= k)
                {
                    dp[i][j] = dp[i][j] % 1000000007 + dp[i - 1][j - k] % 1000000007;
                }
            }
        }
    }
    return dp[d][target] % 1000000007;
}

int main()
{
    assert(numRollsToTarget(2, 6, 7) == 6);
    return 0;
}