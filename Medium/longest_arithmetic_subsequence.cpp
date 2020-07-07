#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

// Given an array A of integers, return the length of the longest arithmetic subsequence in A.

// Recall that a subsequence of A is a list A[i_1], A[i_2], ..., A[i_k] with 0 <= i_1 < i_2 < ... < i_k <= A.length - 1, and that a sequence B is arithmetic if B[i+1] - B[i] are all the same value (for 0 <= i < B.length - 1).

// Example 1:

// Input: [3,6,9,12]
// Output: 4
// Explanation:
// The whole array is an arithmetic sequence with steps of length = 3.

int longestArithSeqLength(vector<int> &A)
{
    int n = A.size();
    if (n == 1)
    {
        return 1;
    }

    map<int, map<int, int>> dp;
    // base case: LAS = 2
    dp[1][A[1] - A[0]] = 2;
    int maxx = INT_MIN;

    for (int i = 2; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            dp[j][A[i] - A[j]] == 0 ? dp[i][A[i] - A[j]] = max(dp[i][A[i] - A[j]], 2) : dp[i][A[i] - A[j]] = max(dp[i][A[i] - A[j]], 1 + dp[j][A[i] - A[j]]);
            maxx = max(maxx, dp[i][A[i] - A[j]]);
        }
    }
    return maxx;
}

int main()
{
    vector<int> A;
    A.push_back(3);
    A.push_back(6);
    A.push_back(9);
    A.push_back(12);
    assert(longestArithSeqLength(A) == 4);
    return 0;
}