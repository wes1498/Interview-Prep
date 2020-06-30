#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Builds a dp matrix from the top down since at each day, buying ticket j
 * will depend on the minimum cost of bbuying future tickets to complete all 
 * of the trip days
 * dp[i][j] is the cost of the trip from days i through n if you purchase the
 * ticket j on day i
 **/
int mincostTickets(vector<int> &days, vector<int> &cost)
{
    // 1. subproblems: suffixes of possible ways you can travel everyday days[i;] at cost
    //    #subproblems: O(days*cost)
    // 2. guess: for a given day i, should I buy a 1, 7, or 30 day pass?
    // consider a TOP-DOWN approach where your decision of which ticket to buy on day i
    // depends on the ticket you last bought on day i-1
    // 3. DP(i,j) = min(DP(i-1, 1), DP(i-1, 7), DP(i-1, 30))
    // 4. Tpological order: for(i=x...0)/
    // 5. Total Time: O(n)
    // 6. What are you solving for? DP[0][1] DP[0][2] DP[0][3]
    int n = days.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    vector<int> day_tracker(396, INT_MIN);

    // dayTracker:
    // index: 0 1 2 3 4 5 6 7 ...
    // value: 0 0 1 1 1 2 2 3 ...
    // ----------------------------
    //
    // from days 0-1, value is 0 (days[0]=1)
    // from days 2-4, value is 1 (days[1]=4)
    // from days 5-6, value is 2 (days[2]=6)
    // and so on ...
    //
    // the gap between 2 days they travel (eg. day 2 and day 5) is filled
    // with the index for the number of days they take up
    for (int i = 0; i < n; i++)
    {
        for (int j = days[i]; j >= 0 && day_tracker[j] == INT_MIN; j--)
        {
            if (day_tracker[j] == INT_MIN)
            {
                day_tracker[j] = i;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int index;
        index = day_tracker[days[i] + 1];
        if (index != INT_MIN)
        {
            dp[i][0] = cost[0] + min(dp[index][0], min(dp[index][1], dp[index][2]));
        }
        else
        {
            dp[i][0] = cost[0];
        }

        index = day_tracker[days[i] + 7];
        if (index != INT_MIN)
        {
            dp[i][1] = cost[1] + min(dp[index][0], min(dp[index][1], dp[index][2]));
        }
        else
        {
            dp[i][1] = cost[1];
        }

        index = day_tracker[days[i] + 30];
        if (index != INT_MIN)
        {
            dp[i][2] = cost[2] + min(dp[index][0], min(dp[index][1], dp[index][2]));
        }
        else
        {
            dp[i][2] = cost[2];
        }
    }
    return min(dp[0][0], min(dp[0][1], dp[0][2]));
}

int main()
{

    vector<int> days;
    days.push_back(1);
    days.push_back(4);
    days.push_back(6);
    days.push_back(7);
    days.push_back(8);
    days.push_back(20);

    vector<int> cost;
    cost.push_back(2);
    cost.push_back(7);
    cost.push_back(15);

    assert(mincostTickets(days, cost) == 11);
    return 0;
}