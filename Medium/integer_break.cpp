#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j >= i / 2; j--)
        {
            dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
        }
    }
    return dp[n];
}

int main()
{
    assert(integerBreak(5) == 6);
    return 0;
}