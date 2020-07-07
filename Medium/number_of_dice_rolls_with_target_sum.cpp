#include <iostream>
#include <vector>

using namespace std;

// You have d dice, and each die has f faces numbered 1, 2, ..., f.

// Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

 

// Example 1:

// Input: d = 1, f = 6, target = 3
// Output: 1
// Explanation: 
// You throw one die with 6 faces.  There is only one way to get a sum of 3.

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