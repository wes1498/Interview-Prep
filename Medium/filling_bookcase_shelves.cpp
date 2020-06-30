#include <iostream>
#include <vector>

using namespace std;

int minHeightShelves(vector<vector<int>> &books, int shelf_width)
{
    int n = books.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = 1;
        int current_height = 0;
        int current_width = 0;

        while (k <= i)
        {
            // grab the max height of all books up to i
            current_height = max(current_height, books[i - k][1]);
            current_width += books[i - k][0];
            // if adding the current book exceeds the width, start a new row!
            if (current_width > shelf_width)
            {
                break;
            }

            // grab the samllest possible combination of book placements of books from k=0,..,i
            // that maximizes the width, and MINIMIZES the height
            dp[i] = min(dp[i], dp[i - k] + current_height);
            k++;
        }
    }
    return dp[n];
}

int main()
{
    //[[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]
    vector<vector<int>> books;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    books.push_back(temp);
    temp.clear();

    temp.push_back(2);
    temp.push_back(3);
    books.push_back(temp);
    books.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(1);
    books.push_back(temp);
    books.push_back(temp);
    books.push_back(temp);
    temp.clear();

    temp.push_back(1);
    temp.push_back(2);
    books.push_back(temp);

    if (minHeightShelves(books, 4) == 6)
    {
        printf("minimum height of 6! \n");
    }
    assert(minHeightShelves(books, 4));
    return 0;
}